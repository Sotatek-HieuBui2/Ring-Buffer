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

void ringBuffer_init(RingBuffer *buffer, int x);
int ringBuffer_isEmpty(RingBuffer *buffer);
int ringBuffer_isFull(RingBuffer *buffer);
int ringBuffer_enqueue(RingBuffer *buffer, int value);
int ringBuffer_dequeue(RingBuffer *buffer, int *value);
int ringBuffer_print(RingBuffer *buffer);
#endif
