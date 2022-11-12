#include <iostream>

#include "Integer.hpp"

using namespace arbitary_precision_arithmetic;

Integer Integer::SumModules(const Integer& other) const {
  int discharge = 0;
  Integer sum;
  std::size_t max_size = std::max(this->numbers_.size(), other.numbers_.size());
  sum.numbers_.resize(max_size);
  for (int i = 0; i < max_size; ++i) {
    sum.numbers_[i] = (*this)[i] + other[i] + discharge;
    discharge = sum[i] / base;
    sum.numbers_[i] %= base;
  }
  if (discharge) {
    sum.numbers_.push_back(1);
  }
  return sum;
}
