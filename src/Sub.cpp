#include "Integer.hpp"

using namespace arbitary_precision_arithmetic;

Integer Integer::SubModules(const Integer& other) const {
    Integer sub(*this);
    int8_t discharge = 1;
    sub.is_positive_ = true;
    for (int i = 0; i < this->Length(); ++i) {
        sub.numbers_[i] += base - 1 - other[i] + discharge;
        discharge = sub[i] / base;
        sub.numbers_[i] %= base;
    }
    while (sub.Length() > 1 && sub[sub.Length() - 1] == 0) {
        sub.numbers_.pop_back();
    }
    return sub;
}