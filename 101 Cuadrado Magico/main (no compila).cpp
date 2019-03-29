#include <iostream>
#include <vector>

using namespace std;

int main() {
	int d, aux;
	int sumaFila, sumaColumna, sumaDiagonal, sumaEsquinas, sumaCentroLateral,  sumaCentroLateralPar, sumaCentro;
	int CM, CM2;
	bool ok;

	cin >> d;
	while (d != 0) {
		vector<vector<int>> matriz(d, vector<int>(d));

		vector<bool> miArray(d*d);

		sumaFila = 0;
		sumaColumna = 0;
		sumaDiagonal = 0;
		sumaEsquinas = 0;
		ok = true;

		for (int i = 0; i < d; i++) {
			for (int j = 0; j < d; j++) {
				cin >> aux;
				matriz[i][j] = aux;
				miArray[aux - 1] = true;
			}
		}

		for (int i = 0; i < d; i++) {
			sumaFila += matriz[0][d];
			sumaColumna += matriz[d][0];
			sumaDiagonal += matriz[d][d];
		}

		if (sumaFila == sumaColumna && sumaColumna == sumaDiagonal) {
			CM = sumaFila;
			// es diabolico

			//cond 1:
			int i = 0;
			while (ok && i < d*d) {
				if (!miArray[i]) {
					ok = false;
				}
				i++;
			}
			if (ok) {
				//cond 1 bien

				//cond 2:
				sumaEsquinas = matriz[0][0] + matriz[0][d] + matriz[d][0] + matriz[d][d];
				if (sumaEsquinas == ((4 * CM) / d)) {
					CM2 = sumaEsquinas;

					//cond 2 bien

					//cond 3:

					if (d % 2 == 0) {
						//par

						//cond 3:
						aux = d / 2;
						sumaCentroLateralPar = matriz[0][aux] + matriz[0][aux + 1] + matriz[aux][0] + matriz[aux + 1][0] +
							matriz[d][aux] + matriz[d][aux + 1] + matriz[aux][d] + matriz[aux + 1][d];
						if (sumaCentroLateralPar == 2 * CM2) {
							//cond 3 bien
							sumaCentro = matriz[aux][aux] + matriz[aux][aux + 1] + matriz[aux + 1][aux] + matriz[aux + 1][aux + 1];

							// esoterico
							cout << "ESOTERICO" << endl;
						}
						else {
							cout << "DIABOLICO" << endl;
						}

					}
					else {
						//impar

						//cond 3
						aux = d / 2 + 1;
						sumaCentroLateral = matriz[0][aux] + matriz[aux][0] + matriz[d][aux] + matriz[aux][d];
						if (sumaCentroLateral == CM * 2) {
							//cond 3 bien

							//cond 4:
							if (matriz[aux][aux] == 4 * CM2) {
								//cond 4 bien

								//Es esoterico
								cout << "ESOTERICO" << endl;

							}
						}
						else {
							cout << "DIABOLICO" << endl;
						}

					}
				}
				else {
					cout << "DIABOLICO" << endl;
				}
			}
			else {
				cout << "DIABOLICO" << endl;
			}

		}
		else {
			cout << "NO" << endl;
		}


		cin >> d;
	}

	return 0;
}
	