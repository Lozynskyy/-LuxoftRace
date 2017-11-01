#ifndef GAME_H   
#define GAME_H
#include<ctime>

class Game
{

public:
	Game();
	void gameOver();
	void setDelay(int);
	int getDelay();
	void setDelayChangeStep(int);
	int getDelayChangeStep();
	void makeDelay();
	float getTime();
	float getDistance();
protected:
	float time;
	int delay;
	int delayChangeStep;
	clock_t startTimer;
	clock_t secondTimer;
	float distance;
};
#endif;