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
		cout << "\n \n \n \n \n \n \n \n \n \n \n                     Game Over!" << endl;
		cout <<	"\n               Press [Enter] to exit";
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
	void print(char spc[30][50], const int L, const int W)
	{
		system("cls");
		for(int i = 0; i < L; ++i){
			for(int j = 0; j < W; ++j){
				cout << spc[i][j];
			}
			if(i < L-1)
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
	void turnRight(char spc[30][50], int xcar[], int ycar[], const int CARW)
	{
		if(GetAsyncKeyState(VK_RIGHT)){
			if(spc[xcar[0]][ycar[4]+1] == '*' || spc[xcar[1]][ycar[4]+1] == '*' || spc[xcar[2]][ycar[4]+1] == '*' || spc[xcar[3]][ycar[4]+1] == '*'){
				Game game;
				game.gameOver();
			}
			if(ycar[4] < 43){
				for(int i = 0; i < CARW; ++i){
					ycar[i] ++;
				}
				spc[xcar[0]][ycar[0]] = '(';spc[xcar[0]][ycar[1]] = ')';spc[xcar[0]][ycar[2]] = '_';spc[xcar[0]][ycar[3]] = '(';spc[xcar[0]][ycar[4]] = ')';spc[xcar[0]][ycar[0]-1] = ' ';
				spc[xcar[1]][ycar[0]] = '.';spc[xcar[1]][ycar[1]] = '|';spc[xcar[1]][ycar[2]] = '|';spc[xcar[1]][ycar[3]] = '|';spc[xcar[1]][ycar[4]] = '.';spc[xcar[1]][ycar[0]-1] = ' ';
				spc[xcar[2]][ycar[0]] = '.';spc[xcar[2]][ycar[1]] = '|';spc[xcar[2]][ycar[2]] = '_';spc[xcar[2]][ycar[3]] = '|';spc[xcar[2]][ycar[4]] = '.';spc[xcar[2]][ycar[0]-1] = ' ';
				spc[xcar[3]][ycar[0]] = '(';spc[xcar[3]][ycar[1]] = ')';spc[xcar[3]][ycar[2]] = ' ';spc[xcar[3]][ycar[3]] = '(';spc[xcar[3]][ycar[4]] = ')';spc[xcar[3]][ycar[0]-1] = ' ';
			};
		}
	}
	void turnLeft(char spc[30][50], int xcar[], int ycar[], const int CARW)
	{
		if(GetAsyncKeyState(VK_LEFT)){
			if(spc[xcar[0]][ycar[0]-1] == '*' || spc[xcar[1]][ycar[0]-1] == '*' || spc[xcar[2]][ycar[0]-1] == '*' || spc[xcar[3]][ycar[0]-1] == '*'){
				Game game;
				game.gameOver();
			}
			if(ycar[0] > 5){
				for(int i = 0; i < CARW; ++i){
					ycar[i] --;
				}
				spc[xcar[0]][ycar[0]] = '(';spc[xcar[0]][ycar[1]] = ')';spc[xcar[0]][ycar[2]] = '_';spc[xcar[0]][ycar[3]] = '(';spc[xcar[0]][ycar[4]] = ')';spc[xcar[0]][ycar[4]+1] = ' ';
				spc[xcar[1]][ycar[0]] = '.';spc[xcar[1]][ycar[1]] = '|';spc[xcar[1]][ycar[2]] = '|';spc[xcar[1]][ycar[3]] = '|';spc[xcar[1]][ycar[4]] = '.';spc[xcar[1]][ycar[4]+1] = ' ';
				spc[xcar[2]][ycar[0]] = '.';spc[xcar[2]][ycar[1]] = '|';spc[xcar[2]][ycar[2]] = '_';spc[xcar[2]][ycar[3]] = '|';spc[xcar[2]][ycar[4]] = '.';spc[xcar[2]][ycar[4]+1] = ' ';
				spc[xcar[3]][ycar[0]] = '(';spc[xcar[3]][ycar[1]] = ')';spc[xcar[3]][ycar[2]] = ' ';spc[xcar[3]][ycar[3]] = '(';spc[xcar[3]][ycar[4]] = ')';spc[xcar[3]][ycar[4]+1] = ' ';
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
	void moveRoad(char spc[30][50], int xcar[], int ycar[], const int L, const int W)
	{
		for(int i = L-1; i >= 0; i--){
			for(int j = 0; j < W; ++j){
				if(spc[i][j] != '(' && spc[i][j] != ')' && spc[i][j] != '.' && spc[i][j] != '_' && spc[i][j] != '|'){
					if(i!=0){
						spc[i][j] = spc[i-1][j];
					}
					else{
						spc[i][3] = '|';
						spc[i][4] = '|';
						spc[i][45] = '|';
						spc[i][46] = '|';
						spc[i][j] = ' ';
					}
				}
			}
		}
		
	};
	void frontStrike(char spc[30][50], int xcar[], int ycar[])
	{
		if(spc[xcar[0]-1][ycar[0]] == '*' || spc[xcar[0]-1][ycar[1]] == '*' || spc[xcar[0]-1][ycar[2]] == '*' || spc[xcar[0]-1][ycar[3]] == '*' || spc[xcar[0]-1][ycar[4]] == '*'){
			Game game;
			game.gameOver();
		}
	};
	void addRubbish(char spc[30][50])
	{
		for (int i = 5; i < 44; i++){
            if (rand() % 100 == 1)
                spc[0][i] = '*';
        }
	}
};
int main()
{	
	system("mode con cols=51 lines=30");
	int speed = 250;
	const int L = 30, W = 50, CARL = 4, CARW = 5;
	int xcar[CARL] = {26, 27, 28, 29};
	int ycar[CARW] = {22, 23, 24, 25, 26};
	char spc[L][W];
	for(int i = 0; i < L; ++i){
		for(int j = 0; j < W; ++j){
			spc[i][j] = ' ';
		}
		spc[i][3] = '|';
		spc[i][4] = '|';
		spc[i][45] = '|';
		spc[i][46] = '|';
	}
	spc[xcar[0]][ycar[0]] = '(';spc[xcar[0]][ycar[1]] = ')';spc[xcar[0]][ycar[2]] = '_';spc[xcar[0]][ycar[3]] = '(';spc[xcar[0]][ycar[4]] = ')';
	spc[xcar[1]][ycar[0]] = '.';spc[xcar[1]][ycar[1]] = '|';spc[xcar[1]][ycar[2]] = '|';spc[xcar[1]][ycar[3]] = '|';spc[xcar[1]][ycar[4]] = '.';
	spc[xcar[2]][ycar[0]] = '.';spc[xcar[2]][ycar[1]] = '|';spc[xcar[2]][ycar[2]] = '_';spc[xcar[2]][ycar[3]] = '|';spc[xcar[2]][ycar[4]] = '.';
	spc[xcar[3]][ycar[0]] = '(';spc[xcar[3]][ycar[1]] = ')';spc[xcar[3]][ycar[2]] = ' ';spc[xcar[3]][ycar[3]] = '(';spc[xcar[3]][ycar[4]] = ')';
	while(true){
		Actions actions;
		actions.finish();
		actions.pause();
		actions.turnLeft(spc, xcar, ycar, CARW);
		actions.turnRight(spc, xcar, ycar, CARW);
		speed = actions.changeSpeedRaise(speed);
		speed = actions.changeSpeedFall(speed);
		Road road;
		road.moveRoad(spc, xcar, ycar, L, W);
		road.addRubbish(spc);
		Display display;
		display.print(spc, L, W);
		road.frontStrike(spc, xcar, ycar);
		Sleep(speed);
	}
	return 0;
}