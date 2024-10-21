#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "ringbuffer.h"

RingBuffer buffer;

static void test_init(void **state)
{
  ringBuffer_init(&buffer, 5);
  assert_int_equal(buffer->size, 5);
}

static void test_enqueue(void **state)
{
  int result = ringBuffer_enqueue(&buffer, 10);
  assert_int_equal(result, 0);
}

static void test_dequeue(void **state)
{
  int result = ringBuffer_dequeue(&buffer, 5);
  assert_int_equal(result, 5);
}

static void test_empty(void **state)
{
  int result = ringBuffer_isEmpty(&buffer);
  assert_int_equal(result, 0);
}

int main(void){
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_init),
    cmocka_unit_test(test_enqueue),
    cmocka_unit_test(test_dequeue),
    cmocka_unit_test(test_empty)
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
