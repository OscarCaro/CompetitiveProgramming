#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void setRL(const string &str, vector <int> &vct);
void solve(const string &str, const vector <int> &vct, int place);

int main() {
	vector <int> vct;		 

	int totalCases, place;
	string str;

	while (getline(cin, str)) {		

		vct.resize(str.size());

		setRL(str, vct);

		// Next input already read
		cin >> totalCases;
		//totalCases = aux2 - '0';
		for (int i = 0; i < totalCases; i++) {
			cin >> place;
			solve(str, vct, place);
		}
		cin.ignore();
	}
	return 0;
}

void setRL(const string &str, vector <int> &vct) {
	int size = str.size(), countL = 0, countR = 0;
	for (int i = 0; i < size; i++) {
		// Left implementation:
		if (str[i] == 'T') {
			// There's a phone at pos i
			countL = 0;
			vct[i] = 0;
		}
		else {
			// No phone at pos i
			vct[i] = -(++countL);
		}

		
	}
	for (int i = 0; i < size; i++) {
		// Right implementation:
		if (str[size - 1 - i] == 'T') {
			// There's a phone at pos size - 1 - i
			countR = 0;
			vct[size - 1 - i] = 0;
		}
		else if ((str[size - 1 - i] != 'T')) {
			// No phone at pos [size - 1 - i]
			if (-(vct[size - 1 - i]) > countR + 1) {
				vct[size - 1 - i] = countR + 1;
			}
			else if (-(vct[size - 1 - i]) == countR + 1) {
				vct[size - 1 - i] = 4000000 + countR + 1;
			}
			++countR;
		}
	}
}


void solve(const string &str, const vector <int> &vct, int place){
	int pos = place - 1;

	if (vct[pos] == 0) {					// Phone in pos
		cout << "AQUI" << endl;
	}
	else {
		//int r = right[pos];
		//int l = left[pos];

		if (vct[pos] > 0 && vct[pos] < 2000000) {
			cout << "ISLAS" << endl;
		}
		else if (vct[pos] >= 2000000) {
			int size = str.size();
			int rPhonePos = place + (vct[pos] - 4000000);
			int rPhoneDistToExit = min(size - rPhonePos + 1, rPhonePos);
			int lPhonePos = place - (vct[pos] - 4000000);
			int lPhoneDistToExit = min(size - lPhonePos + 1, lPhonePos);

			if (rPhoneDistToExit < lPhoneDistToExit) {
				cout << "ISLAS" << endl;
			}
			else if (rPhoneDistToExit > lPhoneDistToExit) {
				cout << "PENINSULA" << endl;
			}
			else { // equal dist
				cout << "PENINSULA" << endl;
			}
		}
		else { // l < r
			cout << "PENINSULA" << endl;
		}
	}
}