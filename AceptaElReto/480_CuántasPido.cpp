//480 ¿Cuántas pido?
#include <iostream>
using namespace std;


int main(){
	int n, total, bad, good, result;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> total;
		cin >> bad;
		cin >> good;
		result = (total / good) * bad;
		if (total % good != 0){
			if(total % good <= bad){
				result += total % good;
			} else {
				result += bad;
			}
		}
		cout << result << endl;
	}
	return 0;
}
