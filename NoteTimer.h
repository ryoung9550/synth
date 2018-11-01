#ifndef _NOTE_TIMER_H
#define _NOTE_TIMER_H

#include <cstring>

enum NoteValue
{
	thirty_second,
	sixteenth,
	eighth,
	quarter,
	half,
	full
};

class NoteTimer
{
private:
	size_t tempo; // Beats per minute
	NoteValue beatCount;

public:
	NoteTimer(size_t tempo, NoteValue beatCount);
	size_t getTempo();
	int setTempo(size_t tempo);

	/*
	 * @brief Returns time in seconds of the length of a note. It will
	 *        use the tempo value to calulate it.
	 * @param note - Musically notation of length of a note
	 * @return - Time in seconds of the expected note length.
	 */
	double getNoteLength(NoteValue note);
};

#endif // _NOTE_TIMER_H
