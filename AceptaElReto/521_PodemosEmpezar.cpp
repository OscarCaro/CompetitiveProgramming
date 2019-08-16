// 521 ¿Podemos Empezar?

#include <iostream>
#include <cmath>
using namespace std;

typedef bool tMatrix[26][30];

int main () {
	int pisos, letras, asistentes;
	int auxCol, auxRow;
	char auxRowChar;
	int counter;
	
	tMatrix matrix;	

	cin >> pisos >> letras >> asistentes;
	while ( pisos != 0 || letras != 0 || asistentes != 0 ) {

		for ( int i = 0; i < 26; i++ ) {
			for ( int j = 0; j < 30; j++ ) {
				matrix[i][j] = false;
			}
		}

		counter = 0;

		for ( int i = 0; i < asistentes; i++ ) {
			cin >> auxCol >> auxRowChar;
			if ( counter < round ( (pisos * letras) / 2.0 ) ) {
				auxRow = auxRowChar - 'A';

				if ( matrix[auxRow][auxCol] == false ) {
					matrix[auxRow][auxCol] = true;
					counter++;
				}
			}
			
		}

		if ( counter >= round ( (pisos * letras) / 2.0 ) ) {
			cout << "EMPEZAMOS" << endl;
		}
		else {
			cout << "ESPERAMOS" << endl;
		}

		cin >> pisos >> letras >> asistentes;

	}
	
	return 0;
}
