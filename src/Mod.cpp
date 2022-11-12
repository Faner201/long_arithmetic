#include "Integer.hpp"

using namespace arbitary_precision_arithmetic;

Integer Integer::ModModules(const Integer& other) const {
    return std::get<1>(this->Devide(other));
}