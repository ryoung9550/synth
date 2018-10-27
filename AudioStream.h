#include <portaudio.h>
#include <deque>
	

struct StreamData
{
	float* buffer;
	bool isEmpty;
};

typedef struct
{
	    float left_phase;
		    float right_phase;
}   
paTestData;

class AudioStream
{
public:
	const static int BUFFER_SIZE = 256;

	// Member Functions
	static int paCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags,  void *userData);

	//Member Variables
	PaStream* stream;
	std::deque<float*> bufferQueue;
	StreamData* callbackData;
	bool startSuccess = false;
	int bufferQueueArrOffest = 0;
	// Member Functions
	AudioStream();
	~AudioStream();

	// Member Variables
	const static int SAMPLE_RATE = 44100;
	int sendAudio(float* audioStream, int size);
	int sendAudio(float* audioStream);
	int stopAudio();
	bool emptyBuffer();
	int nextSample();
	float* next();
	bool running = false;
};

const static float BLANK_AUDIO[AudioStream::BUFFER_SIZE] {0};
