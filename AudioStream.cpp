#include <portaudio.h>
#include <cstdio>
#include <cstring>
#include "AudioStream.h"

static int patestCallback( const void *inputBuffer, void *outputBuffer,
                           unsigned long framesPerBuffer,
                           const PaStreamCallbackTimeInfo* timeInfo,
                           PaStreamCallbackFlags statusFlags,
                           void *userData )
{
    /* Cast data passed through stream to our structure. */
    paTestData *data = (paTestData*)userData; 
    float *out = (float*)outputBuffer;
    unsigned int i;
    (void) inputBuffer; /* Prevent unused variable warning. */
    
    for( i=0; i<framesPerBuffer; i++ )
    {
        *out++ = data->left_phase;  /* left */
        *out++ = data->right_phase;  /* right */
        /* Generate simple sawtooth phaser that ranges between -1.0 and 1.0. */
        data->left_phase += 0.01f;
        /* When signal reaches top, drop back down. */
        if( data->left_phase >= 1.0f ) data->left_phase -= 2.0f;
        /* higher pitch so we can distinguish left and right. */
        data->right_phase += 0.03f;
        if( data->right_phase >= 1.0f ) data->right_phase -= 2.0f;
    }
    return 0;
}

AudioStream::AudioStream()
{
	PaError err = 0;
	err = Pa_Initialize();
	if(err != paNoError) {
		fprintf(stderr, "PortAudio Error: %s\n", Pa_GetErrorText(err));
		return;
	}

	err = Pa_OpenDefaultStream(&stream, 0, 1, paFloat32, SAMPLE_RATE, BUFFER_SIZE, paCallback, this);
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
		std::memcpy(outputBuffer, thisAlt->bufferQueue.front(), BUFFER_SIZE);
		thisAlt->nextSample();
	}
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
