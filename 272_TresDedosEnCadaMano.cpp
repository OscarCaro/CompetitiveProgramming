// 272 Tres dedos en cada mano

#include <cstdio>
#include <string>
using namespace std;

string convertToBase6(long long int num);

int main(){
	int n;
	long int num;
	string result;
	scanf("%i",&n);

	for (int i = 0; i < n; i++) {
		scanf("%li",&num);

		result = convertToBase6(num);
		printf("%s\n",result.c_str());

	}
}

string convertToBase6(long long int num){
	string result;
	while (num >= 6){
		result.insert(0,1,char(num % 6 + int('0')));
		num = num / 6;
	}
	result.insert(0,1,char(num + int('0')));
	return result;
}
