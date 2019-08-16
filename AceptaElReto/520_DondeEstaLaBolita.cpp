#include <iostream>
using namespace std;

int main() {
	int n, pos, a, b;
	cin >> n >> pos;
	while (n != 0 && pos != 0) {
		cin >> a >> b;
		while (a != 0 && b != 0) {
			if (a == pos) {
				pos = b;
			}
			cin >> a >> b;
		}
		cout << pos << endl;
		cin >> n >> pos;
	}


	return 0;
}