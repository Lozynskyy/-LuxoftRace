#ifndef ACTIOS_H
#define ACTIONS_H

class Actions
{
public:
	void pause();
	void finish();
	void turnRight(char space[30][50], int xCarCoordinate[], int yCarCoordinate[], const int CAR_WIDTH);
	void turnLeft(char space[30][50], int xCarCoordinate[], int yCarCoordinate[], const int CAR_WIDTH);
	int upArrowButton(int, int);
	int downArrowButton(int, int);
};
#endif;