#include "NumberWithUnits.hpp"
using namespace ariel;

int main() {

	cout << "Hello, world!" << endl;

    NumberWithUnits a;
    NumberWithUnits b(3, "Km");
    NumberWithUnits c(5, "Mile");

    cout << a << b << c << endl;

    cout << "Trying some operators: " << endl;

    cout << a+b << endl;

	return 0;
}