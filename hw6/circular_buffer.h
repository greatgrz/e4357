#ifndef __CIRCULAR_BUFFER_H
#define __CIRCULAR_BUFFER_H

inline int CircularBufferIsFull(CircularBuffer* que);
inline int CircularBufferIsEmpty(CircularBuffer* que);
inline int CircularBufferEnque(CircularBuffer* que, KeyType k);
inline int CircularBufferDeque(CircularBuffer* que, KeyType* pK);
inline int CircularBufferPrint(CircularBuffer* que);

#endif 
