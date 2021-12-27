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
#include "router_configuration.h"
#include "model_configuration.h"
#include "fifo_rx.h"

/*** VARIABLES ***/
router_configuration route;

char address_buffer[address_size] = {0};
char content_buffer[content_size] = {0};

uint32 *memory_pointer = (uint32 *) 0x00000000;

/*** FUNCTIONS ***/
void set_multiplier(void){                              // When any button is pressed, 
    if (CyPins_ReadPin(Router_0)){                      // a multiplier is set
        route.multiplier = 1;
    }
    
    else if (CyPins_ReadPin(Router_1)){
        route.multiplier = 32;
    }
    
    else if (CyPins_ReadPin(Router_2)){
        route.multiplier = 128;
    }
    
    else if (CyPins_ReadPin(Router_3)){
        route.multiplier = 255;
    }
}

// Function for the Method 1 based on Buttons
void set_address(void){
    if (subtract_to_memory_pointer){                    // operation SW - ON = Subtract
        memory_pointer = memory_pointer - route.multiplier;    
    }
    else if (add_to_memory_pointer){                    // operation SW - OFF = Add
        memory_pointer = memory_pointer + route.multiplier;
    }
    
    sprintf(address_buffer, "%p\n", memory_pointer);    // The address of memory_pointer is assign to address_buffer
}
/* 
    - How to do this function with more than 1 return: 
        "return (address_buffer, content_buffer)"
        a, b set_address(void) doesn´t work

    - Which is the difference between create a variable using "static variable"
      and one which is created inside a function of the specific file?

*/

void set_address_location(void){                        // Set the location of the accessed memory
    if ((uint32) memory_pointer <= 0x0003FFFF){         // depending of the memory_pointer address
        route.address_location = 0; // Flash
    }
    else if ((0x1fff8000 <= (uint32) memory_pointer) and ((uint32) memory_pointer <= 0x1fffffff)){
        route.address_location = 1; // LOW RAM
    }
    else if ((0x20000000 <= (uint32) memory_pointer) and ((uint32) memory_pointer <= 0x20007fff)){
        route.address_location = 2; // HIGH RAM
    }
    else if ((0x20008000 <= (uint32) memory_pointer) and ((uint32) memory_pointer <= 0x3fffffff)){
        route.address_location = 3; // SRAM
    }
    else if ((0x40000000 <= (uint32) memory_pointer) and ((uint32) memory_pointer <= 0x5fffffff)){
        route.address_location = 4; // Peripherals
    }
    else if ((0x60000000 <= (uint32) memory_pointer) and ((uint32) memory_pointer <= 0x9fffffff)){
        route.address_location = 5; // External Ram
    }
    else if ((0xa0000000 <= (uint32) memory_pointer) and ((uint32) memory_pointer <= 0xdfffffff)){
        route.address_location = 6; // External Device
    }
    else if ((0xe0000000 <= (uint32) memory_pointer) and ((uint32) memory_pointer <= 0xfffffff)){
        route.address_location = 7; // System Region (Invalid)
    }
}

/*** INTERRUPTS ***/
CY_ISR(adj_multiplier){
    route.adj_multiplier = 1;
}

/* [] END OF FILE */
