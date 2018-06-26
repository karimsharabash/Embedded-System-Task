/*
 * Switchs.c
 *
 *  Created on: 24/6/2018
 *      Author: Karim sharabash
 */

#include "Switchs.h"

void Switch_Init(void)
{
	/*
	 * enable the hardware(external) interrupt , INT 1
	 * ,and trigger the interrupt for the rising edge input for this pin (PORTD pin 3 )
	 */
   EXT_interrupt_Config(rising_edge_mode,1);
}



void Switch_callback_fun(void (*fun_ptr)(void))
{
	/*
	 * to preserve the modularity of the design i used a global pointer to function to pass
	 * the function i want to be done when the switch is pressed , to the hardware interrupt ISR
	 * through this function .
	 * EXT_INT_FUN_PTR
	 */

	 EXT_INT_FUN_PTR=fun_ptr;
}
