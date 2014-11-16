//#include <iostream>
#include "circular_buffer.cpp"
#include "mbed.h"


Serial pc(USBTX, USBRX) ; 


//initialize circular buffer
CircularBuffer* CircularBufferInit(CircularBuffer** pQue, int size) {
	int sz = size*sizeof(KeyType) + sizeof(CircularBuffer);
	*pQue = (CircularBuffer*) malloc(sz);
	if(*pQue) {
		pc.printf("init CircularBuffer : keys[%d] (%d)\n", size, sz);
		if(!(size & (size-1))) {
			(*pQue)->size = size;
			(*pQue)->mask = size-1;
			(*pQue)->writePointer = 0;
			(*pQue)->readPointer = 0;
		}
		else {
			pc.printf("Error size\n");
		}
	}
	return *pQue;
}

inline int CircularBufferPrint(CircularBuffer* que)
{ 
	while(que->writePointer != que->readPointer) {
		pc.printf("data : %d\n", que->keys[que->readPointer]);
		if (que->readPointer == que->mask) {
			que->readPointer = 0 ;
		}
		else {
			que->readPointer++ ;
		}	
	}
//	printf("data : %d\n", que->keys[que->writePointer]) ; 
	return 1; 
}

int main() {
	pc.baud(115200);
	wait(.1);
//	pc.format(8,Serial::None,1);
	CircularBuffer* myQ;
	myQ = CircularBufferInit(&myQ, 4);

	KeyType testvec[7] = {4, 6, 5, 9, 7, 11, 18};
	KeyType readval;
	for (int i = 0; i < 7; i ++) {
		if (!CircularBufferIsFull(myQ)) {
			CircularBufferEnque(myQ, testvec[i]);
		}
	}
	
	if(!CircularBufferIsEmpty(myQ)) {
		CircularBufferDeque(myQ, &readval);
	    pc.printf("the read output is %d\n", readval);
	}

	CircularBufferPrint(myQ);
	return 1;
}


