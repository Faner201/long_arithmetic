#include "Integer.hpp"
#include "Sum.cpp"
#include "Sub.cpp"
#include "Mul.cpp"
#include "Div.cpp"
#include "Mod.cpp"
#include "Devide.cpp"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace arbitary_precision_arithmetic;


Integer::Integer() {
    numbers_ = {0};
    is_positive_ = true;
}

Integer::Integer(const Integer& other) {
    this->numbers_ = other.numbers_;
    this->is_positive_ = other.is_positive_;
}

Integer::Integer(Integer&& other) {
    numbers_ = std::move(other.numbers_);
    is_positive_ = other.is_positive_;
}

Integer& Integer::operator=(const Integer& other) {
    numbers_ = other.numbers_;
    is_positive_ = other.is_positive_;
    return *this;
}

Integer& Integer::operator=(Integer&& other) {
    numbers_ = std::move(other.numbers_);
    is_positive_ = other.is_positive_;
    return *this;
}

template<typename T, typename Type>
Integer::Integer(T number) {
    is_positive_ = number >= 0;
    if (number == 0) {
        numbers_.push_back(0);
    } else if (number < 0) {
        number *= -1;
    }
    while (number != 0) {
        numbers_.push_back(number % base);
        number /= base;
   }
}

Integer Integer::operator-() const {
    if (*this == Integer(0)) {
        return *this;
    }
    Integer integer(*this);
    integer.is_positive_ = !is_positive_;
    return integer;
}

Integer& Integer::operator--() {
    return *this -= Integer(1);
}

Integer Integer::operator--(int) {
    Integer temp(*this);
    *this -= Integer(1);
    return temp;
}

Integer Integer::operator+() const {
    return *this;
}

Integer& Integer::operator++() {
    return *this += Integer(1);
}

Integer Integer::operator++(int) {
    Integer temp(*this);
    *this += Integer(1);
    return temp;
}

bool Integer::operator==(const Integer& other) const {
    if (other.is_positive_ != this->is_positive_) {
        return false;
    }

    if (other.numbers_.size() != this->numbers_.size()) {
        return false;
    }

    for (int i = 0; i < this->numbers_.size(); ++i) {
        if (other.numbers_[i] != this->numbers_[i]) {
            return false;
        }
    }
    return true;
}

bool Integer::operator>(const Integer& other) const {
    if (other == *this) {
        return false;
    }

    if (this->is_positive_ != other.is_positive_) {
        return this->is_positive_;
    }

    if (this->is_positive_) {
        return this->GreaterModules(other);
    }
    return other.GreaterModules(*this);
}

bool Integer::operator<(const Integer& other) const {
    return other > *this;
}

bool Integer::operator<=(const Integer& other) const {
    return *this < other || *this == other;
}

bool Integer::operator>=(const Integer& other) const {
    return *this > other || *this == other;
}

bool Integer::operator!=(const Integer& other) const {
    return !(other == *this);
}

Integer::operator bool() const {
    return !(this->numbers_.size() == 1 && this->numbers_[0] == 0);
}

template<typename T, typename Type>
Integer::operator T() const {
    if(*this >= Integer(std::numeric_limits<T>::max())) {
        return std::numeric_limits<T>::max();
    }
    T number = 0;
    if (*this <= Integer(std::numeric_limits<T>::min())) {
        return std::numeric_limits<T>::min();
    }
    for (int i = 0; i < this->numbers_.size(); ++i) {
        number += this->numbers_[i] * std::pow(base, i);
    }
    return number;
}

Integer Integer::operator+(const Integer& other) const {
    if (this->is_positive_ && other.is_positive_) {
       return this->SumModules(other);
    }
    if (!this->is_positive_ && !other.is_positive_) {
        Integer result = this->SumModules(other);
        return -result;
    }
    if (this->is_positive_) {
        if (this->GreaterModules(other)) {
            return this->SubModules(other);
        } else {
            Integer result = other.SubModules(*this);
            return -result;
        }
    }
    if (this->GreaterModules(other)) {
        Integer result = this->SubModules(other);
        return -result;
    } else {
        return other.SubModules(*this);
    }
}

Integer Integer::operator-(const Integer& other) const {
    return (*this) + (-other);
}

std::size_t Integer::Length() const {
    return this->numbers_.size();
}

bool Integer::Sign() {
    return this->is_positive_;
}

Integer& Integer::operator+=(const Integer& other){
    *this = *this + other;
    return *this;
}

Integer& Integer::operator-=(const Integer& other){
    *this = *this - other;
    return *this;
}

Integer Integer::operator*(const Integer& other) const {
    if (this->is_positive_ == other.is_positive_) {
        return this->MulModules(other);
    } else {
        Integer result = this->MulModules(other);
        return -result;
    }
}

Integer& Integer::operator*=(const Integer& other) {
    *this = *this * other;
    return *this;
}

Integer Integer::operator/(const Integer& other) const {
    if(other == Integer(0)) {
        throw std::runtime_error("Divide by zero");
    }
    if (this->is_positive_ == other.is_positive_) {
        return this->DivModules(other);
    } else {
        Integer result = this->DivModules(other);
        return -result;
    }
}

Integer& Integer::operator/=(const Integer& other) {
    if(other == Integer(0)) {
        throw std::runtime_error("Divide by zero");
    }
    *this = *this / other;
    return *this;
}

Integer Integer::operator%(const Integer& other) const {
    if(other == Integer(0)) {
        throw std::runtime_error("Divide by zero");
    }
    if (this->is_positive_) {
        return this->ModModules(other);
    } else {
        Integer result = this->ModModules(other);
        return -result;
    }
}

Integer& Integer::operator%=(const Integer& other) {
    *this = *this % other;
    return *this;
}

std::string Integer::TransferString() const {
    std::string line;
    if (!is_positive_) {
        line = "-";
    }
    for (auto i = numbers_.crbegin(); i != numbers_.crend(); ++i) {
        line += std::to_string(*i);
    }
    return line;
}

int8_t Integer::operator[](int index) const{
    if (index >= this->numbers_.size()) {
        return 0;
    } return this->numbers_[index];
}

bool Integer::GreaterModules(const Integer &other) const {
    if (this->Length() == other.Length()) {
            for (int i = this->Length() - 1; i >= 0; --i) {
                if ((*this)[i] != other[i]) {
                    return (*this)[i] > other[i];
                }
            }
        }
    return this->Length() > other.Length();
}
