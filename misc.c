/*
 * misc.c
 *
 *  Created on: Sep 1, 2016
 *      Author: akudlacek
 */

#include "misc.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


/**************************************************************************************************
*                                            FUNCTIONS
*************************************************^************************************************/
/******************************************************************************
 * Re-maps a number from one range to another
 * map(x, in_min, in_max, out_min, out_max)
 ******************************************************************************/
long map_l(long in, long in_min, long in_max, long out_min, long out_max)
{
	long return_val;
	
	return_val = (in - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
	
	//cap to max or min
	return_val = CONSTRAIN(return_val, out_min, out_max);
	
	return return_val;
}

/******************************************************************************
 * Re-maps a number from one range to another
 * map(x, in_min, in_max, out_min, out_max)
 ******************************************************************************/
float map_f(float in, float in_min, float in_max, float out_min, float out_max)
{
	float return_val;
	
	return_val = (in - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
	
	//cap to max or min
	return_val = CONSTRAIN(return_val, out_min, out_max);
	
	return return_val;
}

/******************************************************************************
 * my float round
 * converts a float to long
 ******************************************************************************/
long my_fround(float number)
{
	float diff = (number - floorf(number));
	
	if(diff >= 0.5)
	{
		return (long)ceilf(number);
	}
	else
	{
		return (long)floorf(number);
	}
}

/******************************************************************************
 * interpolation 2D for [n]x[2] array
 * x values must be in ascending order
 ******************************************************************************/
float interpolation(float x, const float array[][2], uint8_t size_of_array)
{
	float x0 = 0, y0 = 0, x1 = 0, y1 = 0;
	uint8_t index = 0;

	//if input less than or equal to x0
	if(x <= array[0][0])
		return array[0][1]; //return y
	//if x greater than or equal to x(n-1)
	else if(x >= array[size_of_array - 1][0])
		return array[size_of_array - 1][1]; //return y

	for(index = 0; index < size_of_array; index++)
	{
		if(array[index][0] == x)
		{
			return array[index][1]; //return y
		}
		else if(array[index][0] > x)
		{
			x0 = array[index - 1][0];
			x1 = array[index][0];
			y0 = array[index - 1][1];
			y1 = array[index][1];
			break;
		}
	}

	return (y0 + (y1 - y0) * ((x - x0) / (x1 - x0)));
}

/******************************************************************************
* Generates random number within a range
******************************************************************************/
int rand_range(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

/******************************************************************************
* Generates Non-uniform distributed random numbers using power-law X^n
* this takes in random numnber from 0-1, can use drand48()
* https://www.twam.info/software/non-uniform-distributed-random-numbers
******************************************************************************/
double non_uniform_rand(double x, double min, double max, double exponent)
{
	if(exponent == -1)
	{
		return exp(log(max-min)*x)*min;
	}
	else
	{
		return exp(log(x*(-pow(min,exponent+1)+pow(max,exponent+1))+pow(min,exponent+1))/(exponent+1));
	}
}
