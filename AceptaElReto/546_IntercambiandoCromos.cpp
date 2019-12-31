#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int MAXCARDS = 5000;
typedef enum t_values {none, one, repeated};
typedef t_values t_array[MAXCARDS];

void initializeArray ( t_array &array );


int main () {
	t_array alex, mateo;

	int n;
	cin >> n;

	for ( int i = 0; i < n; i++ ) {
		int numAlex, numMateo, auxCard;

		initializeArray ( alex );
		initializeArray ( mateo );

		cin >> numAlex;
		for ( int j = 0; j < numAlex; j++ ) {
			cin >> auxCard;
			switch ( alex[auxCard - 1] ) {
				case none:
					alex[auxCard - 1] = one;
					break;
				case one:
					alex[auxCard - 1] = repeated;
					break;
				default:
					break;
			}
		}

		cin >> numMateo;
		for ( int j = 0; j < numMateo; j++ ) {
			cin >> auxCard;
			switch ( mateo[auxCard - 1] ) {
				case none:
					mateo[auxCard - 1] = one;
					break;
				case one:
					mateo[auxCard - 1] = repeated;
					break;
				default:
					break;
			}
		}

		bool thereIsPreviousOutput = false;
		for ( int k = 0; k < MAXCARDS; k++ ) {
			if ( alex[k] == repeated && mateo[k] == none ) {
				if ( thereIsPreviousOutput ) {
					cout << " ";
				}
				cout << k + 1;
				thereIsPreviousOutput = true;
			}
		}
		if ( !thereIsPreviousOutput ) {
			cout << "Nada que intercambiar";
		}
		cout << endl;

		thereIsPreviousOutput = false;
		for ( int k = 0; k < MAXCARDS; k++ ) {
			if ( mateo[k] == repeated && alex[k] == none ) {
				if ( thereIsPreviousOutput ) {
					cout << " ";
				}
				cout << k + 1;
				thereIsPreviousOutput = true;
			}
		}
		if ( !thereIsPreviousOutput ) {
			cout << "Nada que intercambiar";
		}
		cout << endl;

	}



	
	return 0;
}

void initializeArray ( t_array &array ) {
	for ( int i = 0; i < MAXCARDS; i++ ) {
		array[i] = none;
	}
}

