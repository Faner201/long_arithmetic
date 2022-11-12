#include "Integer.hpp"

using namespace arbitary_precision_arithmetic;

Integer Integer::DivModules(const Integer& other) const {
    return std::get<0>(this->Devide(other));
}