#include <iostream>
#include <math.h>
#include <stdint.h>

extern "C" uint64_t inc_func(uint64_t x);
extern "C" uint64_t fact_func(uint64_t x);
extern "C" uint64_t lntwo_func(uint64_t x);
extern "C" uint64_t gcd_func(uint64_t x, uint64_t y);

int main(int argc, char **argv) {
  std::cout << "test inc_func(add_one):" << std::endl;
  for (uint64_t i = 0; i < 10; ++i) {
    std::cout << "iteration: " << i << " inc value: " << inc_func(i)
              << std::endl;
  }

  std::cout << std::endl << "test fact_func(5) 'should be 120':" << std::endl;
  std::cout << "result: " << fact_func(5) << std::endl;
  std::cout << std::endl << "test fact_func(7) 'should be 5040':" << std::endl;
  std::cout << "result: " << fact_func(7) << std::endl;
  std::cout << std::endl << "test fact_func(8) 'should be 40320':" << std::endl;
  std::cout << "result: " << fact_func(8) << std::endl;
  std::cout << std::endl
            << "test fact_func(9) 'should be 362880':" << std::endl;
  std::cout << "result: " << fact_func(9) << std::endl;

  std::cout << std::endl << "test lntwo_func(32) 'should be 5':" << std::endl;
  std::cout << "result: " << lntwo_func(32) << std::endl;
  std::cout << "test lntwo_func(1) 'should be 0':" << std::endl;
  std::cout << "result: " << lntwo_func(1) << std::endl;
  std::cout << "test lntwo_func(0) 'should be 0':" << std::endl;
  std::cout << "result: " << lntwo_func(0) << std::endl;

  std::cout << std::endl
            << "test gcd_func(81, 153) 'should be 9':" << std::endl;
  std::cout << "result: " << gcd_func(81, 153) << std::endl;
  std::cout << "test gcd_func(18, 24) 'should be 6':" << std::endl;
  std::cout << "result: " << gcd_func(18, 24) << std::endl;
  std::cout << "test gcd_func(7, 9) 'should be 1':" << std::endl;
  std::cout << "result: " << gcd_func(7, 9) << std::endl;
  return 0;
}
