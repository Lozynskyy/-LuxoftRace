#ifndef GAME_H   
#define GAME_H

class Game
{
protected:
	int delay;
	int delayChangeStep;
public:
	void gameOver();
	void setDelay(int);
	int getDelay();
	void setDelayChangeStep(int);
	int getDelayChangeStep();
	void makeDelay();
};
#endif;