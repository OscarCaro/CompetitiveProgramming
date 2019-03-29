// Exercise 154 ¿Cuál es la siguiente matrícula?

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

typedef char t_arrayChar [3];

int main() {
	//cout << char('A' + 1) << endl;
	int num;
	t_arrayChar letter;
	cin >> num;
	cin >> letter[0];
	cin >> letter[1];
	cin >> letter[2];
	while (num != 9999 || letter[0] != 'Z' || letter[1] != 'Z' || letter[2] != 'Z'){
		if (num < 9999){
			num++;
		} else {
			num = 0000;
			if (letter[2] < 'Z'){
				if(letter[2] == 'D' || letter[2] == 'H' || letter[2] == 'N' || letter[2] == 'T'){
					letter[2] += 2;
				} else {
					letter[2]++;
				}
			} else {
				letter[2] = 'B';
				if(letter[1] < 'Z') {
					if(letter[1] == 'D' || letter[1] == 'H' || letter[1] == 'N' || letter[1] == 'T'){
						letter[1] += 2;
					} else {
						letter[1]++;
					}
				} else {
					letter[2] = 'B';
					letter[1] = 'B';
					if(letter[0] < 'Z') {
						if(letter[0] == 'D' || letter[0] == 'H' || letter[0] == 'N' || letter[0] == 'T'){
							letter[0] += 2;
						} else {
							letter[0]++;
						}
					}
				}

			}
		}


		cout << setfill('0') << setw(4) << num << " " << letter[0] << letter[1] << letter[2] << endl;

		cin >> num;
		cin >> letter[0];
		cin >> letter[1];
		cin >> letter[2];
	}
	return 0;
}
