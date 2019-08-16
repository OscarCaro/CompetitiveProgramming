#include <iostream>
using namespace std;

int main() {
	int n;
	long long int aux;
	unsigned long long int total;

	cin >> n;
	while (n != 0) {
		total = 0;
		for (int i = 0; i < n; i++) {
			cin >> aux;
			total += aux;
		}
		cout << total << endl;
		cin >> n;
	}
	


	return 0;
}
