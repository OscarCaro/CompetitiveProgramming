#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, consultas, a, b, sol, aux;
	cin >> n;
	while (n != 0) {
		vector<int> sum(n);
		//Cargar datos
		cin >> aux;
		sum[0] = aux;
		for (int i = 1; i < n; i++) {
			cin >> aux;
			sum[i] = sum[i - 1] + aux;
		}
		cin >> consultas;
		for (int i = 0; i < consultas; i++) {
			//consulta
			cin >> a;
			cin >> b;
			if (a > 1) {
				sol = sum[b - 1] - sum[a - 2];
			}
			else {
				sol = sum[b - 1];
			}
			
			cout << sol << endl;
		}
		cin >> n;
	}
	return 0;
}