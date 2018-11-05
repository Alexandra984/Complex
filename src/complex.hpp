#ifndef COMPLEX_SRC_COMPLEX_HPP_
#define COMPLEX_SRC_COMPLEX_HPP_

#include <string>
#include <iostream>

namespace complex {

class Complex {
 public:
  // Constructors
  Complex(double real = 0, double imaginary = 0);
  Complex(std::string str);
  Complex(const Complex& rhs);

  // Getters
  double real() const;
  double imaginary() const;

  // Setters
  void set_real(double real);
  void set_imaginary(double imaginary);

  // Assignment operators
  Complex& operator=(const Complex& rhs);
  Complex& operator=(double rhs);

  Complex& operator+=(const Complex& rhs);
  Complex& operator+=(double rhs);

  Complex& operator-=(const Complex& rhs);
  Complex& operator-=(double rhs);

  Complex& operator*=(const Complex& rhs);
  Complex& operator*=(double rhs);

  Complex& operator/=(const Complex& rhs);
  Complex& operator/=(double rhs);

  // Unary operators
  friend Complex operator+(const Complex& rhs);
  friend Complex operator-(const Complex& rhs);

  // Binary operators
  Complex operator+(const Complex& rhs) const;
  Complex operator+(double rhs) const;
  friend Complex operator+(double lhs, const Complex& rhs);

  Complex operator-(const Complex& rhs) const;
  Complex operator-(double rhs) const;
  friend Complex operator-(double lhs, const Complex& rhs);

  Complex operator*(const Complex& rhs) const;
  Complex operator*(double rhs) const;
  friend Complex operator*(double lhs, const Complex& rhs);

  Complex operator/(const Complex& rhs) const;
  Complex operator/(double rhs) const;
  friend Complex operator/(double lhs, const Complex& rhs);

  friend Complex operator^(const Complex& lhs, int rhs);

  // Relational operators
  bool operator==(const Complex& rhs) const;
  bool operator==(double rhs) const;
  friend bool operator==(double lhs, const Complex& rhs);

  bool operator!=(const Complex& rhs) const;
  bool operator!=(double rhs) const;
  friend bool operator!=(double lhs, const Complex& rhs);

  // ToString method
  std::string ToString() const;

  // Returns conjugate of number
  Complex Conjugate() const;

  // Conversion operators
  operator std::string() const;

  // Friend Methods
  friend double Abs(const Complex& num);
  friend Complex Sqrt(const Complex& num, int ord = 1);

  // Read/Write operators
  friend std::istream& operator>>(std::istream& in, Complex& num);
  friend std::ostream& operator<<(std::ostream& out, const Complex& num);

 private:
  void SetFromString(std::string str);

  double _real;
  double _imaginary;
};

}

#endif

