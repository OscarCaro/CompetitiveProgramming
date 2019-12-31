#include <iostream>
#include <string>
using namespace std;

int main () {
	int n;
	cin >> n;
	int numOfFloors, stepsPerFloor, floorOfFall, extraStepsOfFall;
	for ( int i = 0; i < n; i++ ) {
		cin >> numOfFloors >> stepsPerFloor >> floorOfFall >> extraStepsOfFall;
		cout << floorOfFall * stepsPerFloor + extraStepsOfFall;
		cout << " ";
		cout << numOfFloors * stepsPerFloor + floorOfFall * stepsPerFloor + extraStepsOfFall << endl;
	}
	return 0;
}