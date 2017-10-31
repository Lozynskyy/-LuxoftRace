#include<iostream>
#include<Windows.h>
#include"Actions.h"
#include"Game.h"
#include"Road.h"

using namespace std;

void Actions::pause()
{
	if(GetAsyncKeyState(VK_RETURN)){
		int k = 1;
		while(k!=2){
			if(GetAsyncKeyState(VK_RETURN))
				k = 2;
		}
	}
};
void Actions::finish()
{
	if(GetAsyncKeyState(VK_ESCAPE))
		exit(1);
};
void Actions::turnRight(char space[30][50], int xCarCoordinate[], int yCarCoordinate[], const int CAR_WIDTH)
{
	if(GetAsyncKeyState(VK_RIGHT)){
		if(space[xCarCoordinate[0]][yCarCoordinate[4]+1] == '*' || space[xCarCoordinate[1]][yCarCoordinate[4]+1] == '*' || space[xCarCoordinate[2]][yCarCoordinate[4]+1] == '*' || space[xCarCoordinate[3]][yCarCoordinate[4]+1] == '*'){
			Game game;
			game.gameOver();
		}
		if(yCarCoordinate[4] < 44){
			for(int i = 0; i < CAR_WIDTH; ++i){
				yCarCoordinate[i] ++;
			}
			space[xCarCoordinate[0]][yCarCoordinate[0]] = '(';space[xCarCoordinate[0]][yCarCoordinate[1]] = ')';space[xCarCoordinate[0]][yCarCoordinate[2]] = '_';space[xCarCoordinate[0]][yCarCoordinate[3]] = '(';space[xCarCoordinate[0]][yCarCoordinate[4]] = ')';space[xCarCoordinate[0]][yCarCoordinate[0]-1] = ' ';
			space[xCarCoordinate[1]][yCarCoordinate[0]] = '.';space[xCarCoordinate[1]][yCarCoordinate[1]] = '|';space[xCarCoordinate[1]][yCarCoordinate[2]] = '|';space[xCarCoordinate[1]][yCarCoordinate[3]] = '|';space[xCarCoordinate[1]][yCarCoordinate[4]] = '.';space[xCarCoordinate[1]][yCarCoordinate[0]-1] = ' ';
			space[xCarCoordinate[2]][yCarCoordinate[0]] = '.';space[xCarCoordinate[2]][yCarCoordinate[1]] = '|';space[xCarCoordinate[2]][yCarCoordinate[2]] = '_';space[xCarCoordinate[2]][yCarCoordinate[3]] = '|';space[xCarCoordinate[2]][yCarCoordinate[4]] = '.';space[xCarCoordinate[2]][yCarCoordinate[0]-1] = ' ';
			space[xCarCoordinate[3]][yCarCoordinate[0]] = '(';space[xCarCoordinate[3]][yCarCoordinate[1]] = ')';space[xCarCoordinate[3]][yCarCoordinate[2]] = ' ';space[xCarCoordinate[3]][yCarCoordinate[3]] = '(';space[xCarCoordinate[3]][yCarCoordinate[4]] = ')';space[xCarCoordinate[3]][yCarCoordinate[0]-1] = ' ';
		};
	}
};
void Actions::turnLeft(char space[30][50], int xCarCoordinate[], int yCarCoordinate[], const int CAR_WIDTH)
{
	if(GetAsyncKeyState(VK_LEFT)){
		if(space[xCarCoordinate[0]][yCarCoordinate[0]-1] == '*' || space[xCarCoordinate[1]][yCarCoordinate[0]-1] == '*' || space[xCarCoordinate[2]][yCarCoordinate[0]-1] == '*' || space[xCarCoordinate[3]][yCarCoordinate[0]-1] == '*'){
			Game game;
			game.gameOver();
		}
		if(yCarCoordinate[0] > 5){
			for(int i = 0; i < CAR_WIDTH; ++i){
				yCarCoordinate[i] --;
			}
			space[xCarCoordinate[0]][yCarCoordinate[0]] = '(';space[xCarCoordinate[0]][yCarCoordinate[1]] = ')';space[xCarCoordinate[0]][yCarCoordinate[2]] = '_';space[xCarCoordinate[0]][yCarCoordinate[3]] = '(';space[xCarCoordinate[0]][yCarCoordinate[4]] = ')';space[xCarCoordinate[0]][yCarCoordinate[4]+1] = ' ';
			space[xCarCoordinate[1]][yCarCoordinate[0]] = '.';space[xCarCoordinate[1]][yCarCoordinate[1]] = '|';space[xCarCoordinate[1]][yCarCoordinate[2]] = '|';space[xCarCoordinate[1]][yCarCoordinate[3]] = '|';space[xCarCoordinate[1]][yCarCoordinate[4]] = '.';space[xCarCoordinate[1]][yCarCoordinate[4]+1] = ' ';
			space[xCarCoordinate[2]][yCarCoordinate[0]] = '.';space[xCarCoordinate[2]][yCarCoordinate[1]] = '|';space[xCarCoordinate[2]][yCarCoordinate[2]] = '_';space[xCarCoordinate[2]][yCarCoordinate[3]] = '|';space[xCarCoordinate[2]][yCarCoordinate[4]] = '.';space[xCarCoordinate[2]][yCarCoordinate[4]+1] = ' ';
			space[xCarCoordinate[3]][yCarCoordinate[0]] = '(';space[xCarCoordinate[3]][yCarCoordinate[1]] = ')';space[xCarCoordinate[3]][yCarCoordinate[2]] = ' ';space[xCarCoordinate[3]][yCarCoordinate[3]] = '(';space[xCarCoordinate[3]][yCarCoordinate[4]] = ')';space[xCarCoordinate[3]][yCarCoordinate[4]+1] = ' ';
		};
	}
};
int Actions::upArrowButton(int delay, int delayStep)
{
	if(GetAsyncKeyState(VK_UP)){
		delay /= delayStep;
	}
	return delay;
};
int Actions::downArrowButton(int delay, int delayStep)
{
	if(GetAsyncKeyState(VK_DOWN)){
		delay *= delayStep;
	}
	return delay;
};