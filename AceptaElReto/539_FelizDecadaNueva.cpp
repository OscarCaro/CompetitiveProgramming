#include <iostream>
#include <string>
using namespace std;

int main () {
	int year, firstYear;
	
	while ( cin >> firstYear >> year ) {
		if ( (year - firstYear) % 10 == 9 ) {
			cout << "FELIZ DECADA NUEVA" << endl;
		}
		else {
			cout << "TOCA ESPERAR" << endl;
		}
	}
	return 0;
}