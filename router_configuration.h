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

#ifndef ROUTER_CONFIGURATION_H
    #define ROUTER_CONFIGURATION_H
    
    #include "project.h"

    /*** MACROS ***/
    #define button_pressed_flag_on route.adj_multiplier == 1
    #define button_pressed_flag_off route.adj_multiplier = 0
    
    #define and &&
    #define add_to_memory_pointer configure.operation == 0
    #define subtract_to_memory_pointer configure.operation == 1
    #define address_size 11
    #define content_size 9
    #define Multiplier route.multiplier
    
    #define flash_location route.address_location == 0
    #define low_ram_location route.address_location == 1
    #define high_ram_location route.address_location == 2
    #define sram_location route.address_location == 3
    #define phripherals_location route.address_location == 4
    #define external_ram_location route.address_location == 5
    #define external_device_location route.address_location == 6
    #define system_region_location route.address_location == 7
    
    /*** GLOBAL VARIABLE PROTOTYPES ***/
    typedef struct Router {
        uint16 multiplier:16;
        uint8 adj_multiplier:1;
        uint8 address_location:3;
    } router_configuration;
    
    extern router_configuration route;
    extern char address_buffer[address_size];
    extern char content_buffer[content_size];
    extern uint32 *memory_pointer;
    
    /*** FUNCTION PROTOTYPES ***/
    void set_multiplier(void);
    void set_address(void);
    void set_address_location(void);
    
    /*** INTERRUPTION PROTOTYPES ***/
    CY_ISR_PROTO(adj_multiplier); 
    
#endif

/* [] END OF FILE */
