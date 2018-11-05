#include "complex.hpp"
#include <sstream>
#include <cmath>

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

// Binary operators
Complex Complex::operator+(const Complex& rhs) const {
  Complex res(*this);
  res += rhs;
  return res;
}

Complex Complex::operator+(double rhs) const {
  Complex res(*this);
  res += rhs;
  return res;
}

Complex operator+(double lhs, const Complex& rhs) {
  Complex res(rhs);
  res += lhs;
  return res;
}

Complex Complex::operator-(const Complex& rhs) const {
  Complex res(*this);
  res -= rhs;
  return res;
}

Complex Complex::operator-(double rhs) const {
  Complex res(*this);
  res -= rhs;
  return res;
}

Complex operator-(double lhs, const Complex& rhs) {
  Complex res(lhs);
  res -= rhs;
  return res;
}

Complex Complex::operator*(const Complex& rhs) const {
  Complex res(*this);
  res *= rhs;
  return res;
}

Complex Complex::operator*(double rhs) const {
  Complex res(*this);
  res *= rhs;
  return res;
}

Complex operator*(double lhs, const Complex& rhs) {
  Complex res(rhs);
  res *= lhs;
  return res;
}

Complex Complex::operator/(const Complex& rhs) const {
  Complex res(*this);
  res /= rhs;
  return res;
}

Complex Complex::operator/(double rhs) const {
  Complex res(*this);
  res /= rhs;
  return res;
}

Complex operator/(double lhs, const Complex& rhs) {
  Complex res(lhs);
  res /= rhs;
  return res;
}

Complex operator^(const Complex& lhs, int rhs) {
  int abs_pow = (rhs > 0 ? rhs : -rhs);
  Complex res(1);
  for (int i = 1; i <= abs_pow; ++i)
    res *= lhs;
  if (rhs < 0)
    res = 1 / res;
  return res;
}

// Relational operators
bool Complex::operator==(const Complex& rhs) const {
  return _real == rhs._real && _imaginary == rhs._imaginary;
}

bool Complex::operator==(double rhs) const {
  return _real == rhs && _imaginary == 0;
}

bool operator==(double lhs, const Complex& rhs) {
  return lhs == rhs._real && rhs._imaginary == 0;
}

bool Complex::operator!=(const Complex& rhs) const {
  return _real != rhs._real || _imaginary != rhs._imaginary;
}

bool Complex::operator!=(double rhs) const {
  return _real != rhs || _imaginary != 0;
}

bool operator!=(double lhs, const Complex& rhs) {
  return lhs != rhs._real || rhs._imaginary != 0;
}


// Returns conjugate of number
Complex Complex::Conjugate() const {
  return Complex(_real, -_imaginary);
}

// ToString method
std::string Complex::ToString() const {
  std::ostringstream stream;
  if (_real == 0 && _imaginary == 0)
    stream << "0";
  else if (_imaginary == 0)
    stream << _real;
  else if (_real == 0)
    stream << (_imaginary < 0 ? "-" : "") << "i*"
           << (_imaginary < 0 ? -_imaginary : _imaginary);
  else
    stream << _real << (_imaginary < 0 ? "-" : "+") << "i*"
           << (_imaginary < 0 ? -_imaginary : _imaginary);
  return stream.str();
}

// Conversion operators
Complex::operator std::string() const {
  return ToString();
}

// Friend methods
double Modulus(const Complex& num) {
  return sqrt(num._real*num._real + num._imaginary*num._imaginary);
}


























}













