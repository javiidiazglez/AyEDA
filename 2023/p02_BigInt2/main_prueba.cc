#include <iostream>
#include <chrono>


#include "bigint.h"
#include "bigint2.h"

int main() {
  BigInt<2> x(427);

  BigInt<10> y(427);
  //Test 
  BigInt<8> z = (BigInt<8>)x;
  BigInt<10> w = (BigInt<10>)x;
  BigInt<16> v = (BigInt<16>)x;
 std::cout << "x: " << x << std::endl;
  std::cout << "z: " << z << std::endl;
  std::cout << "w: " << w << std::endl;
  std::cout << "v: " << v << std::endl;
  std::cout << "y: " << y << std::endl;

  return 0;
}