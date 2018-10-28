# Creation rules

CXXFLAGS=-std=c++14
CXXLIBS=-lportaudio
CXXCOMPILER=g++

default: a.out

a.out: AudioStream.o synth.o PitchGen.o
	 ${CXXCOMPILER} ${CXXFLAGS} ${CXXLIBS} $^ -o $@

synth.o: synth.cpp
	${CXXCOMPILER} ${CXXFLAGS} -c $^ -o $@

AudioStream.o: AudioStream.cpp
	${CXXCOMPILER} ${CXXFLAGS} -c $^ -o $@

PitchGen.o: PitchGen.cpp
	${CXXCOMPILER} ${CXXFLAGS} -c $^ -o $@

clean:
	rm *.o a.out
