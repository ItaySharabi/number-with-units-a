#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
using namespace ariel;


TEST_CASE("TEST 1 -- Boolean operators") {

    /*---------CHECK BOOLEAN OPERATORS-------*/
    //           Grams and Kilograms         //
    /*---------------------------------------*/  
    NumberWithUnits a(5, "kg");
    NumberWithUnits b(500, "g");

    CHECK(a > b); 
    CHECK(a >= b);
    CHECK(a >= a);
    CHECK(b >= b);
    CHECK(a != b);
    CHECK_FALSE(a < b);
    CHECK_FALSE(a <= b);
    CHECK_FALSE(a == b);


    /*---------CHECK BOOLEAN OPERATORS-------*/
    //          Meters and Kilometers        //
    /*---------------------------------------*/  
    a = NumberWithUnits(1000, "m"); // 1000[m]
    b = NumberWithUnits(1, "km");   // 1[km]

    CHECK(a == b);
    CHECK(a != b);
    CHECK(a >= b);
    CHECK(a >= b);
    CHECK(a >= a);
    CHECK(b >= b);
    CHECK_FALSE(a > b);
    CHECK_FALSE(a < b);

    /*---------CHECK BOOLEAN OPERATORS-------*/
    //             Kg's and Hours            //
    //     Throws - unsupported exception    //
    /*---------------------------------------*/ 
    a = NumberWithUnits(5, "kg");
    b = NumberWithUnits(3, "hours");
    bool c;
    CHECK_THROWS(c = (a == b));
    CHECK_THROWS(c = (a != b));
    CHECK_THROWS(c = (a >= b));
    CHECK_THROWS(c = (a <= b));
    CHECK_THROWS(c = (a  > b));
    CHECK_THROWS(c = (a  < b));

    cout << a << endl;

    cout << b << endl;
}


TEST_CASE("TEST 2 -- Binary and Unary Operators") {

    NumberWithUnits a{10, "kg"};
    NumberWithUnits b{10, "kg"};
    NumberWithUnits c{20, "kg"};
    NumberWithUnits d{0, "kg"};
    NumberWithUnits e{0, "g"};

    CHECK((a+b) == c);
    CHECK((a-b) == d);
    CHECK((a-b) == e);

    CHECK(((a += a) += a) == (c += a));
}

TEST_CASE("TEST 3 - I/O Stream operators") {
    
    istringstream check1("10[kg]");
    istringstream check2("330[g]");

    NumberWithUnits a, b;
    
    check1 >> a;
    check2 >> b;


    cout << a << endl; // should print 10[kg]
    cout << b << endl; // shhould print 330[g]

    CHECK(a == NumberWithUnits(10, "kg"));
    CHECK(b == NumberWithUnits(330, "g"));
    bool c;
    CHECK_NOTHROW(c = (a+b == NumberWithUnits(a.getNumber() + b.getNumber(),a.getUnitType())));
    
}