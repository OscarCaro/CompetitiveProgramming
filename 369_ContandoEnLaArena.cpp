#include <iostream>
using namespace std;

int main() {
	unsigned short int num;
	cin >> num;
	while (num != 0) {
		for (int i = 0; i < num; i++){
			cout << '1';
		}
		cout << endl;
		cin >> num;
	}
	return 0;
}
