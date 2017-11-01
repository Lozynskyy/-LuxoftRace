#ifndef CAR_ACTIONS_H
#define CAR_ACTIONS_H

class CarActions
{
public:
	void turnRight(char space[30][50], int xCarCoordinate[], int yCarCoordinate[], const int CAR_WIDTH);
	void turnLeft(char space[30][50], int xCarCoordinate[], int yCarCoordinate[], const int CAR_WIDTH);
	int upArrowButton(int, int);
	int downArrowButton(int, int);
};
#endif;