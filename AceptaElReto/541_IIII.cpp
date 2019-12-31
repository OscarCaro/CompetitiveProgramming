#include <iostream>
#include <string>
using namespace std;

int gcd ( int a, int b ) {
	if ( b == 0 )
		return a;
	return gcd ( b, a % b );
}

int main () {
	int a, b, c;
	int my_gcd;
	cin >> a >> b >> c;
	while ( a != 0 || b != 0 || c != 0 ) {
		my_gcd = gcd ( a, b );
		my_gcd = gcd ( my_gcd, c );
		cout << a / my_gcd + b / my_gcd + c / my_gcd << endl;
		cin >> a >> b >> c;
	}
	return 0;
}