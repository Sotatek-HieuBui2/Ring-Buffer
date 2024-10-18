CC := g++

build : ringbuffer.c
	$(CC) ringbuffer.c -o ringbuffer
remove:
	rm -rf ringbuffer

