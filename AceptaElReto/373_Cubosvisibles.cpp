#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


int main() {
	int cases;
	long long int num;
	cin >> cases;
	for (int i = 0; i < cases; i++){
		cin >> num;
		cout << fixed << setprecision(0) << ceil(num * num * num - ((num - 2) * (num - 2) * (num - 2))) << endl;
	}
	return 0;
}