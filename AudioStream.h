#ifndef _AUDIO_STREAM_H
#define _AUDIO_STREAM_H

#include <portaudio.h>
#include <deque>
#include "RingBuffer.h"
	

class AudioStream
{
public:
	const static int BUFFER_SIZE = 256;
private:
	// Member Functions
	static int paCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags,  void *userData);

	//Member Variables
	PaStream* stream;

public:
	// Member Functions
	AudioStream();
	~AudioStream();

	// Member Variables
	const static int SAMPLE_RATE = 44100;
	RingBuffer<float, 10000> buffer;
	int sendAudio(float* audioStream, int size);
	int stopAudio();
};

const static float BLANK_AUDIO[AudioStream::BUFFER_SIZE] {0};

#endif // _AUDIO_STREAM_H
