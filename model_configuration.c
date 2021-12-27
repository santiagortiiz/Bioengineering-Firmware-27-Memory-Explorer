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
#include "model_configuration.h"
#include "router_configuration.h"

/*** VARIABLES ***/
model_configuration configure;

/*** FUNCTIONS ***/


/*** INTERRUPTS ***/
CY_ISR(set_encoding){                                       // SW   -   encoding
    if (Encoder_SW_Read()) configure.encoding = 1;          // ON   -   Hexadecimal
    else configure.encoding = 0;                            // OFF  -   Binary
    configure.update_model = 1;
}

CY_ISR(set_operation){                                      // SW   -   operation 
    if (Operation_SW_Read()) configure.operation = 1;       // ON   -   Subtract
    else configure.operation = 0;                           // Off  -   Add
    configure.update_model = 1;
}

/* [] END OF FILE */
