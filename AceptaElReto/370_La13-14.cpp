#include <iostream>
using namespace std;
bool isPrime(int num);
void print(bool is);

int main() {
	short int n;
	unsigned long long int num1, num2;
	char aux;
	bool is;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> num1;
		cin >> aux;
		cin >> num2;
		if ((num2 - num1) == 1){
			is = isPrime(num1);
			print (is);
		} else if ((num1 - num2) == 1 ) {
			is = isPrime(num2);
			print (is);
		} else {
			print(false);
		}
	}
	return 0;
}

bool isPrime(int num) {
	return ((num % 2) == 0);
}

void print(bool is) {
	if(is) {
		cout << "SI" << endl;
	} else {
		cout << "NO" << endl;
	}
}
