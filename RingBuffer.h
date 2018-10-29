#ifndef _RING_BUFFER_H
#define _RING_BUFFER_H

#include <cstring>
#include <mutex>

template<typename T, int size>
class RingBuffer
{
	int writeIndex = 0;
	int readIndex = 0;
	T data[size] {0};
	std::mutex mtx;
	unsigned WRdiff = 0;
public:
	T read()
	{
		if(readIndex >= size) {
			readIndex = 0;
		}
		while(WRdiff <= 0) {
			//return 0;
		}
		mtx.lock();
		WRdiff--;
		mtx.unlock();
		return data[readIndex++];
	}
	int write(T _data)
	{
		if(writeIndex >= size) {
			writeIndex = 0;
		}
		while(WRdiff >= size - 1);
		mtx.lock();
		WRdiff++;
		mtx.unlock();
		data[writeIndex++] = _data;
		return 0;
	}
};

#endif // _RING_BUFFER_H
