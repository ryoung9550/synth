#include "NoteTimer.h"
#include <iostream>
#include <ctime>

NoteTimer::NoteTimer(size_t tempo, NoteValue beatCount) : tempo(tempo), beatCount(beatCount) {}

size_t NoteTimer::getTempo()
{
	return tempo;
}

int NoteTimer::setTempo(size_t tempo)
{
	this->tempo = tempo;
	return 0;
}

double NoteTimer::getNoteLength(NoteValue note)
{
	double bps = (double) tempo / 60.0; // Beats per second
	double spb = 1 / bps; // Seconds per beat
	double retTime = 0;
	switch(note) {
	case thirty_second:
		retTime = spb / 8;
		break;
	case sixteenth:
		retTime = spb / 4;
		break;
	case eighth:
		retTime = spb / 2;
		break;
	case quarter:
		retTime = spb;
		break;
	case half:
		retTime = spb * 2;
		break;
	case full:
		retTime = spb * 4;
		break;
	}
	return retTime;
}

#ifdef NOTE_TIMER_TEST

int main()
{
	NoteTimer timer(130, NoteValue::quarter);
	std::cout << timer.getNoteLength(quarter) << '\n';
}

#endif
