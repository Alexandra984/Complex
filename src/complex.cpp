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

// Assignment operators
Complex& Complex::operator=(const Complex& rhs) {
  _real = rhs._real;
  _imaginary = rhs._imaginary;
  return *this;
}

Complex& Complex::operator=(double rhs) {
  _real = rhs;
  _imaginary = 0;
  return *this;
}

Complex& Complex::operator+=(const Complex& rhs) {
  _real += rhs._real;
  _imaginary += rhs._imaginary;
  return *this;
}

Complex& Complex::operator+=(double rhs) {
  _real += rhs;
  return *this;
}

Complex& Complex::operator-=(const Complex& rhs) {
  _real -= rhs._real;
  _imaginary -= rhs._imaginary;
  return *this;
}

Complex& Complex::operator-=(double rhs) {
  _real -= rhs;
  return *this;
}

Complex& Complex::operator*=(const Complex& rhs) {
  double new_real = _real*rhs._real - _imaginary*rhs._imaginary;
  double new_imaginary = _real*rhs._imaginary + _imaginary*rhs._real;
  _real = new_real;
  _imaginary = new_imaginary;
  return *this;
}

Complex& Complex::operator*=(double rhs) {
  _real *= rhs;
  _imaginary *= rhs;
  return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
  if (rhs._real == 0 && rhs._imaginary == 0)
    throw "Division by 0";
  *this *= rhs.Conjugate();
  *this /= rhs._real*rhs._real + rhs._imaginary*rhs._imaginary;
  return *this;
}

Complex& Complex::operator/=(double rhs) {
  if (rhs == 0)
    throw "Division by 0";
  _real /= rhs;
  _imaginary /= rhs;
  return *this;
}

// Unary operators
Complex operator+(const Complex& rhs) {
  return rhs;
}

Complex operator-(const Complex& rhs) {
  return Complex(-rhs._real, -rhs._imaginary);
}

// Returns conjugate of number
Complex Complex::Conjugate() const {
  return Complex(_real, -_imaginary);
}














}













