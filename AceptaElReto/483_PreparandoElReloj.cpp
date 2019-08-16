//483 Preparando el reloj
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int calcularSeg(int, int, int);
int main(){
	int hI, mI, sI, totalI;
	int hF, mF, sF, totalF;
	int hR, mR, sR;
	int n, total, caso, diferencia;
	char aux;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> hI >> aux >> mI >> aux >> sI;
		cin >> hF >> aux >> mF >> aux >> sF;
		cin >> total >> caso;
		totalI = calcularSeg(hI, mI, sI);
		totalF = calcularSeg(hF, mF, sF);
		diferencia = totalF - totalI;

		if (diferencia < 0){
			diferencia = totalF + 86400 - totalI;
		}
		diferencia += diferencia / (total - 1);
		totalI += diferencia / total * (caso - 1);

		//pasar a h m s

		if (totalI >= 86400) {
			totalI -= 86400;
		}
		hR = totalI / 3600;
		totalI -= hR * 3600;

		mR = totalI / 60;
		totalI -= mR * 60;

		sR = totalI;
		cout  << setfill('0') << setw(2)<< hR << ":" << setfill('0') << setw(2)<< mR << ":" << setfill('0') << setw(2)<< sR << endl;
	}

	return 0;
}
int calcularSeg(int h, int m, int s){
	return s + m * 60 + h * 3600;
}
