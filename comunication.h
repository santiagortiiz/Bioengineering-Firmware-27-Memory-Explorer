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

#ifndef COMUNICATION_H
    #define COMUNICATION_H
    
    #include "project.h"

    /*** MACROS ***/
    #define binary configure.encoding == 0
    #define hexadecimal configure.encoding == 1
    
    /*** GLOBAL VARIABLE PROTOTYPES ***/
    extern char data;
    extern uint32 address;              // Will be stored in 0x1FFF8184 - This will be usefull for the validation
    
    /*** FUNCTION PROTOTYPES ***/
    void decode_address(void);              
    void send_data(void);
    void send_binary_content(void);
    
    /*** INTERRUPTION PROTOTYPES ***/
    CY_ISR_PROTO(UART_RX);
    CY_ISR_PROTO(UART_TX);
    
#endif

/* [] END OF FILE */
