// Problema 252: Acaso hubo búhos acá

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

typedef char t_array[100];

string reverse(string input, t_array arrayInput, t_array arrayReversed);
string lowerCase(string input, t_array arrayInput, t_array arrayReversed);


int main() {
	string input, reversed, lowerCaseStr;
	t_array arrayInput;
	t_array arrayReversed;

	getline(cin, input);
	while (input != "XXX") {
		reversed = reverse(input, arrayInput, arrayReversed);
		lowerCaseStr = lowerCase(input, arrayInput, arrayReversed);
		if (reversed == lowerCaseStr){
			cout << "SI" << endl;
		} else {
			cout << "NO" << endl;
		}
		getline(cin, input);
	}
	return 0;
}

string reverse(string input, t_array arrayInput, t_array arrayReversed){
	int size = input.size();
	int j = 0;
	strcpy(arrayInput, input.c_str());
	for (int i = 0; i < size; i++) {
		if (tolower(arrayInput[size - i - 1]) != ' '){
			arrayReversed[j] = tolower(arrayInput[size - i - 1]);
			j++;
		}
	}
	return string(arrayReversed).substr(0, j);
}

string lowerCase(string input, t_array arrayInput, t_array arrayReversed){
	int size = input.size();
	int j = 0;
	strcpy(arrayInput, input.c_str());
	for (int i = 0; i < size; i++) {
		if (tolower(arrayInput[i]) != ' '){
			arrayReversed[j] = tolower(arrayInput[i]);
			j++;
		}
	}
	return string(arrayReversed).substr(0, j);
}

