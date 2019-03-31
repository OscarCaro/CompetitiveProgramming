#include <vector>
#include <iostream>
using namespace std;

void solucion(int dim);

bool isDiabolic(vector<vector<int>> matriz, int dim, int &CM);
bool addColumn(vector<vector<int>> matriz, int dim, int &colAdd);
bool addRow(vector<vector<int>> matriz, int dim, int &rowAdd);
bool addDiag(vector<vector<int>> matriz, int dim, int &diagAdd);

bool isEsoteric(vector<vector<int>> matriz, vector<bool> miArray, int dim, int CM, int &CM2);
bool cond1(vector<bool> miArray, int dim);
bool cond2(vector<vector<int>> matriz, int dim, int CM2);
bool cond3Odd(vector<vector<int>> matriz, int dim, int CM2);
bool cond4Odd(vector<vector<int>> matriz, int dim, int CM2);
bool cond3Even(vector<vector<int>> matriz, int dim, int CM2);
bool cond4Even(vector<vector<int>> matriz, int dim, int CM2);

int main() {
	int caso;
	cin >> caso;

	while (caso != 0) {
		solucion(caso);

		cin >> caso;
	}
}

void solucion(int dim) {
	vector<vector<int>> matriz(dim, vector<int>(dim));
	vector<bool> miArray(dim*dim);
	int aux, CM, CM2;
	bool isDiab;

	// fill with data
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			cin >> aux;
			matriz[i][j] = aux;
			if (aux >= 1 && aux <= dim * dim) {
				miArray[aux - 1] = true;
			}
		}
	}

	isDiab = isDiabolic(matriz, dim, CM);
	if (!isDiab) {
		cout << "NO" << endl;
	}
	else {
		// is diabolic
		if (!isEsoteric(matriz, miArray, dim, CM, CM2)) {
			cout << "DIABOLICO" << endl;
		}
		else {
			cout << "ESOTERICO" << endl;
		}
	}
}

bool isDiabolic(vector<vector<int>> matriz, int dim, int &CM) {
	bool itIs = false, colOk = false, rowOk = false, diagOk = false;
	int colAdd, rowAdd, diagAdd;
	CM = 0;
	
	if (colOk = addColumn(matriz, dim, colAdd)) {
		if (rowOk = addRow(matriz, dim, rowAdd)) {
			if (diagOk = addDiag(matriz, dim, diagAdd)) {
				if (colAdd == rowAdd && rowAdd == diagAdd) {
					itIs = true;
					CM = colAdd;
				}
			}
		}
	}

	return itIs;
}

bool addColumn(vector<vector<int>> matriz, int dim, int &colAdd) {
	int add = 0, lastAdd = 0, idx = 0;
	bool ok = true;

	while (ok && idx < dim) {
		lastAdd = add;
		add = 0;
		for (int row = 0; row < dim; row++) {
			add += matriz[row][idx];
		}
		if (idx > 0 && lastAdd != add) {
			ok = false;
		}
		idx++;
	}

	colAdd = add;
	return ok;
}

bool addRow(vector<vector<int>> matriz, int dim, int &rowAdd) {
	int add = 0, lastAdd = 0, idx = 0;
	bool ok = true;

	while (ok && idx < dim) {
		lastAdd = add;
		add = 0;
		for (int col = 0; col < dim; col++) {
			add += matriz[idx][col];
		}
		if (idx > 0 && lastAdd != add) {
			ok = false;
		}
		idx++;
	}

	rowAdd = add;
	return ok;
}

bool addDiag(vector<vector<int>> matriz, int dim, int &diagAdd) {
	int diag1 = 0, diag2 = 0;
	bool ok;
	for (int i = 0; i < dim; i++) {
		diag1 += matriz[i][i];
		diag2 += matriz[i][dim - 1 - i];
	}
	ok = (diag1 == diag2);
	diagAdd = diag1;
	return ok;	
}

bool isEsoteric(vector<vector<int>> matriz, vector<bool> miArray, int dim, int CM, int &CM2) {
	bool isEsot = false;
	CM2 = 4 * CM / dim;
	if (cond1(miArray, dim)) {
		if (cond2(matriz, dim, CM2)) {

			if (dim % 2 == 1) {
				// odd
				if (cond3Odd(matriz, dim, CM2)) {
					if (cond4Odd(matriz, dim, CM2)) {
						isEsot = true;
					}
				}
			}
			else {
				// even
				if (cond3Even(matriz, dim, CM2)) {
					if (cond4Even(matriz, dim, CM2)) {
						isEsot = true;
					}
				} 
			}

		}
	}
	return isEsot;
}

bool cond1(vector<bool> miArray, int dim) {
	bool ok = true;
	for (int i = 0; i < dim * dim && ok; i++) {
		if (!miArray[i]) {
			ok = false;
		}
	}
	return ok;
}

bool cond2(vector<vector<int>> matriz, int dim, int CM2) {
	int add = matriz[0][0] + matriz[0][dim - 1] + matriz[dim - 1][0] + matriz[dim - 1][dim - 1];
	return (add == CM2);
}

bool cond3Odd(vector<vector<int>> matriz, int dim, int CM2) {
	int pos = dim / 2;
	int add = matriz[0][pos] + matriz[pos][0] + matriz[dim - 1][pos] + matriz[pos][dim - 1];
	return (add == CM2);
}

bool cond4Odd(vector<vector<int>> matriz, int dim, int CM2) {
	int pos = dim / 2;
	int n = 4 * matriz[pos][pos];
	return (n == CM2);
}

bool cond3Even(vector<vector<int>> matriz, int dim, int CM2) {
	int pos = dim / 2 - 1;
	int add = matriz[0][pos] + matriz[0][pos + 1] + matriz[pos][0] + matriz[pos + 1][0]
		+ matriz[dim - 1][pos] + matriz[dim - 1][pos + 1] + matriz[pos][dim - 1] + matriz[pos + 1][dim - 1];
	return (add == 2 * CM2);
}

bool cond4Even(vector<vector<int>> matriz, int dim, int CM2) {
	int pos = dim / 2 - 1;
	int add = matriz[pos][pos] + matriz[pos][pos + 1] + matriz[pos + 1][pos] + matriz[pos + 1][pos + 1];
	return (add == CM2);
}