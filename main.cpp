#include "NumberWithUnits.hpp"
#include <fstream>
#include <sstream>
using namespace ariel;

int main() {

	cout << "Hello, world!" << endl;

    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a;
    NumberWithUnits b(3, "Km");
    NumberWithUnits c(5, "Mile");

    cout << a << b << c << endl;

    cout << "Trying some operators: " << endl;

    istringstream check_is_stream("5 Kg");

    cout << check_is_stream.str() << endl;

    check_is_stream >> b;
    

    cout << "b = " << b << ", check_is = " << check_is_stream.str() << endl;
	return 0;
}