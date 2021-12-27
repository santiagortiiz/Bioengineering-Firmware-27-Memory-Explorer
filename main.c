/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#define or ||
#define and &&

#include "project.h"
#include "model_configuration.h"
#include "router_configuration.h"
#include "menu.h"
#include "comunication.h"
#include "fifo_rx.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_encoder_StartEx(set_encoding);
    isr_operation_StartEx(set_operation);
    isr_router_StartEx(adj_multiplier);
    isr_Rx_StartEx(UART_RX);
    //isr_Tx_StartEx(UART_TX);
    
    /*** COMPONENTS INITIALIZATION ***/
    LCD_Start();
    UART_Start();
    
    menu(0);
    FIFO_rx.full = 0;
    FIFO_rx.empty = 0;
    FIFO_rx.data_ready = 0;
    
    for(;;)
    {
        // Routine for Buttons Comunication
        if (button_pressed_flag_on){                        // Comunication routine is activated 
            button_pressed_flag_off;                        // when any button is pressed
            
            set_multiplier();
            set_address();
            set_address_location();
            menu(1);
            send_data();
        }
        
        if (update_model_flag_on){                          // When a SW is used, the model change
            update_model_flag_off;                          // and the LCD screen is updated
            menu(1);
        }
        
        // Routine for Serial Comunication
        if (address_received_flag_on){
            address_received_flag_off;
            
            decode_address();
            set_address_location();
            menu(1);
            send_data();
        }
        
        
    }
}

/* [] END OF FILE */
