// 525 Multas desde el cielo

#include <iostream>
using namespace std;

int main () {
	
	int Ncasos;

	cin >> Ncasos;

	for ( int i = 0; i < Ncasos; i++ ) {

		int a, b, c, d, aux;
		cin >> a >> b >> c >> d;

		if ( a > b ) {
			aux = a;
			a = b;
			b = aux;
		}
		if ( c > d ) {
			aux = c;
			c = d;
			d = aux;
		}

		if ( c < a && d > a ) {
			cout << "SOLAPADOS" << endl;
		}
		else if ( c == a && d > a) {
			cout << "SOLAPADOS" << endl;
		} 
		else if ( (a < c && c < b) && d > a ) {
			cout << "SOLAPADOS" << endl;
		}
		else {
			cout << "SEPARADOS" << endl;
		}


	}
	
	return 0;
}
