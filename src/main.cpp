#include "complex.hpp"
#include <iostream>

int main() {
  complex::Complex x(2, 3);
  complex::Complex y(x);

  x.set_real(5);
  std::cout << x.real() << " " << y.real() << std::endl;

  complex::Complex z(4, 4);
  z /= y += x;
  std::cout << z.real() << " " << z.imaginary() << std::endl;

  return 0;
}
