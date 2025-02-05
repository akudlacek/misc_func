/*
 * misc.h
 *
 *  Created on: Sep 1, 2016
 *      Author: akudlacek
 */

#ifndef MISC_H_
#define MISC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>


/**************************************************************************************************
*                                             DEFINES
*************************************************^************************************************/
#define CONSTRAIN(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt))) //keeps within high and low range
#define MAP(in, in_min, in_max, out_min, out_max) (((in) - (in_min)) * ((out_max) - (out_min)) / ((in_max) - (in_min)) + (out_min)) //maps from one range to another
#define MAPC(in, in_min, in_max, out_min, out_max) (CONSTRAIN(MAP(in, in_min, in_max, out_min, out_max), out_min, out_max)) //constrained map


/**************************************************************************************************
*                                            PROTOTYPES
*************************************************^************************************************/
long   map_l            (const long  in, const long  in_min, const long  in_max, const long  out_min, const long  out_max);
float  map_f            (const float in, const float in_min, const float in_max, const float out_min, const float out_max);
long   my_fround        (const float number);
float  interpolation    (const float x, const float array[][2], const uint8_t size_of_array);
int    rand_range       (const int min, const int max);
float  rand_range_f    (const float min, const float max);
double non_uniform_rand (const double x, const double min, const double max, const double exponent);
float  approx_low_pass_f(float filtered_result, const float input, const float filter_value);
float  max_rng_chk_w_sep(const float input_max, const float cur_min, const float min_lim, const float max_lim, const float min_sep);
float  min_rng_chk_w_sep(const float input_min, const float cur_max, const float min_lim, const float max_lim, const float min_sep);

#ifdef __cplusplus
}
#endif

#endif /* MISC_H_ */
