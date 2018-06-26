/*
 * EXT_Interrupt.c
 *
 *  Created on: 12/3/2018
 *      Author: karim sharabash
 */
#include "EXT_Interrupt.h"

void (*EXT_INT_FUN_PTR)(void);

/*
 * API to adjust the External Interrupt configuration
 * choose the mode and the the interrupt number (atmega32 has 3 external interrupt INT0,INT1&INT2)
 *  */
void EXT_interrupt_Config(uint8 mode,uint8 INT_number)
{
	switch (INT_number)
	{
	case 0:{  //for INT0
		GICR|=(1<<INT0);
		switch(mode)
		{
		case low_level_mode:{
			MCUCR&=~((1<<ISC00)|(1<<ISC01)); //clear the two bits to get this mode
		}break;
		case logical_change_mode:{
			MCUCR|=(1<<ISC00);
			MCUCR&=~(1<<ISC01);
		}break;
		case falling_edge_mode:{
			MCUCR&=~(1<<ISC00);
			MCUCR|=(1<<ISC01);
		}break;
		case rising_edge_mode:{
			MCUCR|=(1<<ISC00)|(1<<ISC01);
		}break;
		}
	}break;

	case 1:{ //for INT1
		GICR|=(1<<INT1);
		switch(mode)
		{
		case low_level_mode:{
			MCUCR&=~((1<<ISC10)|(1<<ISC11));
		}break;
		case logical_change_mode:{
			MCUCR|=(1<<ISC10);
			MCUCR&=~(1<<ISC11);
		}break;
		case falling_edge_mode:{
			MCUCR&=~(1<<ISC10);
			MCUCR|=(1<<ISC11);
		}break;
		case rising_edge_mode:{
			MCUCR|=(1<<ISC10)|(1<<ISC11);
		}break;
		}
	}break;
	case 2:{ //for INT2
		GICR|=(1<<INT2);
		switch(mode)
		{
		case falling_edge_mode:{
			MCUCSR&=~(1<<ISC2);
		}break;
		case rising_edge_mode:{
			MCUCSR|=(1<<ISC2);
		}break;
		}
	}break;
	}
}

ISR(INT1_vect)
{
	EXT_INT_FUN_PTR();  //call the function that passed by this pointer (which will be switch task)
}

