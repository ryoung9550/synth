#ifndef _RING_BUFFER_H
#define _RING_BUFFER_H

#include <cstring>

template<typename T, int size>
class RingBuffer
{
	int writeIndex = 0;
	int readIndex = 0;
	T data[size] {0};
	unsigned WRdiff = 0;
	const int BUFFPADDING = 8000;
public:
	T read()
	{
		if(readIndex >= size) {
			readIndex = 0;
		}
		if(WRdiff <= BUFFPADDING) {
			return 0;
		}
		WRdiff--;
		return data[readIndex++];
	}
	int write(T _data)
	{
		if(writeIndex >= size) {
			writeIndex = 0;
		}
		while(WRdiff >= size - BUFFPADDING /2);
		WRdiff++;
		data[writeIndex++] = _data;
		return 0;
	}
};

#endif // _RING_BUFFER_H
