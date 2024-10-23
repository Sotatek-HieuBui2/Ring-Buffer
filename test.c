#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "ringbuffer.h"

RingBuffer buffer;

static void test_init(void **state)
{
  RingBufferInit(&buffer, 5);
  assert_int_equal(buffer.size, 5);
}

static void test_enqueue(void **state)
{
  int result = RingBufferEnqueue(&buffer, 10);
  assert_int_equal(result, 0);
}

static void test_dequeue(void **state)
{
  int p;
  int result = RingBufferDequeue(&buffer, &p);
  assert_int_equal(result, 0);
}

static void test_empty(void **state)
{
  int result = RingBufferIsEmpty(&buffer);
  assert_int_equal(result, 1);
}
static void test_full(void **state)
{
  RingBufferEnqueue(&buffer, 10);
  RingBufferEnqueue(&buffer, 10);
  RingBufferEnqueue(&buffer, 10);
  RingBufferEnqueue(&buffer, 10);
  RingBufferEnqueue(&buffer, 10);
  int result = RingBufferIsFull(&buffer);
  assert_int_equal(result, 1);
}

int main(void){
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_init),
    cmocka_unit_test(test_enqueue),
    cmocka_unit_test(test_dequeue),
    cmocka_unit_test(test_empty),
    cmocka_unit_test(test_full)   
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
