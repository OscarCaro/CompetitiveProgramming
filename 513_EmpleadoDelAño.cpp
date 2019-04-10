#include <iostream>
using namespace std;

int main() {
	int n, input, sumaAnt, aux;
	
	while (cin >> n) {
		sumaAnt = 0;
		for (int i = 1; i < n; i++) {
			cin >> input;
			aux = input * i - sumaAnt;
			cout << aux << " ";
			sumaAnt += aux;
		}
		cin >> input;
		aux = input * n - sumaAnt;
		cout << aux << endl;
	}

	return 0;
}