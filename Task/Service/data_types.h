/*
 * data_types.h
 *
 *  Created on: 24/6/2018
 *      Author: Karim Sharabash
 *
 *  the purpose of this file is to declare new obvious names for the standard data types
 *  which indicate three things each data types is float or int(singed or unsigned ) , and the size which will be reserved for it in the memory
 */

#ifndef SERVICE_DATA_TYPES_H_
#define SERVICE_DATA_TYPES_H_

typedef long long unsigned int uint64;
typedef long long signed int sint64;
typedef unsigned int uint32;
typedef signed int sint32;
typedef short unsigned int uint16;
typedef short signed int sint16;
typedef unsigned char uint8;
typedef signed char sint8;
typedef float f32;
typedef double f64;
typedef long double f96;

#endif /* SERVICE_DATA_TYPES_H_ */
