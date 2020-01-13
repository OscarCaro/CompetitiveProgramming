#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct {
	bool empty;
	int low;		// Lowest earning for a town that has spent x money (x given by pos in array)
	int high;		// Highest earning for a town that has spent x money (x given by pos in array)
} tCell;

const int MAX = 1000000;

typedef vector<tCell> t_vector;

void initializeArray ( t_vector &list );

int main () {

	t_vector list (MAX);

	int n;
	cin >> n;

	int currPaid, currGain;
	while ( n != 0 ) {
		initializeArray ( list );

		for ( int i = 0; i < n; i++ ) {
			cin >> currPaid >> currGain;

			if ( list[currPaid].empty ) {
				list[currPaid].low = currGain;
				list[currPaid].high = currGain;
				list[currPaid].empty = false;
			}
			else {
				if ( currGain < list[currPaid].low ) {
					list[currPaid].low = currGain;
				}
				if ( currGain > list[currPaid].high ) {
					list[currPaid].high = currGain;
				}
			}

		}

		bool fair = true;
		int prevHigh = list[0].high;
		for ( int i = 1; i < MAX && fair; i++ ) {
			if ( !list[i].empty ) {

				if ( prevHigh >= list[i].low ) {
					fair = false;
				}
				prevHigh = list[i].high;
			}
		}

		if ( fair ) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}

		cin >> n;
	}

	return 0;
}

void initializeArray ( t_vector &list ) {
	for ( int i = 0; i < MAX; i++ ) {
		list[i].empty = true;
	}
}
