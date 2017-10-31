#include <iostream>
#include "Display.h"

using namespace std;

void Display::print(char space[30][50], const int LENGTH, const int WIDTH)
{
	system("cls");
	for(int i = 0; i < LENGTH; ++i){
		for(int j = 0; j < WIDTH; ++j){
			cout << space[i][j];
		}
		if(i < LENGTH-1)
			cout << endl;
	}
};