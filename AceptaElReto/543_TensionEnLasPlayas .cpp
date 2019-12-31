#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int maxUmbrellas = 100;
typedef int t_data[maxUmbrellas][3];

void initializeArray ( t_data &data );
void processNewUmbrella ( int posX, int posY, int r, t_data &data, int k, int &counter );
bool isOnTop ( int aX, int aY, int aR, int bX, int bY, int bR );
//bool isCellInvading ( int cellX, int cellY, int aX, int aY, int aR );

int main () {
	int n;
	cin >> n;
	t_data data;
	for ( int j = 0; j < n; j++ ) {
		initializeArray ( data );

		int numOfUmbrellas;
		cin >> numOfUmbrellas;

		int counter = 0;

		for ( int k = 0; k < numOfUmbrellas; k++ ) {
			int auxX, auxY, auxR;
			cin >> auxX >> auxY >> auxR;
			processNewUmbrella ( auxX, auxY, auxR, data, k, counter );
		}
		cout << counter << endl;
	}
	return 0;
}

void initializeArray ( t_data &data ) {
	for ( int i = 0; i < maxUmbrellas; i++ ) {
		data[i][0] = 0;
		data[i][1] = 0;
		data[i][2] = 0;
	}
}

void processNewUmbrella ( int posX, int posY, int r, t_data &data, int k, int &counter ) {
	data[k][0] = posX;
	data[k][1] = posY;
	data[k][2] = r;
	for ( int l = 0; l < k; l++ ) {
		if ( isOnTop ( data[l][0], data[l][1], data[l][2], posX, posY, r ) ) {
			counter++;
		}
	}
}

bool isOnTop ( int aX, int aY, int aR, int bX, int bY, int bR ) {
	int distance = sqrt ( pow ( abs ( aX - bX ), 2 ) + pow ( abs ( aY - bY ), 2 ) );
	return (distance < (aR + bR));

	//bool onTopInX = false;
	//bool onTopInY = false;

	//if ( (bX - bR + 1 <= aX - aR + 1) && (bX + bR - 1 >= aX + aR - 1) ) {
	//	onTopInX = true;
	//	// Case 3
	//}
	//else if ( (bX - bR + 1 <= aX + aR - 1) && (bX - bR + 1 >= aX - aR + 1) ) {
	//	onTopInX = true;
	//	// Case 2
	//}
	//else if ( (bX + bR - 1 >= aX - aR + 1) && (bX + bR - 1 <= aX + aR - 1) ) {
	//	onTopInX = true;
	//	// Case 1
	//}

	//if ( (bY - bR + 1 <= aY - aR + 1) && (bY + bR - 1 >= aY + aR - 1) ) {
	//	onTopInY = true;
	//	// Case 3
	//}
	//else if ( (bY + bR - 1 >= aY - aR + 1) && (bY + bR - 1 <= aY + aR - 1) ) {
	//	onTopInY = true;
	//	// Case 1
	//}
	//else if ( (bY - bR + 1 >= aY - aR + 1) && (bY - bR + 1 <= aY + aR - 1) ) {
	//	onTopInY = true;
	//	// Case 2
	//}
	//return (onTopInX && onTopInY);

	//bool itIs = false;
	//for ( int x = bX - bR + 1; x <= bX + bR - 1 && !itIs; x++ ) {
	//	for ( int y = bY - bR + 1; y <= bY + bR - 1 && !itIs; y++ ) {
	//		if ( isCellInvading ( x, y, aX, aY, aR ) ) {
	//			itIs = true;
	//		}
	//	}
	//}
	//return itIs;
}

//bool isCellInvading ( int cellX, int cellY, int aX, int aY, int aR ) {
//	bool itIs = false;
//	if ( (cellX >= aX - aR + 1) && (cellX <= aX + aR - 1) ) {
//		if ( (cellY >= aY - aR + 1) && (cellY <= aY + aR - 1) ) {
//			itIs = true;
//		}
//	}
//	return itIs;
//}