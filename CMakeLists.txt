cmake_minimum_required(VERSION 2.7)
project(synth)

set(CMAKE_SOURCE_DIR .)
set(CMAKE_FILE_DIR ${CMAKE_SOURCE_DIR}/cmake)
set(MAIN_TARGET a.out)
set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_FILE_DIR}/portaudio.cmake)

set(SOURCES
	${CMAKE_SOURCE_DIR}/synth.cpp
	${CMAKE_SOURCE_DIR}/AudioStream.cpp
	${CMAKE_SOURCE_DIR}/NoteTimer.cpp
	${CMAKE_SOURCE_DIR}/PitchGen.cpp
	#${CMAKE_SOURCE_DIR}/SynthController.cpp
)

add_executable(${MAIN_TARGET} ${SOURCES})

target_link_libraries(${MAIN_TARGET} ${PORTAUDIO_LIBRARIES}) 
