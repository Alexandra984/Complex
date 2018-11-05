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

  z = -y;
  std::cout << z.real() << " " << z.imaginary() << std::endl;

  z = (z^3) / z;
  std::cout << z.real() << " " << z.imaginary() << std::endl;

  std::cout << (z == y) << " " << (y != y) << " " << (5 != z) << std::endl;

  std::cout << static_cast<std::string>(complex::Complex(-2, 3)) << " "
            << complex::Complex(0, -3).ToString() << std::endl;

  return 0;
}
