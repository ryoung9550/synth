#include <portaudio.h>
#include <cstdio>
#include <cstring>
#include "AudioStream.h"
#include "RingBuffer.h"


AudioStream::AudioStream()
{
	PaError err = 0;
	err = Pa_Initialize();
	if(err != paNoError) {
		fprintf(stderr, "PortAudio Error: %s\n", Pa_GetErrorText(err));
		return;
	}

	err = Pa_OpenDefaultStream(&stream, 0, 1, paFloat32, SAMPLE_RATE, BUFFER_SIZE, paCallback, &buffer);
	if(err != paNoError) {
		fprintf(stderr, "PortAudio Error: %s\n", Pa_GetErrorText(err));
		return;
	}

	Pa_StartStream(stream);
}

AudioStream::~AudioStream()
{
	PaError err = 0;

	Pa_StopStream(stream);

	err = Pa_CloseStream(stream);
	if(err != paNoError) {
		fprintf(stderr, "PortAudio Error: %s\n", Pa_GetErrorText(err));
	}

	err = Pa_Terminate();
	if(err != paNoError) {
		fprintf(stderr, "PortAudio Error: %s\n", Pa_GetErrorText(err));
	}
}



int AudioStream::paCallback(const void*, void *outputBuffer, unsigned long, const PaStreamCallbackTimeInfo*, PaStreamCallbackFlags, void* userData)
{
	RingBuffer<float, 10000>* ringBuffer = (RingBuffer<float, 10000>*) userData;
	float* out = (float*)outputBuffer;
	for(int i = 0; i < BUFFER_SIZE; ++i) {
		*out++ = ringBuffer->read();
	}
	return 0;
}


int AudioStream::sendAudio(float* audioStream, int size)
{
	for(int i = 0; i < size; ++i) {
		buffer.write(audioStream[i]);
	}
	delete audioStream;
	return 0;
}
