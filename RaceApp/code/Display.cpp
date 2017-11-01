#include <iostream>
#include "Display.h"
#include "Road.h"

using namespace std;

void Display::printRoad(char space[30][50], const int LENGTH, const int WIDTH)
{
	system("cls");
	for(int i = 0; i < LENGTH; ++i){
		for(int j = 0; j < WIDTH; ++j){
			cout << space[i][j];
		}
			cout << endl;
	}
};
void Display::printInfo(const int WIDTH, int delay, float timer, float distance)
{
	for(int j = 0; j < WIDTH; j++){
		cout << "-";
	}
	cout << endl;
	int speed = 10240/delay;
	cout << "  speed : " << speed << " m/s" << endl;
	cout << "  time : " << timer << " s" << endl;
	cout << "  distance : " << distance << " m";
}