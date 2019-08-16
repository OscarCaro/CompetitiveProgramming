#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int numOfCases, n, counter = 0;
	cin >> numOfCases;
	for (int i = 0; i < numOfCases; i++) {
		cin >> n;
		//counter = (n / 5);

		for (int i = 1; i < 14; i++){
			counter += n / pow(5, i);
		}
		cout << counter << endl;
		counter = 0;
	}

	return 0;
}
