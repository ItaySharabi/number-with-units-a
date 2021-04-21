#include "NumberWithUnits.hpp"
#include <fstream>
#include <sstream>

namespace ariel{ 

    void NumberWithUnits::read_units(ifstream& stream) {
        cout << "read_units()" << endl;   
    }

    /*--------------------*/
    //   Unary Operators  //
    /*--------------------*/

    NumberWithUnits NumberWithUnits::operator+ () {
        cout << "Unary (+)" << endl;
        return NumberWithUnits();
    }

    NumberWithUnits NumberWithUnits::operator- () {
        cout << "Unary (-)" << endl;
        return NumberWithUnits();
    }

    NumberWithUnits& NumberWithUnits::operator++ () {
        cout << "Unary (++) From the left" << endl;
        setNumber(getNumber()+1);
        return *this;
    }

    NumberWithUnits& NumberWithUnits::operator-- () {
        cout << "Unary (--) From the left" << endl;
        setNumber(getNumber()-1);
        return *this;
    }

    // NumberWithUnits operator++ (NumberWithUnits num1, int a) {
    //     cout << "Unary (++) From the right ? " << endl;
    //     cout << "--------" << "a" << "=" << a << endl;
    //     return NumberWithUnits();
    // }
    NumberWithUnits& NumberWithUnits::operator++ (int a) {
        cout << "Unary (++) From the right ? " << endl;
        // cout << "a = " << a << endl;
        // NumberWithUnits copy = *this;
        // copy.setNumber(getNumb/er()+1);
        setNumber(getNumber()+1);
        return *this;
    }

    NumberWithUnits& NumberWithUnits::operator-- (int a) {
        cout << "Unary (--) From the right ? " << endl;
        // cout << "--------" << "a" << "=" << a << endl;
        setNumber(getNumber()-1);
        return *this;
    }


    /*====================*/
    //  Binary Operators  //
    /*====================*/


    NumberWithUnits operator+ (NumberWithUnits num1, NumberWithUnits num2) {
        cout << "Binary (+)" << endl;
        return NumberWithUnits();
    }

    NumberWithUnits operator-(NumberWithUnits num1, NumberWithUnits num2) {
        cout << "Binary (-)" << endl;
        return NumberWithUnits();
    }

    // This overload is inside the class scope (not a friend func) 
    // and returns a reference to *this, after calculation.
    // By doing so, gain the ability to invoke ((n1 += n2) += n3)
    NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& num) {
        setNumber(num.number + getNumber());
        setUnitType(num.unit_type);
        return *this;
    }

    // This overload is defined as a friend function, 
    // which allows implementations outside of class scope
    // and access to private class members.
    // NumberWithUnits operator+= (NumberWithUnits num1, NumberWithUnits num2) {
    //     cout << "Binary (+=)" << endl;
    //     return NumberWithUnits();
    // }

    NumberWithUnits& NumberWithUnits::operator-= (const NumberWithUnits& num) {
        setNumber(getNumber() - num.number);
        setUnitType(num.unit_type);
        return *this;
    }

    NumberWithUnits operator-=(NumberWithUnits num1, NumberWithUnits num2) {
        cout << "Binary (-=)" << endl;
        return NumberWithUnits();
    }

    // Defined as a friend function to enable 2 arguments which are not of class type.
    // allows operations such as 3*a (while 'a' is of type 'NumberWithUnits').
    NumberWithUnits operator* (double x, NumberWithUnits num) {
        cout << "Binary (*)" << endl;
        NumberWithUnits mult(x * num.getNumber(), num.unit_type);
        return mult;
    }

    NumberWithUnits operator* (NumberWithUnits num, double x) {
        cout << "Binary (*) From the right" << endl;
        return NumberWithUnits();
    }

    bool operator> (const NumberWithUnits& num1, const NumberWithUnits& num2) {
        cout << "Binary (>)" << endl;
        return false;
    }

    bool operator>= (const NumberWithUnits& num1, const NumberWithUnits& num2) {
        cout << "Binary (>=)" << endl;
        return false;
    }

    bool operator< (const NumberWithUnits& num1, const NumberWithUnits& num2) {
        cout << "Binary (<)" << endl;
        return false;
    }

    bool operator<= (const NumberWithUnits& num1, const NumberWithUnits& num2) {
        cout << "Binary (<=)" << endl;
        return false;
    }

    bool operator== (const NumberWithUnits& num1, const NumberWithUnits& num2) {
        cout << "Binary (==)" << endl;
        return false;
    }

    bool operator!= (const NumberWithUnits& num1, const NumberWithUnits& num2) {
        cout << "Binary (!=)" << endl;
        return false;
    }


    // Has to be defined as a friend function inorder to get parameters that are not
    // of class type.
    ostream& operator<< (ostream& cout, const NumberWithUnits& a) {
        // cout << a.getNumber() << "[" << a.getUnitType() << "]";
        cout << a.number << "[" << a.unit_type << "]";
        return cout;
    }

    istream& operator>> (istream& cin, const NumberWithUnits& num) {
        cout << "NumberWithUnits input:...." << endl;
        ostringstream oss;
        

        return cin;
    }  

    
};