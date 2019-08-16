#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n != 0) {
		if (n == 1) {
			cout << 1 << endl;
		}
		else if (n % 2 == 0) {
			// par
			cout << n << endl;
		}
		else {
			// impar
			cout << n - 1 << endl;
		}


		cin >> n;
	}

	return 0;
}