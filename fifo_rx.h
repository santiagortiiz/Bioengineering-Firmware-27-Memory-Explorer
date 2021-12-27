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

#ifndef FIFO_RX_H
    #define FIFO_RX_H
    
    #include "project.h"

    /*** MACROS ***/
    #define FIFO_size 8
    #define True 1
    #define False 0
    
    #define address_received_flag_on FIFO_rx.data_ready == 1
    #define address_received_flag_off FIFO_rx.data_ready = 0
    
    /*** GLOBAL VARIABLE PROTOTYPES ***/
    typedef struct fifo_rx_flags {
        uint8 empty:1;
        uint8 full:1;
        uint8 data_ready:1;
    } fifo_rx_flags;
    
    extern fifo_rx_flags FIFO_rx;
    extern char FIFO[FIFO_size];
    extern char *put_FIFO_pointer;
    extern char *get_FIFO_pointer;
    
    /*** FUNCTION PROTOTYPES ***/
    uint8 FIFO_put_data(char data);
    uint8 FIFO_get_data(char *consume);
    
    /*** INTERRUPTION PROTOTYPES ***/
    
#endif

/* [] END OF FILE */
