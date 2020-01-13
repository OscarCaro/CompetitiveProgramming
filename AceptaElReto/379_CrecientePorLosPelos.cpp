#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 1000;
typedef int t_list[MAX];

void initializeArray ( t_list list );

int main () {
	t_list list;
	int n; 
	cin >> n;
	while ( n != 0 ) {

		for ( int i = 0; i < n; i++ ) {
			cin >> list[i];
		}
		int pos = n - 1 ;

		while ( pos > 0 && list[pos] != list[pos - 1] ) {
			pos--;
		}
		list[pos]++;
		for ( int i = pos; i < n; i++ ) {
			list[i] = list[pos];
		}

		for ( int i = 0; i < n; i++ ) {
			if ( i == 0 ) {
				cout << list[i];
			}
			else {
				cout << " " << list[i];
			}
		}
		cout << endl;

		cin >> n;
	}

	return 0;
}

void initializeArray ( t_list list ) {
	for ( int i = 0; i < MAX; i++ ) {
		list[i] = 0;
	}
}