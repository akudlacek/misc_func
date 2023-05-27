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
long map_l(const long in, const long in_min, const long in_max, const long out_min, const long out_max)
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
float map_f(const float in, const float in_min, const float in_max, const float out_min, const float out_max)
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
long my_fround(const float number)
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
float interpolation(const float x, const float array[][2], const uint8_t size_of_array)
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
int rand_range(const int min, const int max)
{
	return rand() % (max - min + 1) + min;
}

/******************************************************************************
* Generates Non-uniform distributed random numbers using power-law X^n
* this takes in random numnber from 0-1, can use drand48()
* https://www.twam.info/software/non-uniform-distributed-random-numbers
******************************************************************************/
double non_uniform_rand(const double x, const double min, const double max, const double exponent)
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

/******************************************************************************
* Approximate rolling average
* https://stackoverflow.com/a/16757630
* 
* filtered_result - remembered/output result
* input           - 
* filter_value    - number of samples to average, sort of
******************************************************************************/
float approx_low_pass_f(float filtered_result, const float input, const float filter_value)
{

	filtered_result -= filtered_result / filter_value;
	filtered_result += input / filter_value;

	return filtered_result;
}

/******************************************************************************
*  \brief Max range check w/ min separation
*
*  \note
******************************************************************************/
float max_rng_chk_w_sep(const float input_max, const float cur_min, const float min_lim, const float max_lim, const float min_sep)
{
	float output_max;
	
	output_max = input_max;
	
	/*Range checks*/
	//check lower limit
	if(output_max < (min_lim + min_sep))
	output_max = min_lim + min_sep;
	
	//check upper limit
	if(output_max > max_lim)
	output_max = max_lim;
	
	//check separation
	if((output_max - cur_min) < min_sep)
	output_max = cur_min + min_sep;
	
	return output_max;
}

/******************************************************************************
*  \brief Min range check w/ min separation
*
*  \note
******************************************************************************/
float min_rng_chk_w_sep(const float input_min, const float cur_max, const float min_lim, const float max_lim, const float min_sep)
{
	float output_min;
	
	output_min = input_min;
	
	/*Range checks*/
	//check lower limit
	if(output_min < min_lim)
	output_min = min_lim;
	
	//check upper limit
	if(output_min > (max_lim - min_sep))
	output_min = max_lim - min_sep;
	
	//check separation
	if((cur_max - output_min) < min_sep)
	output_min = cur_max - min_sep;
	
	return output_min;
}
