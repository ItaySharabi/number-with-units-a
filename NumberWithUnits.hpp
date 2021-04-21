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
            NumberWithUnits() {
                // cout << "constructor1()" << endl;
                number = 0;
                unit_type = "Default";
            }; // Empty Constructor
            NumberWithUnits(int num, string u_type) {
                // cout << "constructor2()" << endl;
                number = num;
                unit_type = u_type;
            }; // Construcrtor
            ~NumberWithUnits(){}; // Destructor
            static void read_units(ifstream& stream);
            int getNumber() {return this->number;}
            string getUnitType(){return this->unit_type;}
            void setNumber(int n) {this->number = n;}
            void setUnitType(string unit_type) {this->unit_type = unit_type;}
            
        

            /*========================*/
            //    Unary Operators     //
            /*========================*/
            NumberWithUnits operator+ ();
            NumberWithUnits operator- ();

            NumberWithUnits& operator++ (); // Pre-fix-Increment
            NumberWithUnits& operator-- ();
            NumberWithUnits& operator++ (int); // Post-fix-Increment
            NumberWithUnits& operator-- (int);

            /*========================*/
            //    Binary Operators    //
            /*========================*/

            NumberWithUnits& operator+=(const NumberWithUnits&);
            NumberWithUnits& operator-= (const NumberWithUnits&);

            friend NumberWithUnits operator+ (NumberWithUnits, NumberWithUnits);
            friend NumberWithUnits operator- (NumberWithUnits, NumberWithUnits);
            
            // friend NumberWithUnits operator+= (NumberWithUnits, NumberWithUnits);            
            // friend NumberWithUnits operator-= (NumberWithUnits, NumberWithUnits);

            friend NumberWithUnits operator* (double, NumberWithUnits);
            friend NumberWithUnits operator* (NumberWithUnits, double);

            friend bool operator> (const NumberWithUnits&, const NumberWithUnits&);
            friend bool operator>= (const NumberWithUnits&, const NumberWithUnits&);

            friend bool operator< (const NumberWithUnits&, const NumberWithUnits&);
            friend bool operator<= (const NumberWithUnits&, const NumberWithUnits&);

            friend bool operator== (const NumberWithUnits&, const NumberWithUnits&);
            friend bool operator!= (const NumberWithUnits&, const NumberWithUnits&);

            /*========================*/
            //  friend I/O operators  //
            /*========================*/
            friend ostream& operator<< (ostream&, const NumberWithUnits&);
            friend istream& operator>> (istream&, const NumberWithUnits&);
    };
};

#endif