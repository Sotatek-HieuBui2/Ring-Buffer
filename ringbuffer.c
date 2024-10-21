#include <stdio.h>
#include <stdbool.h>
#include "ringbuffer.h"

void ringBuffer_init(RingBuffer *buffer, int x) {
    buffer->head = 0;
    buffer->tail = 0;
    buffer->count = 0;
    buffer->size = x;
}

// Kiểm tra buffer có rỗng không
int ringBuffer_isEmpty(RingBuffer *buffer) {
    if(buffer->count == 0){
        printf("buffer is empty\n");
        return 1;
    }else{
        printf("buffer is not empty\n");
        return 0;
    }
}

// Kiểm tra buffer có đầy không
int ringBuffer_isFull(RingBuffer *buffer) {
    if(buffer->count == buffer->size){
        printf("buffer is full\n");
        return 1;
    }else {
        printf("buffer is not full\n");
        return 0;
    }
}

// Thêm phần tử vào buffer
int ringBuffer_enqueue(RingBuffer *buffer, int value) {
    if (buffer->count == buffer->size) {
        printf("buffer day, khong the them %d\n", value);
        return -1;
    }
    buffer->data[buffer->tail] = value;
    buffer->tail = (buffer->tail + 1) % BUFFER_SIZE;
    buffer->count++;
    return 0;
}

// Lấy phần tử ra khỏi buffer
int ringBuffer_dequeue(RingBuffer *buffer, int *value) {
    if (buffer->count == 0) {
        printf("buffer rong, khong the lay phan tu\n");
        return -1;
    }
    *value = buffer->data[buffer->head];
    buffer->head = (buffer->head + 1) % BUFFER_SIZE;
    buffer->count--;
    return 0;
}

// In trạng thái của buffer
int ringBuffer_print(RingBuffer *buffer) {
    int d = buffer->count;
    printf("Size of Buffer: %d\n", d);
}
