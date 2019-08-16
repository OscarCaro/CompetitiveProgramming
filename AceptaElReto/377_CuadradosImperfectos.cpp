// Exercise 337

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

typedef char t_char_array [4];
typedef int t_nums[4];

int main() {
	string inputNumString, impDigitsString;
	t_char_array char_array;
	t_nums nums;
	int stringSize, realNum = 0, remainder, n;
	while(cin >> inputNumString){
		for (int j = 0; j < 4; j++){
			char_array[j] = 0;
		}

		stringSize = inputNumString.length();

		if (stringSize >= 4){
			n = 4;
		} else if (stringSize <= 3 && stringSize >= 1) {
			n = stringSize;
		}
		impDigitsString = inputNumString.substr(stringSize - n, n);

		for (int a = 0; a < n; a++){
			char_array[a] = impDigitsString[a];
		}

		for (int i = 0; i < n; i++) {
			nums[i] = char_array[i] - 48;
		}

		switch(n) {
			case 1:
				realNum = nums[0];
				break;

			case 2:
				realNum += nums[1] + nums[0] * 10;
				break;
			case 3:
				realNum += nums[2] + nums[1] * 10 + nums[0] * 100;
				break;
			case 4:
				realNum += nums[3] + nums[2] * 10 + nums[1] * 100+ nums[0] * 1000;
				break;
		}

		remainder = realNum % 16;
		if (remainder == 0 || remainder == 1 || remainder == 4 || remainder == 9){
			cout << "NO SE" << endl;
		} else {
			cout << "IMPERFECTO" << endl;
		}
		realNum = 0;
	}
	return 0;
}
