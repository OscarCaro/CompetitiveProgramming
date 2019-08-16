//481 Ajedrez asistido por computador
#include <iostream>
#include <cstdio>
using namespace std;


int main(){
	int fila, columna;
	char filaCh;
	scanf("%i",&fila);
	scanf("%i",&columna);
	while (fila != 0 || columna != 0){
		filaCh = char(int(char('a')) + 8 - fila);
		printf("%c", filaCh);
		printf("%i\n", columna);
		scanf("%i",&fila);
		scanf("%i",&columna);
	}
	return 0;
}
