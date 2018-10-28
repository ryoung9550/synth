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
	PitchGen pitchGen(200);
	const int Repeat = 20;
	for(int i = 0; i < Repeat; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::F, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::F, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::G, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::G, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::D, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::D, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 6; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 2.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 6; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 2.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 6; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 2.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 2.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 2.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 6; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 6; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 2.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 20; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 2.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 6; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 2.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 6; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 2.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 6; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 2.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 6; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 2.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 6; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 17; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 2.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < 10000; ++i);
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 12; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::G, 3.0), pitchGen.getArrLen());
	}


	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::E, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::D, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 14; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::G, 3.0), pitchGen.getArrLen());
	}



	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 6; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::G, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::F, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::G, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::G, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 14; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 3.0), pitchGen.getArrLen());
	}


	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 6; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::G, 3.0), pitchGen.getArrLen());
	}



	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::E, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::D, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 14; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::G, 3.0), pitchGen.getArrLen());
	}

	

	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 4.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::B, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 6; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::G, 3.0), pitchGen.getArrLen());
	}



	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::F, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::G, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::A, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 4; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::G, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::C, 3.0), pitchGen.getArrLen());
	}
	for(int i = 0; i < Repeat * 2; ++i) {
		stream.sendAudio(pitchGen.getSin(Pitch::E, 3.0), pitchGen.getArrLen());
	}
}
