#include <iostream>
#include <string>

using namespace std;

int main () {
	int n;
	int bestArea, bestWater, bestDistance, bestCompost;
	int currArea, currWater, currDistance, currCompost;
	string bestName;
	string currName;
	while ( cin >> n ) {
		for ( int i = 0; i < n; i++ ) {			
			if ( i == 0 ) {
				cin >> bestArea >> bestCompost >> bestWater >> bestDistance;
				cin.ignore ();
				getline ( cin, bestName );
			}
			else {
				cin >> currArea >> currCompost >> currWater >> currDistance;
				cin.ignore ();
				getline ( cin, currName );
				if ( currArea > bestArea ) {
					bestArea = currArea;
					bestWater = currWater;
					bestDistance = currDistance;
					bestCompost = currCompost;
					bestName = currName;
				}
				else if ( currArea == bestArea ) {
					if ( currWater < bestWater ) {
						bestArea = currArea;
						bestWater = currWater;
						bestDistance = currDistance;
						bestCompost = currCompost;
						bestName = currName;
					}
					else if ( currWater == bestWater ) {
						if ( currDistance < bestDistance ) {
							bestArea = currArea;
							bestWater = currWater;
							bestDistance = currDistance;
							bestCompost = currCompost;
							bestName = currName;
						}
						else if ( currDistance == bestDistance ) {
							if ( currCompost < bestCompost ) {
								bestArea = currArea;
								bestWater = currWater;
								bestDistance = currDistance;
								bestCompost = currCompost;
								bestName = currName;
							}
						}
					}
				}

			}
		}
		cout << bestName << endl;
	}

	return 0;
}




