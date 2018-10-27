#include <portaudio.h>
#include <cstdio>
#include <cstring>
#include "AudioStream.h"

AudioStream::AudioStream()
{
	PaError err = 0;
	err = Pa_Initialize();
	if(err != paNoError) {
		fprintf(stderr, "PortAudio Error: %s\n", Pa_GetErrorText(err));
		return;
	}

	err = Pa_OpenDefaultStream(&stream, 0, 2, paFloat32, SAMPLE_RATE, BUFFER_SIZE, paCallback, this);
	if(err != paNoError) {
		fprintf(stderr, "PortAudio Error: %s\n", Pa_GetErrorText(err));
		return;
	}

	Pa_StartStream(stream);

	startSuccess = true;
	running = true;
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

int AudioStream::nextSample()
{
	delete bufferQueue.front();
	bufferQueue.pop_front();

	return 0;
}

bool AudioStream::emptyBuffer() 
{
	return bufferQueue.empty();
}

int AudioStream::paCallback(const void*, void *outputBuffer, unsigned long, const PaStreamCallbackTimeInfo*, PaStreamCallbackFlags, void* userData)
{
	AudioStream* thisAlt = (AudioStream*) userData;
	if(thisAlt->emptyBuffer()) {
		std::memcpy(outputBuffer, BLANK_AUDIO, BUFFER_SIZE);
	} else {
		thisAlt->running = false;
	}
	std::memcpy(outputBuffer, userData, BUFFER_SIZE);
	return 0;
}

int AudioStream::sendAudio(float* audioStream, int size)
{
	if(bufferQueueArrOffest == 0) {
		for(int i = 0; i < (size / BUFFER_SIZE) + 1; ++i) {
			float* newBuffer = new float[BUFFER_SIZE];
			std::memcpy(newBuffer, audioStream + (i * BUFFER_SIZE), BUFFER_SIZE);
			bufferQueue.push_back(newBuffer);
		}
	} else {
		for(int i = 0; i < (size / BUFFER_SIZE) + 1; ++i) {
			float* offset_ptr = bufferQueue.back() + bufferQueueArrOffest;
			std::memcpy(offset_ptr, audioStream + (i * BUFFER_SIZE), bufferQueueArrOffest);
			float* newBuffer = new float[BUFFER_SIZE];
			offset_ptr = audioStream + (i * BUFFER_SIZE) + BUFFER_SIZE - bufferQueueArrOffest;
			std::memcpy(newBuffer, offset_ptr, BUFFER_SIZE - bufferQueueArrOffest);
			bufferQueue.push_back(newBuffer);
		}
	}
	running = true;
	return 0;
}

int AudioStream::sendAudio(float* audioStream)
{
	if(bufferQueueArrOffest == 0) {
		float* newBuffer = new float[BUFFER_SIZE];
		std::memcpy(newBuffer, audioStream, BUFFER_SIZE);
		bufferQueue.push_back(newBuffer);
	} else {
		float* offset_ptr = bufferQueue.back() + bufferQueueArrOffest;
		std::memcpy(offset_ptr, audioStream, bufferQueueArrOffest);
		float* newBuffer = new float[BUFFER_SIZE];
		offset_ptr = audioStream + BUFFER_SIZE - bufferQueueArrOffest;
		std::memcpy(newBuffer, offset_ptr, BUFFER_SIZE - bufferQueueArrOffest);
		bufferQueue.push_back(newBuffer);
	}
	return 0;
}
