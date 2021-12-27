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

/*** INCLUDED COMPONENTS ***/
#include <stdio.h>
#include <math.h>
#include "comunication.h"
#include "router_configuration.h"
#include "model_configuration.h"
#include "fifo_rx.h"

/*** VARIABLES ***/
char data = 0;
uint32 address = 0;

/*** FUNCTIONS ***/
void decode_address(void){                              // Function for the Method 2 based on Serial Comunication
    for (uint8 i = 0; i < FIFO_size; i++){              // Convert each character in the FIFO
        switch(FIFO[i]){                                // from Hexadecimal to Decimal
            case 'A':
                address_buffer[i] = 10;
                break;
            case 'B':
                address_buffer[i] = 11;
                break;
            case 'C':
                address_buffer[i] = 12;
                break;
            case 'D':
                address_buffer[i] = 13;
                break;
            case 'E':
                address_buffer[i] = 14;
                break;
            case 'F':
                address_buffer[i] = 15;
                break;
            default:
                address_buffer[i] = FIFO[i];
                break;
        }
    }
    
    address = (uint32)                                  // Set the direction of the memory_pointer
    (    
    address_buffer[0]*pow(16,7) + 
    address_buffer[1]*pow(16,6) + 
    address_buffer[2]*pow(16,5) + 
    address_buffer[3]*pow(16,4) + 
    address_buffer[4]*pow(16,3) + 
    address_buffer[5]*pow(16,2) + 
    address_buffer[6]*pow(16,1) + 
    address_buffer[7]*pow(16,0) 
    );
    
    memory_pointer = (uint32 *) address;                // Assign the address number to the memory_pointer
                                                        // The address of memory_pointer is assign to address_buffer
    sprintf(address_buffer, "%p\n", memory_pointer);    // Note: sprintf also add here '0x' and '\n'
}                                                       

void send_data(void){ 
    UART_PutString(address_buffer);                     // Send the address
    
    sprintf(content_buffer, "%lX", *memory_pointer);    // Store the content of the pointer in the buffer
    
    if (hexadecimal) {
        UART_PutString(content_buffer);                 // Send the content in hexadecimal
        UART_PutCRLF(' ');
    }
    else {                                              // Send the content in binary
        send_binary_content();
        UART_PutCRLF(' ');
    }
}

void send_binary_content(void){
    for (uint8 i = 0; i < content_size; i++){           // Convert each character in the content_buffer
        switch(content_buffer[i]){                      // from Hexadecimal to Binary
            case '0':
                UART_PutString("0000 ");
                break;
            case '1':
                UART_PutString("0001 ");
                break;
            case '2':
                UART_PutString("0010 ");
                break;
            case '3':
                UART_PutString("0011 ");
                break;
            case '4':
                UART_PutString("0100 ");
                break;
            case '5':
                UART_PutString("0101 ");
                break;
            case '6':
                UART_PutString("0110 ");
                break;
            case '7':
                UART_PutString("0111 ");
                break;
            case '8':
                UART_PutString("1000 ");
                break;
            case '9':
                UART_PutString("1001 ");
                break;
            case 'A':
                UART_PutString("1010 ");
                break;
            case 'B':
                UART_PutString("1011 ");
                break;
            case 'C':
                UART_PutString("1100 ");
                break;
            case 'D':
                UART_PutString("1101 ");
                break;
            case 'E':
                UART_PutString("1110 ");
                break;
            case 'F':
                UART_PutString("1111 ");
                break;
        }
    }
}

/*** INTERRUPTS ***/
CY_ISR(UART_RX){
    char read_data = UART_GetChar();                    // GetChar is Designed for read ASCII characters
    FIFO_put_data(read_data);                           // Each read value is set into the FIFO
}

// Not in use for this Application
CY_ISR(UART_TX){
    char recovered_data = 0;                            // The recovered_data will be replaced
    if (FIFO_get_data(&recovered_data)){                // by the FIFO's input value and then
        UART_PutChar(recovered_data);                   // send by serial comunication
    }
}
/* [] END OF FILE */
