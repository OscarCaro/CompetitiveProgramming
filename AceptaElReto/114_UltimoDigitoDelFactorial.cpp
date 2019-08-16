#include <iostream>
using namespace std;

int main() {
	int numOfCases, n, totalNum = 1, lastDigit;
	cin >> numOfCases;
	for (int j = 0; j < numOfCases; j++) {
		cin >> n;
		switch (n) {
		case 0:
			cout << '1' << endl;
			break;
		case 1:
			cout << '1' << endl;
			break;
		case 2:
			cout << '2' << endl;
			break;
		case 3:
			cout << '6' << endl;
			break;
		case 4:
			cout << '4' << endl;
			break;
		default:
			cout << '0' << endl;
		}
	}
	return 0;
}
