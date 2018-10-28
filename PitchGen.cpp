#include "PitchGen.h"
#include <cmath>

#ifndef PI
#define PI 3.14159265
#endif

PitchGen::PitchGen(size_t arr_size) : ret_arr_len(arr_size) 
{
	buffer = new float[ret_arr_len];
	memset(buffer, 0, sizeof(float) * ret_arr_len);
}

float* PitchGen::getSin(const Pitch& pitch)
{
	switch(pitch) {
	case C: return getSin(262);
	case Cs: return getSin(277);
	case D: return getSin(294);
	case Ds: return getSin(311);
	case E: return getSin(330);
	case F: return getSin(349);
	case Fs: return getSin(370);
	case G: return getSin(392);
	case Gs: return getSin(415);
	case A: return getSin(440);
	case As: return getSin(466);
	case B: return getSin(494);
	}
}

float* PitchGen::getSin(size_t frequency)
{
	static double lastVal = 0;
	double increment = 2.0 * PI / frequency;
	for(size_t i = 0; i < ret_arr_len; ++i) {
		buffer[i] = std::sin(lastVal);
		lastVal += increment;
	}
	return buffer;
}

size_t& PitchGen::getArrLen()
{
	return ret_arr_len;
}

#undef PI
