#include "Integer.hpp"

using namespace arbitary_precision_arithmetic;

Integer Integer::MulModules(const Integer& other) const {
    Integer mul;
    int8_t discharge = 0;
    mul.numbers_.resize(this->Length() + other.Length() + 2);
    for (int i = 0; i <= this->Length(); ++i) {
        for (int j = 0; j <= other.Length(); ++j) {
            mul.numbers_[i + j] += (*this)[i] * other[j] + discharge;
            discharge = mul[i + j] / base;
            mul.numbers_[i + j] %= base;
        }
    }
    while (mul.Length() > 1 && mul[mul.Length() - 1] == 0) {
        mul.numbers_.pop_back();
    }
    return mul;
}