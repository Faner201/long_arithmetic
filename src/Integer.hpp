#pragma once
#include <vector>
#include <cstdint>
#include <string>
#include <type_traits>


namespace arbitary_precision_arithmetic {
class Integer final {
  private:
    std::vector<int8_t> numbers_;
    bool is_positive_;
    const int base = 10;
    const int shift = 2;
    const int order = 1;
  public:
    Integer();
    Integer(const Integer&);
    Integer(Integer&&); // -__-

    Integer& operator=(const Integer&);
    Integer& operator=(Integer&&);  // -__-

    template<typename T,typename Type = std::enable_if_t<std::is_integral<T>::value>>
    explicit Integer(T);
  
    ~Integer() = default;

    Integer operator-() const;
    Integer& operator--();
    Integer operator--(int);

    Integer operator+() const;
    Integer& operator++();
    Integer operator++(int);

    [[nodiscard]] Integer operator-(const Integer&) const;
    Integer& operator-=(const Integer&);

    [[nodiscard]] Integer operator+(const Integer&) const;
    Integer& operator+=(const Integer&);

    [[nodiscard]] Integer operator*(const Integer&) const;
    Integer& operator*=(const Integer&);

    [[nodiscard]] Integer operator/(const Integer&) const;
    Integer& operator/=(const Integer&);
    
    [[nodiscard]] Integer operator%(const Integer&) const;
    Integer& operator%=(const Integer&);  

    [[nodiscard]] explicit operator bool() const;
    template<typename T, typename Type = std::enable_if_t<std::is_integral<T>::value>>
    [[nodiscard]] explicit operator T() const;
    
    [[nodiscard]] bool operator==(const Integer&) const;
    [[nodiscard]] bool operator!=(const Integer&) const;
    [[nodiscard]] bool operator<(const Integer&) const;
    [[nodiscard]] bool operator<=(const Integer&) const;
    [[nodiscard]] bool operator>(const Integer&) const;
    [[nodiscard]] bool operator>=(const Integer&) const;

    template <typename OStream>
    friend OStream&& operator<<(OStream&&, const Integer&);

    std::size_t Length() const;
    bool Sign();
    std::string TransferString() const;
    int8_t operator[](int) const;
    

    private:
     Integer SumModules(const Integer&) const;
     Integer SubModules(const Integer&) const;
     Integer MulModules(const Integer&) const;
     Integer DivModules(const Integer&) const;
     Integer ModModules(const Integer&) const;
     bool GreaterModules(const Integer&) const;
     std::tuple<Integer, Integer> Devide(const Integer&) const;
  };

  template <typename OStream>
  OStream&& operator<<(OStream&& stream, const Integer& integer) {
    if(!integer.is_positive_) {
      stream << "-";
    }
    for(auto i = integer.numbers_.crbegin(); i != integer.numbers_.crend(); i++) {
      stream << static_cast<int>(*i);
    }
    return stream;
  }
}
