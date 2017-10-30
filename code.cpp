#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;
class Game
{
public:
	void gameOver()
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
};
class Display
{
public:
	void print(char space[30][50], const int LENGTH, const int WIDTH)
	{
		system("cls");
		for(int i = 0; i < LENGTH; ++i){
			for(int j = 0; j < WIDTH; ++j){
				cout << space[i][j];
			}
			if(i < LENGTH-1)
				cout << endl;
		}
	}
};
class Actions : public Game
{
public:
	void pause()
	{
		if(GetAsyncKeyState(VK_RETURN)){
			int k = 1;
			while(k!=2){
				if(GetAsyncKeyState(VK_RETURN))
					k = 2;
			}
		}
	}
	void finish()
	{
		if(GetAsyncKeyState(VK_ESCAPE))
			exit(1);
	}
	void turnRight(char space[30][50], int xCarCoordinate[], int yCarCoordinate[], const int CAR_WIDTH)
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
	}
	void turnLeft(char space[30][50], int xCarCoordinate[], int yCarCoordinate[], const int CAR_WIDTH)
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
	}
	int changeSpeedRaise(int speed)
	{
		if(GetAsyncKeyState(VK_UP))
			speed/=2;
		return speed;
	}
	int changeSpeedFall(int speed)
	{
		if(GetAsyncKeyState(VK_DOWN))
			speed*=2;
		return speed;
	}
};
class Road : public Game
{
public:
	void move(char space[30][50], int xCarCoordinate[], int yCarCoordinate[], const int LENGTH, const int WIDTH)
	{
		for(int i = LENGTH-1; i >= 0; i--){
			for(int j = 0; j < WIDTH; ++j){
				if(space[i][j] != '(' && space[i][j] != ')' && space[i][j] != '.' && space[i][j] != '_' && space[i][j] != '|'){
					if(i!=0){
						space[i][j] = space[i-1][j];
					}
					else{
						space[i][3] = '|';
						space[i][4] = '|';
						space[i][45] = '|';
						space[i][46] = '|';
						space[i][j] = ' ';
					}
				}
			}
		}
		
	};
	void frontStrike(char space[30][50], int xCarCoordinate[], int yCarCoordinate[])
	{
		if(space[xCarCoordinate[0]-1][yCarCoordinate[0]] == '*' || space[xCarCoordinate[0]-1][yCarCoordinate[1]] == '*' || space[xCarCoordinate[0]-1][yCarCoordinate[2]] == '*' || space[xCarCoordinate[0]-1][yCarCoordinate[3]] == '*' || space[xCarCoordinate[0]-1][yCarCoordinate[4]] == '*'){
			Game game;
			game.gameOver();
		}
	};
	void addRubbish(char space[30][50])
	{
		for (int i = 5; i < 44; i++){
            if (rand() % 100 == 1)
                space[0][i] = '*';
        }
	}
};
int main()
{	
	system("mode con cols=52 lines=30");
	int speed = 250;
	const int LENGTH = 30, WIDTH = 50, CAR_LENGTH = 4, CAR_WIDTH = 5;
	int xCarCoordinate[CAR_LENGTH] = {26, 27, 28, 29};
	int yCarCoordinate[CAR_WIDTH] = {22, 23, 24, 25, 26};
	char space[LENGTH][WIDTH];
	for(int i = 0; i < LENGTH; ++i){
		for(int j = 0; j < WIDTH; ++j){
			space[i][j] = ' ';
		}
		space[i][3] = '|';
		space[i][4] = '|';
		space[i][45] = '|';
		space[i][46] = '|';
	}
	space[xCarCoordinate[0]][yCarCoordinate[0]] = '(';space[xCarCoordinate[0]][yCarCoordinate[1]] = ')';space[xCarCoordinate[0]][yCarCoordinate[2]] = '_';space[xCarCoordinate[0]][yCarCoordinate[3]] = '(';space[xCarCoordinate[0]][yCarCoordinate[4]] = ')';
	space[xCarCoordinate[1]][yCarCoordinate[0]] = '.';space[xCarCoordinate[1]][yCarCoordinate[1]] = '|';space[xCarCoordinate[1]][yCarCoordinate[2]] = '|';space[xCarCoordinate[1]][yCarCoordinate[3]] = '|';space[xCarCoordinate[1]][yCarCoordinate[4]] = '.';
	space[xCarCoordinate[2]][yCarCoordinate[0]] = '.';space[xCarCoordinate[2]][yCarCoordinate[1]] = '|';space[xCarCoordinate[2]][yCarCoordinate[2]] = '_';space[xCarCoordinate[2]][yCarCoordinate[3]] = '|';space[xCarCoordinate[2]][yCarCoordinate[4]] = '.';
	space[xCarCoordinate[3]][yCarCoordinate[0]] = '(';space[xCarCoordinate[3]][yCarCoordinate[1]] = ')';space[xCarCoordinate[3]][yCarCoordinate[2]] = ' ';space[xCarCoordinate[3]][yCarCoordinate[3]] = '(';space[xCarCoordinate[3]][yCarCoordinate[4]] = ')';
	while(true){
		Actions actions;
		actions.finish();
		actions.pause();
		actions.turnLeft(space, xCarCoordinate, yCarCoordinate, CAR_WIDTH);
		actions.turnRight(space, xCarCoordinate, yCarCoordinate, CAR_WIDTH);
		speed = actions.changeSpeedRaise(speed);
		speed = actions.changeSpeedFall(speed);
		Road road;
		road.move(space, xCarCoordinate, yCarCoordinate, LENGTH, WIDTH);
		road.addRubbish(space);
		Display display;
		display.print(space, LENGTH, WIDTH);
		road.frontStrike(space, xCarCoordinate, yCarCoordinate);
		Sleep(speed);
	}
	return 0;
}