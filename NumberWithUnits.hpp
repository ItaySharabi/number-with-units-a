#pragma once
#ifndef NUMWITHUNITS
#define NUMWITHUNITS

#include <iostream>
#include <fstream>

using namespace std;

namespace ariel {

    //read_units(units_file);

    class NumberWithUnits {
        private:
            int number;
            string unit_type;
        public:
            NumberWithUnits();
            NumberWithUnits(int number, string unit_type);
            ~NumberWithUnits();
            static void read_units(ifstream& stream);
            int getNumber() {return this->number;}
            
        

            /*------------------------*/
            //    Unary Operators     //
            /*------------------------*/
            NumberWithUnits operator- ();

            /*------------------------*/
            //    Binary Operators    //
            /*------------------------*/

            NumberWithUnits operator+ (NumberWithUnits);
            NumberWithUnits operator- (NumberWithUnits);
            NumberWithUnits operator* (NumberWithUnits);

            friend ostream& operator<< (ostream& cout, NumberWithUnits a);
    };
};

#endif