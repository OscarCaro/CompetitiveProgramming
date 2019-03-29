//128 Florencia

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int eTamMat, eNumNervios, eDivNervios, eTamBrazo;
	int brazosAHacer, brazosHechosConRestoAnterior, restoAnt, sobraVerd, matUsadoVerd, brazosPorCadaMaterial, matUsadoCompletoEnCasoActual;
	bool posible;

	cin >> eTamMat;
	while (eTamMat != -1) {
		restoAnt = 0;
		sobraVerd = 0;
		matUsadoVerd = 0;

		cin >> eNumNervios;
		posible = true;
		while (eNumNervios != -1 && posible) {
			cin >> eDivNervios >> eTamBrazo;
			if (eTamBrazo > eTamMat) {
				posible = false;
			}
			if (posible) {
				brazosAHacer = eNumNervios * eDivNervios;
				if (restoAnt / eTamBrazo > brazosAHacer) {
					brazosHechosConRestoAnterior = brazosAHacer;
					restoAnt = restoAnt - brazosHechosConRestoAnterior * eTamBrazo;
				}
				else {
					brazosHechosConRestoAnterior = restoAnt / eTamBrazo;
					sobraVerd += restoAnt - eTamBrazo * brazosHechosConRestoAnterior;
					if (restoAnt > 0) {
						matUsadoVerd++;
					}
					brazosAHacer -= brazosHechosConRestoAnterior;
					brazosPorCadaMaterial = eTamMat / eTamBrazo;
					//matUsadoCompletoEnCasoActual = brazosAHacer / brazosPorCadaMaterial;
					if (eTamMat - eTamBrazo * brazosPorCadaMaterial == 0) {
						matUsadoCompletoEnCasoActual = brazosAHacer / brazosPorCadaMaterial;
					}
					else {
						matUsadoCompletoEnCasoActual = ceil(brazosAHacer * 1.0 / brazosPorCadaMaterial) - 1;
					}

					matUsadoVerd += matUsadoCompletoEnCasoActual;
					sobraVerd += matUsadoCompletoEnCasoActual * (eTamMat - eTamBrazo * brazosPorCadaMaterial);
					if (brazosAHacer - brazosPorCadaMaterial * matUsadoCompletoEnCasoActual > 0) {
						restoAnt = eTamMat - (eTamBrazo * (brazosAHacer - brazosPorCadaMaterial * matUsadoCompletoEnCasoActual));
					}
					else {
						restoAnt = 0;
					}
				}
				cin >> eNumNervios;
			}
		}
		if (restoAnt > 0) {
			sobraVerd += restoAnt;
			matUsadoVerd++;
		}
		if (posible) {
			cout << matUsadoVerd << " " << sobraVerd << endl;

		}
		else {
			cin >> eNumNervios;
			while (eNumNervios != -1) {
				cin >> eDivNervios >> eTamBrazo;
				cin >> eNumNervios;
			}
			cout << "IMPOSIBLE" << endl;
		}

		cin >> eTamMat;
	}
	return 0;
}