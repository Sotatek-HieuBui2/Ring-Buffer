#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "ringbuffer.h"
#include <math.h>

RingBuffer buffer;

// ham test khoi tao fail khi truyen size nho hon 0
static void test_init_fail(void **state)
{
  RingBufferInit(&buffer, -5);
  assert_int_equal(buffer.size, 0);

}

// ham test khoi tao thanh cong khi 0 <= size <= MAXSIZE=50
static void test_init(void **state)
{
  RingBufferInit(&buffer, 5);
  assert_int_equal(buffer.size, 5);

}

// ham test them fail khi truyen so lon hon 2^8
static void test_enqueue_fail(void **state)
{
  int result = RingBufferEnqueue(&buffer, pow(2,9));
  assert_int_equal(result, 1);
}

// ham test them thanh cong voi -2^8 - 1 <= bien <= 2^8
static void test_enqueue(void **state)
{
  int result = RingBufferEnqueue(&buffer, 10);
  assert_int_equal(result, 0);
}

// ham test buffer khong rong
static void test_n_empty(void **state)
{
  int result = RingBufferIsEmpty(&buffer);
  assert_int_equal(result, 0);
}

// ham test lay phan tu thanh cong
static void test_dequeue(void **state)
{
  int p;
  int result = RingBufferDequeue(&buffer, &p);
  assert_int_equal(result, 0);
}

// ham test buffer rong
static void test_empty(void **state)
{
  int result = RingBufferIsEmpty(&buffer);
  assert_int_equal(result, 1);
}

// ham test lay phan tu that bai
static void test_dequeue_fail(void **state)
{
  int p;
  int result = RingBufferDequeue(&buffer, &p);
  assert_int_equal(result, -1);
}

// ham test buffer khong day
static void test_n_full(void **state)
{
  int result = RingBufferIsFull(&buffer);
  assert_int_equal(result, 0);
}

// ham test buffer day
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

// ham test them phan tu that bai khi buffer day
static void test_enqueue_fail_full(void **state)
{
  int result = RingBufferEnqueue(&buffer, 5);
  assert_int_equal(result, -1);
}

// ham test in so phan tu hien tai cua buffer
static void test_print_size(void **state)
{
  int result = RingBufferSize(&buffer);
  assert_int_equal(result, 5);
}

int main(void){
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_init_fail),
    cmocka_unit_test(test_init),
    cmocka_unit_test(test_enqueue_fail),
    cmocka_unit_test(test_enqueue),
    cmocka_unit_test(test_n_empty),
    cmocka_unit_test(test_dequeue),
    cmocka_unit_test(test_empty),
    cmocka_unit_test(test_dequeue_fail),
    cmocka_unit_test(test_n_full),
    cmocka_unit_test(test_full),
    cmocka_unit_test(test_enqueue_fail_full),
    cmocka_unit_test(test_print_size)   
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
