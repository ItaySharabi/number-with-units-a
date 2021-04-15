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

    NumberWithUnits NumberWithUnits::operator+ (NumberWithUnits num) {
        cout << "Adding this(" << number << ") + " << num.getNumber() << endl;
        NumberWithUnits add(num.getNumber() + number, num.unit_type);
        return add;
    }

    NumberWithUnits NumberWithUnits::operator- (NumberWithUnits b) {
        cout << number << " - " << b.getNumber() << endl;

        NumberWithUnits sub(number - b.getNumber(), b.unit_type);

        return sub;
    }

    NumberWithUnits NumberWithUnits::operator- () {
        // NumberWithUnits a(-1*number, unit_type);
        return NumberWithUnits(-1*number, unit_type);
    }

    NumberWithUnits NumberWithUnits::operator* (NumberWithUnits num) {
        NumberWithUnits mult(num.number * number, unit_type);
        return mult;
    }

    ostream& operator<< (ostream& cout, NumberWithUnits a) {
        cout << a.number << "[" << a.unit_type << "]";
        return cout;
    }
};