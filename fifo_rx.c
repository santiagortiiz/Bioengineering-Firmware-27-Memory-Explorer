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
#include "fifo_rx.h"

/*** VARIABLES ***/
fifo_rx_flags FIFO_rx;
char FIFO[FIFO_size];
char *put_FIFO_pointer = &FIFO[0];
char *get_FIFO_pointer = &FIFO[0];

/*** FUNCTIONS ***/
uint8 FIFO_put_data(char data){
    if (FIFO_rx.full){                              // If the FIFO_full_flag is on,  
        return False;                               // the data can't be put in the FIFO
    }
    else{                                           // Otherwise the data will be put in the FIFO 
        *put_FIFO_pointer = data;                   // and the pointer position will be the next
        put_FIFO_pointer++;                         // Note: This is the same that *(put_FIFO_pointer++)
        if (put_FIFO_pointer == &FIFO[FIFO_size]){  // When the pointer point to the null char
            put_FIFO_pointer = &FIFO[0];
            FIFO_rx.data_ready = 1;                 // This means that the fifo has 8 Bytes saved
        }
        return True;
    }
}

// Not in use for this Application
uint8 FIFO_get_data(char *consumer){
    if (FIFO_rx.empty){
        return False;    
    }
    else{                                           // The value of the get_FIFO_pointer is assign to 
        *consumer = *get_FIFO_pointer;              // the consumer variable.
        get_FIFO_pointer++;                         // Note: This is the same that *(get_FIFO_pointer++)
        if (get_FIFO_pointer == &FIFO[FIFO_size]){  // When the pointer point to the null char
            get_FIFO_pointer = &FIFO[0];
        }
        return True;
    }
}

/*
// If FIFO is EMPTY
if (put_FIFO_pointer == get_FIFO_pointer){ 
    FIFO_rx.empty = 1;
    // HABILITAR UART_TX_INT_ENABLE();
}
// If FIFO is FULL
if ((put_FIFO_pointer + 1 == get_FIFO_pointer) or (put_FIFO_pointer - get_FIFO_pointer == FIFO_size - 1)){
    FIFO_rx.full = 1;
}
*/

/*** INTERRUPTS ***/

/* [] END OF FILE */
