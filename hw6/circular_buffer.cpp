
#include "mbed.h"
#include "circular_buffer.h"



inline int CircularBufferIsFull(CircularBuffer* que)
{
	return (((que->writePointer + 1) & que->mask) == que->readPointer);

 }
 
inline int CircularBufferIsEmpty(CircularBuffer* que)
{
	return (que->readPointer == que->writePointer) ;
 }
 
inline int CircularBufferEnque(CircularBuffer* que, KeyType k)
{
	que->keys[que->writePointer] = k ;
	if (que->writePointer == que->mask) {
		que->writePointer = 0 ;
	}
	else {
		que->writePointer++ ;
	}
	return 1; 
 }

inline int CircularBufferDeque(CircularBuffer* que, KeyType* pK)
{
	*pK = que->keys[que->readPointer]  ;
	if (que->readPointer == que->mask) {
		que->readPointer = 0 ;
	}
	else {
		que->readPointer++ ;
	}
	return 1; 	
 }



//}

//#endif
