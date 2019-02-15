/*
 * misc.h
 *
 *  Created on: Sep 1, 2016
 *      Author: akudlacek
 */

#ifndef MISC_H_
#define MISC_H_

#include <stdint.h>


/**************************************************************************************************
*                                             DEFINES
*************************************************^************************************************/
#define CONSTRAIN(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt))) //keeps within high and low range


/**************************************************************************************************
*                                            PROTOTYPES
*************************************************^************************************************/
long map_l(long in, long in_min, long in_max, long out_min, long out_max);
float map_f(float in, float in_min, float in_max, float out_min, float out_max);
long my_fround(float number);
float interpolation(float x, const float array[][2], uint8_t size_of_array);
int rand_range(int min, int max);
double non_uniform_rand(double x, double min, double max, double exponent);
float approx_low_pass_f(float filtered_result, float input, float filter_value);
float max_rng_chk_w_sep(float input_max, float cur_min, float min_lim, float max_lim, float min_sep);
float min_rng_chk_w_sep(float input_min, float cur_max, float min_lim, float max_lim, float min_sep);


#endif /* MISC_H_ */
