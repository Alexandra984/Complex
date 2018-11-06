#include "complex.hpp"
#include <sstream>
#include <cmath>

namespace complex {

// Constructors
Complex::Complex(double real, double imaginary) :
    _real(real),
    _imaginary(imaginary) {
}

Complex::Complex(std::string str) {
  SetFromString(str);
}

Complex::Complex(const Complex& rhs) :
    _real(rhs._real),
    _imaginary(rhs._imaginary) {
}

// Destructor
Complex::~Complex() {
  // do nothing
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

Complex Sqrt(const Complex& num, int ord) {
  if (ord != 1 && ord != 2)
    throw "Invalid index of root";
  double theta = atan2(num._imaginary, num._real)/2
               + (ord == 1 ? 0 : Complex::kPI);
  return sqrt(Modulus(num)) * Complex(cos(theta), sin(theta));
}

// Read/Write operators
std::istream& operator>>(std::istream& in, Complex& num) {
  std::string str;
  in >> str;
  num.SetFromString(str);
  return in;
}

std::ostream& operator<<(std::ostream& out, const Complex& num) {
  out << num.ToString();
  return out;
}

// Class constant for PI
const double Complex::kPI = 3.141592653;

// Method to set the complex number from a string format
void Complex::SetFromString(std::string str) {
  static const char error[] = "Invalid format";
  if (str == "")
    throw error;

  std::size_t find_pos = str.find("i*");
  try {

    if (find_pos == std::string::npos) {
      //just real part
      std::size_t sz;
      double real = std::stod(str, &sz);
      if (sz < str.size())
        throw error;
      else {
        _real = real;
        _imaginary = 0;
      }
    } else if (find_pos == 0 || find_pos == 1) {
      //just imaginary part
      if (find_pos == 1 && str[0] != '-' && str[0] != '+')
        throw error;
      if (!isdigit(str[find_pos + 2]))
        throw error;

      str.erase(find_pos, 2);
      std::size_t sz;
      double imaginary = std::stod(str, &sz);
      if (sz < str.size())
        throw error;
      else {
        _imaginary = imaginary;
        _real = 0;
      }

    } else {
      //both
      int sign_imaginary;
      if (str[find_pos - 1] == '+')
        sign_imaginary = 1;
      else if (str[find_pos - 1] == '-')
        sign_imaginary = -1;
      else
        throw error;

      std::size_t sz;
      double real = std::stod(str.substr(0, find_pos - 1), &sz);
      if (sz < find_pos - 1)
        throw error;

      if (find_pos + 2 >= str.size() || !isdigit(str[find_pos + 2]))
        throw error;
      double imaginary = std::stod(str.substr(find_pos + 2), &sz);
      if (sz < str.size() - find_pos - 2)
        throw error;

      _real = real;
      _imaginary = sign_imaginary * imaginary;
    }

  }
  catch (...) {
    throw error;
  }
}

}
