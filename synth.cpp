#include "AudioStream.h"
#include <cmath>
#include <iostream>

#define PI 3.14159265
#define SINE_RATE .1

const int ARR_LEN = 50000;
float* createSine() 
{
	static double lastVal = 0;
	float* sinBuffer = new float[ARR_LEN];
	for(int i = 0; i < ARR_LEN; ++i) {
		sinBuffer[i] = std::sin(lastVal);
		std::cout << sinBuffer[i] << '\n';
		lastVal += SINE_RATE;
	}

	return sinBuffer;
}

int main()
{
	AudioStream stream;
	while(true) {
		stream.sendAudio(createSine(), ARR_LEN);
	}
}
