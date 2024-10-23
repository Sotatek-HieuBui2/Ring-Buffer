#include <stdio.h>
#include <math.h>
#include "ringbuffer.h"

void RingBufferInit(RingBuffer *buffer, int x) {
    if(x < 0 || x > BUFFER_SIZE || buffer == NULL ){
   	buffer->size = 0;
        printf("Vui long nhap dam bao da khoi tao buffer\n") ;
        printf("va nhap 0 < size <= 50\n") ;
    }else{
    buffer->head = 0;
    buffer->tail = 0;
    buffer->count = 0;
    buffer->size = x;
    }
}

// Kiểm tra buffer có rỗng không
int RingBufferIsEmpty(RingBuffer *buffer) {
    if(buffer->count == 0){
        //printf("buffer is empty\n");
        return 1;
    }else{
        //printf("buffer is not empty\n");
        return 0;
    }
}

// Kiểm tra buffer có đầy không
int RingBufferIsFull(RingBuffer *buffer) {
    if(buffer->count == buffer->size){
        //printf("buffer is full\n");
        return 1;
    }else {
        printf("buffer is not full\n");
        return 0;
    }
}

// Thêm phần tử vào buffer
int RingBufferEnqueue(RingBuffer *buffer, int value) {
    if( value < -pow(2,8) - 1 || value > pow(2,8)){                  //kiem tra gia tri hop le cua value
	printf("vui long nhap gia tri tu -2^8 - 1 den 2^8");
    }else if (buffer->count == buffer->size) {                      // kiem tra buffer day
        printf("buffer day, khong the them %d\n", value);
        return -1;
    }else{
    buffer->data[buffer->tail] = value;
    buffer->tail = (buffer->tail + 1) % buffer->size;
    buffer->count++;
    return 0;
    }
}

// Lấy phần tử ra khỏi buffer
int RingBufferDequeue(RingBuffer *buffer, int *value) {
    if (buffer->count == 0) {                                   // kiem tra buffer rong
        printf("buffer rong, khong the lay phan tu\n");
        return -1;
    }else{
    *value = buffer->data[buffer->head];
    buffer->head = (buffer->head + 1) % buffer->size;
    buffer->count--;
    return 0;
}
}

// In kich thuoc của buffer
int RingBufferSize(RingBuffer *buffer) {
    int d = buffer->count;
    printf("Size of Buffer: %d\n", d);
    return d;
}
