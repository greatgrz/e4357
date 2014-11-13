#ifndef __CIRCULAR_BUFFER
#define __CIRCULAR_BUFFER

/* Implement a circularbuffer library with the following API interface */

/**< Circular Buffer Types */
typedef unsigned char INT8U;
typedef INT8U KeyType ;
typedef struct {  
    INT8U writePointer ; /**< write pointer */  
    INT8U readPointer ;  /**< read pointer */  
    INT8U size;         /**< size of circular buffer */
    INT8U mask;         /**< bit Mask of circular buffer size*/   
    KeyType keys[0];    /**< Element of ciruclar buffer */
} CircularBuffer ; 

inline int CircularBufferIsFull(CircularBuffer* que)
{
	if ((que->readPointer - que->writePointer) == 1) {
		return 1;
	}
	else {
		return 0;
	}
 }
 
inline int CircularBufferIsEmpty(CircularBuffer* que)
{
	if (que->readPointer == que->writePointer) {
		return 1;
	}
	else {
		return 0;
	}
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
	retuen 1; 
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
	retuen 1; 	
 }

inline int CircularBufferPrint(CircularBuffer* que)
{ 
	while(que->writePointer != que->readPointer) {
		printf("data : %d\n", que->keys[readPointer]);
		if (que->readPointer == que->mask) {
			que->readPointer = 0 ;
		}
		else {
			que->readPointer++ ;
		}	
	}
	return 1; 
}

#endif