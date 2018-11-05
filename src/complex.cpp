#include "complex.hpp"

namespace complex {

// Constructors
Complex::Complex(double real, double imaginary) :
    _real(real),
    _imaginary(imaginary) {
}

Complex::Complex(const Complex& rhs) :
    _real(rhs._real),
    _imaginary(rhs._imaginary) {
}

// Getters
double Complex::real() const {
  return _real;
}

double Complex::imaginary() const {
  return _imaginary;
}

// Setters
void Complex::set_real(double real) {
  _real = real;
}

void Complex::set_imaginary(double imaginary) {
  _imaginary = imaginary;
}

}
