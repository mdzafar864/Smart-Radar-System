// Placeholder native (host-side) test for the median-of-3 noise filter used
// in firmware/RadarSystem/RadarSystem.ino.
//
// To wire this up for real:
//   1. Extract the median calculation into a plain function, e.g.
//        int medianOf3(int a, int b, int c);
//      in a shared header included by both the firmware .ino and this test.
//   2. Run with: pio test -e native
//
// This stub demonstrates the expected shape of that test using Unity
// (bundled with PlatformIO's test runner).

#include <unity.h>

// TODO: #include the extracted median-of-3 helper once it exists.
static int medianOf3(int a, int b, int c) {
  int maxV = a > b ? (a > c ? a : c) : (b > c ? b : c);
  int minV = a < b ? (a < c ? a : c) : (b < c ? b : c);
  return a + b + c - maxV - minV;
}

void test_median_picks_middle_value(void) {
  TEST_ASSERT_EQUAL_INT(20, medianOf3(30, 20, 10));
  TEST_ASSERT_EQUAL_INT(20, medianOf3(10, 20, 30));
}

void test_median_handles_duplicates(void) {
  TEST_ASSERT_EQUAL_INT(15, medianOf3(15, 15, 999));
}

void setup() {
  UNITY_BEGIN();
  RUN_TEST(test_median_picks_middle_value);
  RUN_TEST(test_median_handles_duplicates);
  UNITY_END();
}

void loop() {}

#ifdef PIO_UNIT_TESTING
int main(int argc, char **argv) {
  setup();
  return 0;
}
#endif
