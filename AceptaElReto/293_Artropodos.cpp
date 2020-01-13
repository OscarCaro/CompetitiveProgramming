#include <iostream>

using namespace std;


int main () {
	int n;
	int ins, arac, crus, esc, ringsPerEsc;
	cin >> n;
	for ( int  i = 0; i < n; i++ ) {
		cin >> ins >> arac >> crus >> esc >> ringsPerEsc;
		cout << ins * 6 + arac * 8 + crus * 10 + esc * (ringsPerEsc * 2) << endl;
	}

	return 0;
}




