#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Game.h"
#include "Display.h"
#include "SystemActions.h"
#include "CarActions.h"
#include "Road.h"

using namespace std;

int main()
{	
	system("mode con cols=51 lines=34");

	const int LENGTH = 30;
	const int WIDTH = 50;
	const int CAR_LENGTH = 4;
	const int CAR_WIDTH = 5;
	const int LINES = 4;

	char space[LENGTH][WIDTH];
	int xCarCoordinate[CAR_LENGTH] = {26, 27, 28, 29};
	int yCarCoordinate[CAR_WIDTH] = {22, 23, 24, 25, 26};
	int yBorderCoordinate[LINES] = {3, 4, 45, 46};
	
	Game game;
	game.setDelay(256);
	game.setDelayChangeStep(2);
	Road road;
	road.draw(space, xCarCoordinate, yCarCoordinate, yBorderCoordinate, LENGTH, WIDTH);
	while(true){
		SystemActions sysActions;
		sysActions.finish();
		sysActions.pause();
		CarActions carActions;
		carActions.turnLeft(space, xCarCoordinate, yCarCoordinate, CAR_WIDTH);
		carActions.turnRight(space, xCarCoordinate, yCarCoordinate, CAR_WIDTH);
		game.setDelay(carActions.upArrowButton(game.getDelay(), game.getDelayChangeStep()));
		game.setDelay(carActions.downArrowButton(game.getDelay(), game.getDelayChangeStep()));
		road.move(space, xCarCoordinate, yCarCoordinate, yBorderCoordinate, LENGTH, WIDTH);
		road.addRubbish(space);
		Display display;
		display.printRoad(space, LENGTH, WIDTH);
		display.printInfo(WIDTH, game.getDelay(), game.getTime(), game.getDistance());
		road.frontStrike(space, xCarCoordinate, yCarCoordinate);
		game.makeDelay();
	}
	return 0;
}