static:
	ar rcs lib/static/libringbuffer.a obj/ringbuffer.o
link:
	gcc --coverage obj/test.o -Llib -lcmocka -Linclude -Llib/static -lringbuffer -o bin/test
build:
	gcc -c -fprofile-arcs -ftest-coverage test.c -o obj/test.o -I./include -I./inc
	gcc -c -fprofile-arcs -ftest-coverage src/ringbuffer.c -o obj/ringbuffer.o -I./inc
run:
	./bin/test
rmlib:
	rm  -f lib/static/*
lcov:
	lcov -c -d ./obj -o cov.info
	genhtml cov.info -o cov
	firefox ./cov/index.html
watch:
	firefox ./cov/index.html
all:
	gcc -c -fprofile-arcs -ftest-coverage test.c -o obj/test.o -I./include -I./inc
	gcc -c -fprofile-arcs -ftest-coverage src/ringbuffer.c -o obj/ringbuffer.o -I./inc
	ar rcs lib/static/libringbuffer.a obj/ringbuffer.o
	gcc --coverage obj/test.o -Llib -lcmocka -Linclude -Llib/static -lringbuffer -o bin/test
clean:
	rm -rf obj/* bin/* lib/static/*
	rm -rf cov.info cov/*

PHONY: test install

CMOCKA_DIR=$(shell pwd)/cmocka-1.1.0
CMOCKA_BUILD_DIR=$(CMOCKA_DIR)/build
CMOCKA_OUT_DIR=$(CMOCKA_BUILD_DIR)/output


install:
	curl https://cmocka.org/files/1.1/cmocka-1.1.0.tar.xz -o cmocka.tar
	tar xf cmocka.tar
	rm cmocka.tar
	mkdir -p $(CMOCKA_OUT_DIR)
	cd $(CMOCKA_BUILD_DIR) && \
		 cmake -DWITH_STATIC_LIB=1 -DCMAKE_INSTALL_PREFIX=$(CMOCKA_OUT_DIR) .. && \
		 make && \
		 make install
	mkdir -p lib include
	cp $(CMOCKA_OUT_DIR)/lib/libcmocka.a lib
	cp $(CMOCKA_OUT_DIR)/include/*.h include
	rm -R $(CMOCKA_DIR)

