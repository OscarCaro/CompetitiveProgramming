//Ex 538: Toesto era campo
#include <iostream>
#include <string>
using namespace std;

int main () {
	int grandpa, church;
	cin >> grandpa >> church;
	while ( grandpa != 0 || church != 0 ) {
		if ( grandpa >= church ) {
			cout << "CUERDO" << endl;
		}
		else {
			cout << "SENIL" << endl;
		}
		cin >> grandpa >> church;
	}
	return 0;
}