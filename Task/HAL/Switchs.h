/*
 * Switchs.h
 *
 *  Created on: 24/6/2018
 *      Author: Karim sharabash
 */


#ifndef SWITCHS_H_
#define SWITCHS_H_
#include "../MCAL/DIO.h"
#include "../MCAL/EXT_Interrupt.h"
#include "../Service/data_types.h"


void Switch_Init(void);
void Switch_callback_fun(void (*fun_ptr)(void));



#endif /* SWITCHS_H_ */
