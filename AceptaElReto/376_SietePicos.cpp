// Exercise 376 Siete Picos

#include <iostream>
using namespace std;


int main() {
	int n, peaks;
	cin >> n;
	while(n != 0){
		peaks = 0;
		typedef int t_nums [n];
		t_nums nums;
		for (int i = 0; i < n; i++){
			cin >> nums[i];
		}
		for (int j = 0; j < n; j++){
			if (j == 0){
				if (nums[j] > nums[j + 1] && nums[j] > nums[n - 1]){
					peaks++;
				}
			} else if(j ==  n - 1){
				if (nums[j] > nums[0] && nums[j] > nums[n - 2]){
					peaks++;
				}
			} else {
				if (nums[j] > nums[j + 1] && nums[j] > nums[j - 1]){
					peaks++;
				}
			}
		}
		cout << peaks << endl;
		cin >> n;
	}

	return 0;
}
