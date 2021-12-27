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

#ifndef MODEL_CONFIGURATION_H
    #define MODEL_CONFIGURATION_H
    
    #include "project.h"

    /*** MACROS ***/
    #define update_model_flag_on configure.update_model == 1
    #define update_model_flag_off configure.update_model = 0
    
    /*** GLOBAL VARIABLE PROTOTYPES ***/
    typedef struct Model_Configuration{             
        uint8 update_model:1;                       // Struct of the Model
        uint8 encoding:1;                           // It determine if the system display binary or
        uint8 operation:1;                          // hexadecimal numbers, and if the system add
    } model_configuration;                          // or subtract the multiplier to the address
    
    extern model_configuration configure;
    
    /*** FUNCTION PROTOTYPES ***/
    
    /*** INTERRUPTION PROTOTYPES ***/
    CY_ISR_PROTO(set_encoding);  
    CY_ISR_PROTO(set_operation);  
    
#endif

/* [] END OF FILE */
