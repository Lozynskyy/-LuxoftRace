#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Game.h"

using namespace std;

void Game::gameOver()
{
	system("cls");
	for(int i = 0; i < 11; ++i){
		cout << endl;
	}
	cout << "                     Game Over!" << endl << endl;
	cout <<	"               Press [Enter] to exit";
	int k = 1;
	while(k!=2){
		 if(getch() == 13)
			k = 2;
	}
	exit(1);
};
void Game::setDelay(int screenDelay)
{
	delay = screenDelay;
};
int Game::getDelay()
{
	return delay;
};
void Game::setDelayChangeStep(int delayStep)
{
	delayChangeStep = delayStep;
};
int Game::getDelayChangeStep()
{
	return delayChangeStep;
};
void Game::makeDelay()
{
	Sleep(delay);
}