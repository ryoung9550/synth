#include "AudioStream.h"
#include <cmath>

#define PI 3.14159265
#define SINE_RATE .1

float* createSine() 
{
	static float lastVal = 0;
	float* sinBuffer = new float[AudioStream::BUFFER_SIZE];
	for(int i = 0; i < AudioStream::BUFFER_SIZE; ++i) {
		sinBuffer[i] = std::sin(lastVal);
		lastVal += SINE_RATE;
	}

	return sinBuffer;
}

int main()
{
	AudioStream stream;
	while(true) {
	}
}
