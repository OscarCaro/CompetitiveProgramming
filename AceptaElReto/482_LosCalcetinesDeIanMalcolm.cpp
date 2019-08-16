#include iostream
using namespace std;

const int size = 2;
typedef unsigned long int t_array[size];

int main(){
	char ch;
	t_array array;
	int counter = 0;
	array[0] = 0;
	array[1] = 0;
	while(counter  2) {
		counter = 0;
		cin  ch;
		if (ch == '.'){
			counter = 3;
		} else if (ch == 'G') {
			array[1]++;
		} else if (ch == 'N'){
			array[0]++;
		}

		while (counter  1){
			cin  ch;
			if (ch == '.'){
				counter = 1;
			} else if (ch == 'G') {
				array[1]++;
			} else if (ch == 'N'){
				array[0]++;
			}
		}
		if(counter  2){
			if (array[0] % 2 == 0 && array[1] % 2 == 0){
				cout  EMPAREJADOS  endl;
			} else if (array[0] % 2 != 0 && array[1] % 2 != 0){
				cout  PAREJA MIXTA  endl;
			} else if (array[0] % 2 != 0 && array[1] % 2 == 0){
				cout  NEGRO SOLITARIO  endl;
			} else if (array[0] % 2 == 0 && array[1] % 2 != 0){
				cout  GRIS SOLITARIO  endl;
			}
		}
		array[0] = 0;
		array[1] = 0;
	}
	return 0;
}
