#ifndef _PITCH_GEN_H
#define _PITCH_GEN_H

#include <cstring>

#ifndef SAMPLE_RATE
#define SAMPLE_RATE 44100
#endif

enum Pitch
{
C,
Cs,
D,
Ds,
E,
F,
Fs,
G,
Gs,
A,
As,
B
};

class PitchGen
{
	size_t ret_arr_len;
	float* buffer;
	float* getSin(double frequency);
public:
	PitchGen(size_t arr_size);
	float* getSin(const Pitch& pitch, double octave);
	float* getSawtooth(const Pitch& pitch);
	size_t& getArrLen();
};

#endif // _PITCH_GEN_H
