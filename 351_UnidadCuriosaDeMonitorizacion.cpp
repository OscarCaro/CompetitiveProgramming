#include <iostream>
using namespace std;

typedef struct {
	int id;
	int period;
	int current;
}tCell;

typedef tCell tArray[2500];

typedef struct {
	tArray array;
	int counter;
}tList;

typedef tList *listPtr;

int findLower (const tList &list);

int main() {
	int lowerPos, n;
	listPtr list = new tList;

	cin >> list->counter;
	while ( list->counter != 0 ) {
		
		for ( int i = 0; i < list->counter; i++ ) {
			cin >> list->array[i].id;
			cin >> list->array[i].period;
			list->array[i].current = list->array[i].period;
		}
		cin >> n;

		for ( int i = 0; i < n; i++ ) {
			lowerPos = findLower ( *list );
			cout << list->array[lowerPos].id << endl;
			list->array[lowerPos].current += list->array[lowerPos].period;
		}
		cout << "----" << endl;

		cin >> list->counter;
	}
	return 0;
}

int findLower ( const tList& list ) {
	int pos = 0, aux = list.array[0].current;
	for ( int i = 0; i < list.counter; i++ ) {
		if ( list.array[i].current < aux ) {
			pos = i;
			aux = list.array[i].current;
		}
		else if ( list.array[i].current == aux ) {
			if ( list.array[i].id < list.array[pos].id ) {
				pos = i;
				aux = list.array[i].current;
			}
		}
	}
	return pos;
}
