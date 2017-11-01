#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Game.h"

using namespace std;

Game::Game()
{
	distance = 0;
	startTimer = 0;
	secondTimer = 0;
}
void Game::gameOver()
{
	system("cls");
	for(int i = 0; i < 11; ++i){
		cout << endl;
	}
	cout << "                     Game Over!" << endl << endl;
	cout <<	"               Press [Enter] to exit" << endl << endl;
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
float Game::getTime()
{
	secondTimer = startTimer;
	startTimer = clock();
	time = float(startTimer) / CLOCKS_PER_SEC;
	return time;
}
float Game::getDistance()
{
	clock_t timeCalc = startTimer - secondTimer;
	float timeSec = float(timeCalc)/CLOCKS_PER_SEC;
	distance += timeSec * 1024/delay;
	return distance;
}