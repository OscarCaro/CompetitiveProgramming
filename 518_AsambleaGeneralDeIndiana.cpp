#include <iostream>
using namespace std;

int main() {
	int day, month;
	bool ok;
	char aux;
	cin >> month >> aux >> day;
	while (month != 0 && day != 0) {
		ok = false;
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day > 0 && day <= 31) {
				ok = true;
			}
		}
		else if(month == 2){
			if (day > 0 && day <= 28) {
				ok = true;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11){
			
				if (day > 0 && day <= 30) {
					ok = true;
				}
		}
		if (ok) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		cin >> month >> aux >> day;
	}


	return 0;
}