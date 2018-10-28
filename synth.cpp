#include "AudioStream.h"
#include "PitchGen.h"
#include <cmath>
#include <iostream>

#define PI 3.14159265
#define SINE_RATE .1

const int ARR_LEN = 50;
float* createSine(float* sinBuffer) 
{
	static double lastVal = 0;
	for(int i = 0; i < ARR_LEN; ++i) {
		sinBuffer[i] = std::sin(lastVal);
		//std::cout << sinBuffer[i] << '\n';
		lastVal += SINE_RATE;
	}

	return sinBuffer;
}

int main()
{
	AudioStream stream;
	float buffer[ARR_LEN] {0};
	PitchGen pitchGen(1000);
	while(true) {
		stream.sendAudio(pitchGen.getSin(Pitch::A), pitchGen.getArrLen());
	}
}
