/*
 * misc.h
 *
 *  Created on: Sep 1, 2016
 *      Author: akudlacek
 */

#ifndef MISC_H_
#define MISC_H_

#include <stdint.h>


/******************************************************************************
* Macro Defines
******************************************************************************/
#define CONSTRAIN(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt))) //keeps within high and low range


/******************************************************************************
 * Global Prototypes
 ******************************************************************************/
long map(long x, long in_min, long in_max, long out_min, long out_max);
long my_fround(float number);
float interpolation(float x, const float array[][2], uint8_t size_of_array);
int rand_range(int min, int max);
double non_uniform_rand(double x, double min, double max, double exponent);

#endif /* MISC_H_ */
