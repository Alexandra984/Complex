#include "complex.hpp"

namespace complex {

Complex::Complex(double real, double imaginary) :
    _real(real),
    _imaginary(imaginary) {
}

Complex::Complex(const Complex& rhs) :
    _real(rhs._real),
    _imaginary(rhs._imaginary) {
}



}
