// Ex 372: La farsante de Mary Poppins
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
const int SIZE = 40;
typedef char t_array[SIZE];


int main(){
	int n, counter;
	string input;
	cin >> n;
	cin.ignore();


	for(int i = 0; i < n; i++){
		getline(cin,input);
		counter = input.size();
		if(isupper(input.at(0))){

			cout << char(toupper(input.at(counter - 1)));
		} else {

			cout << input.at(counter - 1);
		}
		for(int j = 1; j < counter; j++){

			cout << char(tolower(input.at(counter - 1 - j)));
		}
		cout << endl;

	}
	return 0;
}
