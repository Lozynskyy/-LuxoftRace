#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Game.h"
#include "Display.h"
#include "Actions.h"
#include "Road.h"

using namespace std;

int main()
{	
	system("mode con cols=52 lines=30");
	const int LENGTH = 30;
	const int WIDTH = 50;
	const int CAR_LENGTH = 4;
	const int CAR_WIDTH = 5;
	int xCarCoordinate[CAR_LENGTH] = {26, 27, 28, 29};
	int yCarCoordinate[CAR_WIDTH] = {22, 23, 24, 25, 26};
	int yBorderCoordinate[4] = {3, 4, 45, 46};
	char space[LENGTH][WIDTH];
	for(int i = 0; i < LENGTH; ++i){
		for(int j = 0; j < WIDTH; ++j){
			space[i][j] = ' ';
		}
		for(int k = 0; k < 4; ++k){
			space[i][yBorderCoordinate[k]] = '|';
		}
	}
	space[xCarCoordinate[0]][yCarCoordinate[0]] = '(';
	space[xCarCoordinate[0]][yCarCoordinate[1]] = ')';
	space[xCarCoordinate[0]][yCarCoordinate[2]] = '_';
	space[xCarCoordinate[0]][yCarCoordinate[3]] = '(';
	space[xCarCoordinate[0]][yCarCoordinate[4]] = ')';
	space[xCarCoordinate[1]][yCarCoordinate[0]] = '.';
	space[xCarCoordinate[1]][yCarCoordinate[1]] = '|';
	space[xCarCoordinate[1]][yCarCoordinate[2]] = '|';
	space[xCarCoordinate[1]][yCarCoordinate[3]] = '|';
	space[xCarCoordinate[1]][yCarCoordinate[4]] = '.';
	space[xCarCoordinate[2]][yCarCoordinate[0]] = '.';
	space[xCarCoordinate[2]][yCarCoordinate[1]] = '|';
	space[xCarCoordinate[2]][yCarCoordinate[2]] = '_';
	space[xCarCoordinate[2]][yCarCoordinate[3]] = '|';
	space[xCarCoordinate[2]][yCarCoordinate[4]] = '.';
	space[xCarCoordinate[3]][yCarCoordinate[0]] = '(';
	space[xCarCoordinate[3]][yCarCoordinate[1]] = ')';
	space[xCarCoordinate[3]][yCarCoordinate[2]] = ' ';
	space[xCarCoordinate[3]][yCarCoordinate[3]] = '(';
	space[xCarCoordinate[3]][yCarCoordinate[4]] = ')';
	Game game;
	game.setDelay(250);
	game.setDelayChangeStep(2);
	while(true){
		Actions actions;
		actions.finish();
		actions.pause();
		actions.turnLeft(space, xCarCoordinate, yCarCoordinate, CAR_WIDTH);
		actions.turnRight(space, xCarCoordinate, yCarCoordinate, CAR_WIDTH);
		game.setDelay(actions.upArrowButton(game.getDelay(), game.getDelayChangeStep()));
		game.setDelay(actions.downArrowButton(game.getDelay(), game.getDelayChangeStep()));
		Road  road;
		road.move(space, xCarCoordinate, yCarCoordinate, yBorderCoordinate, LENGTH, WIDTH);
		road.addRubbish(space);
		Display display;
		display.print(space, LENGTH, WIDTH);
		road.frontStrike(space, xCarCoordinate, yCarCoordinate);
		game.makeDelay();
	}
	return 0;
}