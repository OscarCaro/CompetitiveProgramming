//485 Senda Pirenaica
#include <cstdio>
using namespace std;
const int size = 100;
typedef int t_array [size];
int main(){
	t_array array;

	int etapas, total;
	scanf("%i",&etapas);
	while (etapas != 0) {
		total = 0;
		for (int j = 0; j < etapas; j++){
			scanf("%i", &array[j]);
			total += array[j];
		}

		for (int k = 0; k < etapas - 1; k++){
			printf("%i ", total);
			total -= array[k];
		}
		printf("%i\n",total);

		for (int i = 0; i < size; i++){
			array[i] = 0;
		}
		scanf("%i",&etapas);
	}
	return 0;
}
