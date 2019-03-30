#include <iostream>
using namespace std;

int main() {
	int numOfCases, n1, n2;
	cin >> numOfCases;
	for (int i = 0; i < numOfCases; i++) {
		cin >> n1;
		cin >> n2;
		cout << ((n1 + 1) * n2 + (n2 + 1) * n1) << endl;
	}
	return 0;
}