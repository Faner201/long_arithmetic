#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Integer.cpp"
#include <iostream>
#include <string>

using namespace arbitary_precision_arithmetic;


TEST_CASE("Constructor", "[constructor]") {

    SECTION("Default") {
        Integer digits;

        REQUIRE(digits.Length() == 1);

        REQUIRE(digits.Sign());
    }

    SECTION("Copy") {
        Integer digits;

        Integer digits1(digits);

        REQUIRE(digits1.Length() == 1);

        REQUIRE(digits1.Sign());
    }

    SECTION("Move copy") {
        Integer digits(535);

        Integer digits1(std::move(digits));

        REQUIRE(digits1.Length() == 3);

        REQUIRE(digits1.Sign());
    }
}

TEST_CASE("Assignment", "[assigment]") {

    SECTION("Assignment check") {
        Integer digits;

        Integer digits1(3425);

        digits = digits1;

        REQUIRE(digits1 == digits);
    }

    SECTION("Move assignment") {
        Integer digits;

        Integer digits1(543534);

        digits = std::move(digits1);

        REQUIRE(digits1 != digits);
    }
}

TEST_CASE("Data type constructor", "[constructor]") {

    SECTION("Char") {
        Integer digits_char(std::numeric_limits<char>::max());

        REQUIRE(digits_char.TransferString() == std::to_string(std::numeric_limits<char>::max()));
    }

    SECTION("Unsigned char") {
        Integer digits_unsigned_char(std::numeric_limits<unsigned char>::max());

        REQUIRE(digits_unsigned_char.TransferString() == std::to_string(std::numeric_limits<unsigned char>::max()));
    }

    SECTION("Short") {
        Integer digits_short(std::numeric_limits<short>::max());

        REQUIRE(digits_short.TransferString() == std::to_string(std::numeric_limits<short>::max()));
    }

    SECTION("Unsigned short") {
        Integer digits_short_unsigned(std::numeric_limits<unsigned short>::max());

        REQUIRE(digits_short_unsigned.TransferString() == std::to_string(std::numeric_limits<unsigned short>::max()));
    }

    SECTION("Int") {
        Integer digits_int(std::numeric_limits<int>::max());

        REQUIRE(digits_int.TransferString() == std::to_string(std::numeric_limits<int>::max()));
    }

    SECTION("Unsigned int") {
        Integer digits_int_unsigned(std::numeric_limits<unsigned int>::max());

        REQUIRE(digits_int_unsigned.TransferString() == std::to_string(std::numeric_limits<unsigned int>::max()));
    }

    SECTION("Long") {
        Integer digits_long(std::numeric_limits<long>::max());

        REQUIRE(digits_long.TransferString() == std::to_string(std::numeric_limits<long>::max()));
    }

    SECTION("Unsigned long") {
        Integer digits_long_unsigned(std::numeric_limits<unsigned long>::max());

        REQUIRE(digits_long_unsigned.TransferString() == std::to_string(std::numeric_limits<unsigned long>::max()));
    }

    SECTION("Long long") {
        Integer digits_long_long(std::numeric_limits<long long>::max());

        REQUIRE(digits_long_long.TransferString() == std::to_string(std::numeric_limits<long long>::max()));
    }

    SECTION("Unsigned long long") {
        Integer digits_long_long_unsigned(std::numeric_limits<unsigned long long>::max());

        REQUIRE(digits_long_long_unsigned.TransferString() == std::to_string(std::numeric_limits<unsigned long long>::max()));
    }
}

TEST_CASE("Negation operator", "[operator]") {
    Integer digits(423423);

    digits = -digits;

    REQUIRE_FALSE(digits.Sign());
}

TEST_CASE("Positive operator", "[operator]") {
    Integer digits(4324242231);

    digits = +digits;

    REQUIRE(digits.Sign());
}

TEST_CASE("Prefix decrement", "[decrement]") {
    Integer digits(347457);

    REQUIRE(--digits == Integer(347456));
}

TEST_CASE("Postfix decrement", "[decrement]") {
    Integer digits(3240235);

    REQUIRE(digits-- == digits + Integer(1));
}

TEST_CASE("Prefix increment", "[increment]") {
    Integer digits(2);

    REQUIRE(Integer(3) == ++digits);
}

TEST_CASE("Postfix increment", "[increment]") {
    Integer digits(32472921301);

    REQUIRE(digits++ == digits - Integer(1));
}


TEST_CASE("Output", "[output]") {
    Integer digits(999);

    std::stringstream asy;

    asy << digits;

    REQUIRE(asy.str() == "999");
}

TEST_CASE("Comparison more", "[comparison]") {

    SECTION("Two positive numbers") {
        Integer digits(3242342342312323);

        Integer digits1(324234);

        REQUIRE(digits > digits1);
    }

    SECTION("False two positive numbers") {
        Integer digits(4324234);

        Integer digits1(3244234231);

        REQUIRE_FALSE(digits > digits1);
    }

    SECTION("First positive, second negative") {
        Integer digits(423);

        Integer digits1(-434322);

        REQUIRE(digits > digits1);
    }

    SECTION("Two negative numbers") {
        Integer digits(-462);

        Integer digits1(-423423);

        REQUIRE(digits > digits1);
    }

    SECTION("False two negative numbers") {
        Integer digits(-312412);

        Integer digits1(-423);

        REQUIRE_FALSE(digits > digits1);
    }
}

TEST_CASE("Comparison less", "[comparison]") {

    SECTION("Two positive numbers") {
        Integer digits(3242342342312323);

        Integer digits1(324234);

        REQUIRE(digits1 <  digits);
    }

    SECTION("False two positive numbers") {
        Integer digits(432423);
    
        Integer digits1(432423423);

        REQUIRE_FALSE(digits1 < digits);
    }

    SECTION("First positive, secon negative") {
        Integer digits(3245);

        Integer digits1(-432423);

        REQUIRE(digits1 < digits);
    }

    SECTION("Two negative numbers") {
        Integer digits(-32423);
    
        Integer digits1(-4234235235);

        REQUIRE(digits1 < digits);
    }

    SECTION("False two negative numbers") {
        Integer digits(-4324235235);
    
        Integer digits1(-3242);

        REQUIRE_FALSE(digits1 < digits);
    }
}

TEST_CASE("Comparison greater than or equal to", "[comparison]") {

    SECTION("Two positive numbers") {
        Integer digits(4324525323412343254);

        Integer digits1(42345235);

        REQUIRE(digits >= digits1);

        digits1 = digits;

        REQUIRE(digits >= digits1);
    }

    SECTION("False two positive numbers") {
        Integer digits(423523523);
    
        Integer digits1(5235235235);

        REQUIRE_FALSE(digits >= digits1);
    }

    SECTION("First positive, second negative") {
        Integer digits(34235235);
    
        Integer digits1(-43242);

        REQUIRE(digits >= digits1);
    }

    SECTION("Two negative numbers") {
        Integer digits(-42352);

        Integer digirts1(-4234325235);

        REQUIRE(digits >= digirts1);
    }

    SECTION("False two negative numbers") {
        Integer digits(-423523523);

        Integer digits1(-423432);

        REQUIRE_FALSE(digits >= digits1);
    }
}

TEST_CASE("Comparison of less than or equal to", "[comparison]") {

    SECTION("Two positive numbers") {
        Integer digits(5434423423422352392);

        Integer digits1(432423425823026);

        REQUIRE(digits1 <= digits);

        digits = digits1;

        REQUIRE(digits1 <= digits);
    }

    SECTION("False two positive numbers") {
        Integer digits(35235235);

        Integer digits1(5235235236523);

        REQUIRE_FALSE(digits1 <= digits);
    }

    SECTION("First positive, second negative") {
        Integer digits(35253252);
    
        Integer digits1(-42342);

        REQUIRE(digits1 <= digits);
    }

    SECTION("Two numbers negative") {
        Integer digits(-241241);

        Integer digits1(-423523523);

        REQUIRE(digits1 <= digits);
    }

    SECTION("False two negative numbers") {
        Integer digits(-532532532);

        Integer digits1(-423523);

        REQUIRE_FALSE(digits1 <= digits);
    }
}

TEST_CASE("The comparison does not equal", "[comparison]") {

    SECTION("True") {
        Integer digits(353);

        Integer digits1(435);

        REQUIRE(digits != digits1);
    }

    SECTION("False") {
        Integer digits(352);

        Integer digits1(digits);

        REQUIRE_FALSE(digits != digits1);
    }
}

TEST_CASE("Sum", "[sum]") {

    SECTION("Two positive numbers") {
        Integer digits(999);

        Integer digits1(5);

        REQUIRE((digits1 + digits) == Integer(1004));
    }

    SECTION("First negative, second positive") {
        Integer digits(-53);

        Integer digits1(50);

        REQUIRE(digits + digits1 == Integer(-3));
    }

    SECTION("First negative, second positive") {
        Integer digits(40);

        Integer digits1(-60);

        REQUIRE(digits + digits1 == Integer(-20));
    }

    SECTION("First negative number the second place is zero") {
        Integer digits(42);

        Integer digits1(-42);

        REQUIRE(digits + digits1 == Integer(0));
    }

    SECTION("Two negative numbers") {
        Integer digits(-423);

        Integer digits1(-4);

        REQUIRE(digits + digits1 == Integer(-427));
    }

    SECTION("Positive number with zero") {
        Integer digits;

        Integer digits1(523);

        REQUIRE(digits + digits1 == digits1);
    }

    SECTION("Negative number with zero") {
        Integer digits;
    
        Integer digits1(-4324);

        REQUIRE(digits + digits1 == digits1);
    }
}

TEST_CASE("Sub", "[sub]") {

    SECTION("Two positive numbers with a negative result") {
        Integer digits(256);

        Integer digits1(260);

        REQUIRE(digits - digits1 == Integer(-4));
    }

    SECTION("Two positive numbers with a positive result") {
        Integer digits(532);

        Integer digits1(32);

        REQUIRE(digits - digits1 == Integer(500));
    }

    SECTION("First negative, second positive") {
        Integer digits(-52);

        Integer digits1(50);

        REQUIRE(digits - digits1 == Integer(-102));
    }

    SECTION("First positive, second negative") {
        Integer digits(50);

        Integer digits1(-102);

        REQUIRE(digits - digits1 == Integer(152));
    }

    SECTION("Positive number from zero") {
        Integer digits;

        Integer digits1(50);

        REQUIRE(digits - digits1 == Integer(-50));
    }

    SECTION("Negative number from zero") {
        Integer digits;
    
        Integer digits1(-50);

        REQUIRE(digits - digits1 == Integer(50));
    }
}

TEST_CASE("Sum or equal to", "[sum or equal]") {

    SECTION("Two positive numbers") {
        Integer digits(1);

        Integer digits1(50);

        REQUIRE((digits += digits1) == Integer(51));
    }

    SECTION("First negative, second positive") {
        Integer digits(-4);

        Integer digits1(50);

        REQUIRE((digits += digits1) == Integer(46));
    }

    SECTION("First negative, second positive") {
        Integer digits(-4);

        Integer digits1(50);

        REQUIRE((digits += digits1) == Integer(46));        
    }
    
    SECTION("Two negative numbers") {
        Integer digits(-502);

        Integer digits1(-3);

        REQUIRE((digits += digits1) == Integer(-505));
    }

    SECTION("Positive number from zero") {
        Integer digits;

        Integer digits1(5);

        REQUIRE((digits += digits1) == Integer(5));
    }

    SECTION("Negative number from zero") {
        Integer digits;

        Integer digits1(-4);

        REQUIRE((digits += digits1) == Integer(-4));
    }
}

TEST_CASE("Difference or equal", "[difference or equal]") {

    SECTION("Two positive numbers") {
        Integer digits(1);

        Integer digits1(50);

        REQUIRE((digits -= digits1) == Integer(-49));
    }

    SECTION("First negative, second positive") {
        Integer digits(-4);

        Integer digits1(50);

        REQUIRE((digits -= digits1) == Integer(-54));
    }

    SECTION("Two negative numbers") {
        Integer digits(-502);

        Integer digits1(-3);

        REQUIRE((digits -= digits1) == Integer(-499));
    }

    SECTION("Positive number fom zero") {
        Integer digits;

        Integer digits1(5);

        REQUIRE((digits -= digits1) == Integer(-5));
    }

    SECTION("Negative number from zero") {
        Integer digits;

        Integer digits1(-4);

        REQUIRE((digits -= digits1) == Integer(4));
    }
}

TEST_CASE("Converting to data type", "[converting]") {

    SECTION("Char") {
        char i = 123;

        Integer digits(i);

        REQUIRE((char)digits == i);
    }

    SECTION("Max size char") {
        Integer digits(53453453);

        REQUIRE((char)digits == std::numeric_limits<char>::max());
    }

    SECTION("Unsigned char") {
        unsigned char i = 123;
    
        Integer digits(i);

        REQUIRE((unsigned char)digits == i);
    }

    SECTION("Max size unsigned char") {
        Integer digits(53453453);

        REQUIRE((unsigned char)digits == std::numeric_limits<unsigned char>::max());
    }

    SECTION("Short") {
        short i = 52;

        Integer digits(i);

        REQUIRE((short)digits == i);
    }

    SECTION("Max size short") {
        Integer digits(534534324253);

        REQUIRE((short)digits == std::numeric_limits<short>::max());
    }

    SECTION("Unsigned short") {
        unsigned short i = 5842;

        Integer digits(i);

        REQUIRE((unsigned short)digits == i);
    }

    SECTION("Max size unsigned short") {
        Integer digits(534542343453);

        REQUIRE((unsigned short)digits == std::numeric_limits<unsigned short>::max());
    }

    SECTION("Int") {
        int i = 52324;

        Integer digits(i);

        REQUIRE((int)digits == i);
    }

    SECTION("Max size int") {
        Integer digits(534432453454323);

        REQUIRE((int)digits == std::numeric_limits<int>::max());
    }

    SECTION("Unsigned int") {
        unsigned int i = 52;

        Integer digits(i);

        REQUIRE((unsigned int)digits == i);
    }

    SECTION("Max size unsigned int") {
        Integer digits(234234324325232342);

        REQUIRE((unsigned int)digits == std::numeric_limits<unsigned int>::max());
    }

    SECTION("Long") {
        long i = 5423452;

        Integer digits(i);

        REQUIRE((long)digits == i);
    }

    SECTION("Max size long") {
        Integer digits(std::numeric_limits<long long>::max());

        REQUIRE((long)digits == std::numeric_limits<long>::max());
    }

    SECTION("Unsigned long") {
        unsigned long i = 5452433424452;

        Integer digits(i);

        REQUIRE((unsigned long)digits == i);
    }

    SECTION("Max size unsigned long") {
        Integer digits(std::numeric_limits<unsigned long>::max());

        REQUIRE((unsigned long)digits == std::numeric_limits<unsigned long>::max());
    }

    SECTION("Long long") {
        long long i = 54235242333452;

        Integer digits(i);

        REQUIRE((long long)digits == i);
    }

    SECTION("Max size long long") {
        Integer digits(std::numeric_limits<long long>::max());

        REQUIRE((long long)digits == std::numeric_limits<long long>::max());
    }

    SECTION("Unsigned long long") {
        unsigned long long i = 542432562453452;

        Integer digits(i);

        REQUIRE((unsigned long long)digits == i);
    }

    SECTION("Max size unsigned long long") {
        Integer digits(std::numeric_limits<unsigned long long>::max());

        REQUIRE((unsigned long long)digits == std::numeric_limits<unsigned long long>::max());
    }
}

TEST_CASE("Multiplication", "[mul]"){

    SECTION("Two positive numbers") {
        Integer digits(5);

        Integer digits1(20);

        REQUIRE(digits * digits1 == Integer(100));
    }

    SECTION("First positive, second negative") {
        Integer digits(20);

        Integer digits1(-10);

        REQUIRE(digits * digits1 == Integer(-200));
    }

    SECTION("First negative, second positive") {
        Integer digits(-4);

        Integer digits1(20);

        REQUIRE(digits * digits1 == Integer(-80));
    }

    SECTION("Two negative numbers") {
        Integer digits(-3); 

        Integer digits1(-5);

        REQUIRE(digits * digits1 == Integer(15));
    }

    SECTION("Positive number by one") {
        Integer digits(1);

        Integer digits1(5);

        REQUIRE(digits * digits1 == Integer(5));
    }

    SECTION("Negative number by one") {
        Integer digits(1);

        Integer digits1(-15);

        REQUIRE(digits * digits1 == Integer(-15));
    }

    SECTION("Positive number by zero") {
        Integer digits;

        Integer digits1(5);

        REQUIRE(digits * digits1 == Integer(0));
    }

    SECTION("Negative number by zero") {
        Integer digits;

        Integer digits1(-235);

        REQUIRE(digits * digits1 == Integer(0));
    }
}

TEST_CASE("Multiplication combined with assignment", "[mult]") {

    SECTION("Two positive numbers") {
        Integer digits(25);

        Integer digits1(10);

        REQUIRE((digits *= digits1) == Integer(250));
    }

    SECTION("First positive, second negative") {
        Integer digits(50);

        Integer digits1(-10);

        REQUIRE((digits *= digits1) == Integer(-500));
    }

    SECTION("First negative, second positive") {
        Integer digits(-2);

        Integer digits1(50);

        REQUIRE((digits *= digits1) == Integer(-100));
    }

    SECTION("Two numbers negative") {
        Integer digits(-5);

        Integer digits1(-20);

        REQUIRE((digits *= digits1) == Integer(100));
    }

    SECTION("Positive number by one") {
        Integer digits(1);

        Integer digits1(20);

        REQUIRE((digits *= digits1) == Integer(20));
    }

    SECTION("Negative number by one") {
        Integer digits(1);

        Integer digits1(-20);

        REQUIRE((digits *= digits1) == Integer(-20));
    }

    SECTION("Positive number by zero") {
        Integer digits;

        Integer digits1(20);

        REQUIRE((digits *= digits1) == Integer(0));
    }

    SECTION("Negativenumber by zero") {
        Integer digits;

        Integer digits1(-20);

        REQUIRE((digits *= digits1) == Integer(0));
    }
}

TEST_CASE("Division", "[div]") {

    SECTION("Two positive numbers") {
        Integer digits(5);

        Integer digits1(2);

        REQUIRE(digits / digits1 == Integer(2));
    }

    SECTION("First positive, second negative") {
        Integer digits(20);

        Integer digits1(-5);

        REQUIRE(digits / digits1 == Integer(-4));
    }

    SECTION("First negative, second positive") {
        Integer digits(-20);

        Integer digits1(5);

        REQUIRE(digits / digits1 == Integer(-4));
    }

    SECTION("Two negative numbers") {
        Integer digits(-4);

        Integer digits1(-4);

        REQUIRE(digits / digits1 == Integer(1));
    }

    SECTION("Positive number by one") {
        Integer digits(5);

        REQUIRE(digits / Integer(1) == digits);
    }

    SECTION("Negative number by one") {
        Integer digits(-55);

        REQUIRE(digits / Integer(1) == digits);
    }

    SECTION("One by a positive number") {
        Integer digits(423);

        REQUIRE(Integer(1) / digits == Integer(0));
    }

    SECTION("One by a negative number") {
        Integer digits(-423);

        REQUIRE(Integer(1) / digits == Integer(0));
    }

    SECTION("One by one") {
        REQUIRE(Integer(1) / Integer(1) == Integer(1));
    }

    SECTION("Positive number by zero]") {
        Integer digits(4234);

        Integer digits1;

        REQUIRE_THROWS_WITH(digits / digits1, "Divide by zero");
    }

    SECTION("Negative number by zero") {
        Integer digits(-4234);

        Integer digits1;

        REQUIRE_THROWS_WITH(digits / digits1, "Divide by zero");
    }

    SECTION("Zero by a positive number") {
        Integer digits;

        Integer digits1(53453);

        REQUIRE(digits / digits1 == Integer(0));
    }

    SECTION("Zero by a negative number") {
        Integer digits;

        Integer digits1(-53453);

        REQUIRE(digits / digits1 == Integer(0));
    }
}

TEST_CASE("Division combined with assignment", "[div]") {

    SECTION("TWo positive numbers") {
        Integer digits(5);

        Integer digits1(2);

        REQUIRE((digits /= digits1) == Integer(2));
    }

    SECTION("First positive, second negative") {
        Integer digits(20);

        Integer digits1(-5);

        REQUIRE((digits /= digits1) == Integer(-4));
    }

    SECTION("First negative, second positive") {
        Integer digits(-20);

        Integer digits1(5);

        REQUIRE((digits /= digits1) == Integer(-4));
    }

    SECTION("TWo numbers negative") {
        Integer digits(-20);

        Integer digits1(-5);

        REQUIRE((digits /= digits1) == Integer(4));
    }

    SECTION("Positive number by one") {
        Integer digits(5);

        REQUIRE((digits /= Integer(1)) == digits);
    }

    SECTION("Negative number by one") {
        Integer digits(-5);

        REQUIRE((digits /= Integer(1)) == digits);
    }

    SECTION("One by a positive number") {
        Integer digits(5);

        REQUIRE((Integer(1) /= digits) == Integer(0));
    }

    SECTION("One by a negative number") {
        Integer digits(-5);

        REQUIRE((Integer(1) /= digits) == Integer(0));
    }

    SECTION("One by a one") {
        REQUIRE((Integer(1) /= Integer(1)) == Integer(1));
    }

    SECTION("Positive number by zero") {
        Integer digits(4234);

        Integer digits1;

        REQUIRE_THROWS_WITH(digits /= digits1, "Divide by zero");
    }

    SECTION("Negatinve number by zero") {
        Integer digits(-4234);

        Integer digits1;

        REQUIRE_THROWS_WITH(digits /= digits1, "Divide by zero");
    }

    SECTION("Zero by a positive number") {
        Integer digits;

        Integer digits1(53453);

        REQUIRE((digits /= digits1) == Integer(0));
    }

    SECTION("Zero by a negative number") {
        Integer digits;

        Integer digits1(-53453);

        REQUIRE((digits /= digits1) == Integer(0));
    }
}

TEST_CASE("Calculation of the remainder of division", "[mod]") {

    SECTION("Two positive numbers") {
        Integer digits(5);

        Integer digits1(2);

        REQUIRE(digits % digits1 == Integer(1));
    }

    SECTION("First positive, second negative") {
        Integer digits(5);

        Integer digits1(-2);

        REQUIRE(digits % digits1 == Integer(1));
    }

    SECTION("First negative, second positive") {
        Integer digits(-5);

        Integer digits1(2);

        REQUIRE(digits % digits1 == Integer(-1));
    }

    SECTION("Two negative numbers") {
        Integer digits(-5);

        Integer digits1(-2);

        REQUIRE(digits % digits1 == Integer(-1));
    }

    SECTION("Positive number by one") {
        Integer digits(5);

        REQUIRE(digits % Integer(1) == Integer(0));
    }

    SECTION("Negative number by one") {
        Integer digits(-55);

        REQUIRE(digits % Integer(1) == Integer(0));
    }

    SECTION("One by a positive number") {
        Integer digits(423);

        REQUIRE(Integer(1) % digits == Integer(1));
    }

    SECTION("One by a negative number") {
        Integer digits(-423);

        REQUIRE(Integer(1) % digits == Integer(1));
    }

    SECTION("One by one") {
        REQUIRE(Integer(1) % Integer(1) == Integer(0));
    }

    SECTION("Positive number by zero") {
        Integer digits(4234);

        Integer digits1;

        REQUIRE_THROWS_WITH(digits % digits1, "Divide by zero");
    }

    SECTION("Negative number by zero") {
        Integer digits(-4234);

        Integer digits1;

        REQUIRE_THROWS_WITH(digits % digits1, "Divide by zero");
    }

    SECTION("Zero by a positive number") {
        Integer digits;

        Integer digits1(53453);

        REQUIRE(digits % digits1 == Integer(0));
    }

    SECTION("Zero by a negative number") {
        Integer digits;

        Integer digits1(-53453);

        REQUIRE(digits % digits1 == Integer(0));
    }
}

TEST_CASE("Calculation of the remainder of division, combined with assignment", "[mod]") {
    
    SECTION("Two positive number") {
        Integer digits(5);

        Integer digits1(2);

        REQUIRE((digits %= digits1) == Integer(1));
    }

    SECTION("First positive, second negative") {
        Integer digits(20);

        Integer digits1(-5);

        REQUIRE((digits %= digits1) == Integer(0));
    }

    SECTION("First negative, second positive") {
        Integer digits(-20);

        Integer digits1(5);

        REQUIRE((digits %= digits1) == Integer(0));
    }

    SECTION("Two numbers negative") {
        Integer digits(-20);

        Integer digits1(-5);

        REQUIRE((digits %= digits1) == Integer(0));
    }

    SECTION("Positive number by one") {
        Integer digits(5);

        REQUIRE((digits %= Integer(1)) == Integer(0));
    }

    SECTION("Negative number by one]") {
        Integer digits(-5);

        REQUIRE((digits %= Integer(1)) == Integer(0));
    }

    SECTION("One by a positive number") {
        Integer digits(5);

        REQUIRE((Integer(1) %= digits) == Integer(1));
    }

    SECTION("One by a negative number") {
        Integer digits(-5);

        REQUIRE((Integer(1) %= digits) == Integer(1));
    }

    SECTION("One by one") {
        REQUIRE((Integer(1) %= Integer(1)) == Integer(0));
    }

    SECTION("Positive number by zero") {
        Integer digits(4234);

        Integer digits1;

        REQUIRE_THROWS_WITH(digits %= digits1, "Divide by zero");
    }

    SECTION("Negative number by zero") {
        Integer digits(-4234);

        Integer digits1;

        REQUIRE_THROWS_WITH(digits %= digits1, "Divide by zero");
    }

    SECTION("Zero by a positive number") {
        Integer digits;

        Integer digits1(53453);

        REQUIRE((digits %= digits1) == Integer(0));
    }

    SECTION("Zero by a negative number") {
        Integer digits;

        Integer digits1(53453);

        REQUIRE((digits %= digits1) == Integer(0));
    }
}
