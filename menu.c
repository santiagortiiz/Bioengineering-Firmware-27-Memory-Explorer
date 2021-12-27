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
#include "menu.h"
#include "router_configuration.h"
#include "model_configuration.h"

/*** VARIABLES ***/

/*** FUNCTIONS ***/
void menu(uint8 menu_index){
    switch(menu_index){
        case 0:
            LCD_ClearDisplay();
            LCD_Position(0,2);
            LCD_PrintString("Memory Explorer");
            LCD_Position(1,0);
            LCD_PrintString("Numeric System - SW1");
            LCD_Position(2,0);
            LCD_PrintString("Move Up/Down - SW2");
            LCD_Position(3,0);
            LCD_PrintString("Address-4PushButtons");
            
            break;
        case 1:
            LCD_ClearDisplay();
            LCD_Position(0,0);
            LCD_PrintString("NS:");
            if (configure.encoding) LCD_PrintString("Hexadecimal");
            else LCD_PrintString("Binary");
            
            LCD_Position(1,0);
            LCD_PrintString("Move:");
            if (configure.operation) LCD_PrintString("Down");
            else LCD_PrintString("Up");
            
            LCD_Position(2,0);
            LCD_PrintString("Multiplier: ");
            LCD_PrintNumber(Multiplier);
            
            LCD_Position(3,0);
            LCD_PrintString("Memory: ");
            if (flash_location) LCD_PrintString("Flash");
            else if (low_ram_location) LCD_PrintString("Low RAM");
            else if (high_ram_location) LCD_PrintString("High RAM");
            else if (sram_location) LCD_PrintString("SRAM");
            else if (phripherals_location) LCD_PrintString("Pheripherals");
            else if (external_ram_location) LCD_PrintString("External RAM");
            else if (external_device_location) LCD_PrintString("Ext. Device");
            else if (system_region_location) LCD_PrintString("System Region");
            
            break;
    }
}

/*** INTERRUPTS ***/

/* [] END OF FILE */
