#include "NumberWithUnits.hpp"

namespace ariel{ 
    
    NumberWithUnits::NumberWithUnits() {
        cout << "constructor1()" << endl;
        number = 0;
        unit_type = "Default";
    }
    
    NumberWithUnits::NumberWithUnits(int num, string u_type) {
        cout << "constructor2()" << endl;
        number = num;
        unit_type = u_type;
    }

    NumberWithUnits::~NumberWithUnits() {
        // cout << "Destructor()" << endl;
    }

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

    NumberWithUnits NumberWithUnits::operator++ () {
        cout << "Unary (++) From the left" << endl;
        return NumberWithUnits();
    }

    NumberWithUnits NumberWithUnits::operator-- () {
        cout << "Unary (--) From the left" << endl;
        return NumberWithUnits();
    }

    NumberWithUnits operator++ (NumberWithUnits num1, int a) {
        cout << "Unary (++) From the right ? " << endl;
        cout << "--------" << "a" << "=" << a << endl;
        return NumberWithUnits();
    }

    NumberWithUnits operator-- (NumberWithUnits num1, int a) {
        cout << "Unary (--) From the right ? " << endl;
        cout << "--------" << "a" << "=" << a << endl;
        return NumberWithUnits();
    }


    /*--------------------*/
    //  Binary Operators  //
    /*--------------------*/


    NumberWithUnits operator+ (NumberWithUnits num1, NumberWithUnits num2) {
        cout << "Binary (+)" << endl;
        return NumberWithUnits();
    }

    NumberWithUnits operator-(NumberWithUnits num1, NumberWithUnits num2) {
        cout << "Binary (-)" << endl;
        return NumberWithUnits();
    }

    NumberWithUnits operator+= (NumberWithUnits num1, NumberWithUnits num2) {
        cout << "Binary (+=)" << endl;
        return NumberWithUnits();
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

    bool operator> (NumberWithUnits num1, NumberWithUnits num2) {
        cout << "Binary (>)" << endl;
        return false;
    }

    bool operator>= (NumberWithUnits num1, NumberWithUnits num2) {
        cout << "Binary (>=)" << endl;
        return false;
    }

    bool operator< (NumberWithUnits num1, NumberWithUnits num2) {
        cout << "Binary (<)" << endl;
        return false;
    }

    bool operator<= (NumberWithUnits num1, NumberWithUnits num2) {
        cout << "Binary (<=)" << endl;
        return false;
    }

    bool operator== (NumberWithUnits num1, NumberWithUnits num2) {
        cout << "Binary (==)" << endl;
        return false;
    }

    bool operator!= (NumberWithUnits num1, NumberWithUnits num2) {
        cout << "Binary (!=)" << endl;
        return false;
    }


    // Has to be defined as a friend function inorder to get parameters that are not
    // of class type.
    ostream& operator<< (ostream& cout, NumberWithUnits a) {
        cout << a.number << "[" << a.unit_type << "]";
        return cout;
    }

    istream& operator>> (istream& cin, NumberWithUnits num) {
        cout << "NumberWithUnits input:...." << endl;
        return cin;
    }  

    
};