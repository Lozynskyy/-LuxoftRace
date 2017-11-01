#ifndef ROAD_H   
#define ROAD_H

class Road
{
public:
	void move(char space[30][50], int xCarCoordinate[], int yCarCoordinate[], int yBorderCoordinate[], const int LENGTH, const int WIDTH);
	void frontStrike(char space[30][50], int xCarCoordinate[], int yCarCoordinate[]);
	void addRubbish(char space[30][50]);
	int getSpeed();
	void draw(char space[30][50], int xCarCoordinate[], int yCarCoordinate[], int yBorderCoordinate[], const int LENGTH, const int WIDTH);
private:
	int speed;
};
#endif