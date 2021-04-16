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
            enum Units {
                Miles, Meters, Grams, Time
            };
            NumberWithUnits(); // Empty Constructor
            NumberWithUnits(int number, string unit_type); // Construcrtor
            ~NumberWithUnits(); // Destructor
            static void read_units(ifstream& stream);
            int getNumber() {return this->number;}
            string getUnitType(){return this->unit_type;}
            
        

            /*------------------------*/
            //    Unary Operators     //
            /*------------------------*/
            NumberWithUnits operator+ ();
            NumberWithUnits operator- ();

            NumberWithUnits operator++ ();
            NumberWithUnits operator-- ();
            friend NumberWithUnits operator++ (NumberWithUnits, int);
            friend NumberWithUnits operator-- (NumberWithUnits, int);

            /*------------------------*/
            //    Binary Operators    //
            /*------------------------*/

            friend NumberWithUnits operator+ (NumberWithUnits, NumberWithUnits);
            friend NumberWithUnits operator+= (NumberWithUnits, NumberWithUnits);

            friend NumberWithUnits operator- (NumberWithUnits, NumberWithUnits);
            friend NumberWithUnits operator-= (NumberWithUnits, NumberWithUnits);

            friend NumberWithUnits operator* (double, NumberWithUnits);
            friend NumberWithUnits operator* (NumberWithUnits, double);

            friend bool operator> (NumberWithUnits, NumberWithUnits);
            friend bool operator>= (NumberWithUnits, NumberWithUnits);

            friend bool operator< (NumberWithUnits, NumberWithUnits);
            friend bool operator<= (NumberWithUnits, NumberWithUnits);

            friend bool operator== (NumberWithUnits, NumberWithUnits);
            friend bool operator!= (NumberWithUnits, NumberWithUnits);


            friend ostream& operator<< (ostream&, NumberWithUnits);
            friend istream& operator>> (istream&, NumberWithUnits);
    };
};

#endif