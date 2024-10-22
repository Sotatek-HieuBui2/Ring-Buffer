#ifndef ringbuffer_h
#define ringbuffer_h
#include <stdio.h>
#include <stdint.h>

#define BUFFER_SIZE 50
typedef struct {
   int data[BUFFER_SIZE];  // Mảng lưu dữ liệu
    int head;  // Con trỏ đầu
    int tail;  // Con trỏ cuối
    int count; // Số lượng phần tử hiện tại trong buffer
    int size;
} RingBuffer;

void RingBufferInit(RingBuffer *buffer, int x);
int RingBufferIsEmpty(RingBuffer *buffer);
int RingBufferIsFulll(RingBuffer *buffer);
int RingBufferEnqueue(RingBuffer *buffer, int value);
int RingBufferDequeue(RingBuffer *buffer, int *value);
int RingBufferSize(RingBuffer *buffer);
#endif
