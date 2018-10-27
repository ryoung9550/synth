#ifndef _RING_BUFFER_H
#define _RING_BUFFER_H

#include <cstring>

template<typename T, int size>
class RingBuffer
{
	int writeIndex = 0;
	int readIndex = 0;
	T data[size] {0};
public:
	T read()
	{
		if(readIndex >= size) {
			readIndex = 0;
		}
		return data[readIndex++];
	}
	int write(T _data)
	{
		if(writeIndex >= size) {
			writeIndex = 0;
		}
		data[writeIndex++] = _data;
		return 0;
	}
};

#endif // _RING_BUFFER_H
