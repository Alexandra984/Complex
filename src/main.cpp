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

  std::cout << Modulus(y) << std::endl;

  std::cout << Sqrt(y).ToString() << " " << Sqrt(y, 2).ToString() << std::endl;

  std::cout << x << " " << y << std::endl;

  complex::Complex t("-5.034+i*4.33");
  std::cout << t << std::endl;

  try {
    std::cin >> x;
  }
  catch (const char* msg) {
    std::cout << msg << std::endl;
    return 0;
  }

  std::cout << x << std::endl;

  return 0;
}
