#include "Integer.hpp"

using namespace arbitary_precision_arithmetic;

std::tuple<Integer, Integer> Integer::Devide(const Integer& other) const {
    Integer result;
    Integer remainder(*this);
    Integer divider(other);
    remainder.is_positive_ = true;
    divider.is_positive_ = true;

    while (remainder >= divider) {
        remainder -= divider;
        result++;
    }
    return std::make_tuple(result, remainder);
}