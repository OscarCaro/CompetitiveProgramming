// Ejercicio 350 Tri�ngulo de mayor �rea
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	short int a, b;
	cin >> a >> b;
	while(a > 0 || b > 0){
		printf("%.1f\n", a * b / 2.0);
		cin >> a >> b;
	}
	return 0;
}
