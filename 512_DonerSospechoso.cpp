#include <iostream>
using namespace std;

int main() {
	int casos, conejo, caballo;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		cin >> conejo;
		cin >> caballo;
		cout << int(conejo * 100.0 / (caballo + conejo)) << endl;
	}

	return 0;
}