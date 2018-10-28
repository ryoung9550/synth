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

float* PitchGen::getSin(const Pitch& pitch, double octave)
{
	switch(pitch) {
	case C: return getSin(262.0f * std::pow(2, octave));
	case Cs: return getSin(277.0f * std::pow(2, octave));
	case D: return getSin(294.0f * std::pow(2, octave));
	case Ds: return getSin(311.0f * std::pow(2, octave));
	case E: return getSin(330.0f * std::pow(2, octave));
	case F: return getSin(349.0f * std::pow(2, octave));
	case Fs: return getSin(370.0f * std::pow(2, octave));
	case G: return getSin(392.0f * std::pow(2, octave));
	case Gs: return getSin(415.0f * std::pow(2, octave));
	case A: return getSin(440.0f * std::pow(2, octave));
	case As: return getSin(466.0f * std::pow(2, octave));
	case B: return getSin(494.0f * std::pow(2, octave));
	}
}

float* PitchGen::getSin(double frequency)
{
	static double lastVal = 0;
	double increment = 1.0 / SAMPLE_RATE;
	for(size_t i = 0; i < ret_arr_len; ++i) {
		buffer[i] = std::sin(2.0 * PI * lastVal * (float) frequency);
		lastVal += increment;
	}
	return buffer;
}

size_t& PitchGen::getArrLen()
{
	return ret_arr_len;
}

#undef PI
