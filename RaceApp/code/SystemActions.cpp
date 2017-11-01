#include<iostream>
#include<Windows.h>
#include"SystemActions.h"
#include"Game.h"

using namespace std;

void SystemActions::pause()
{
	if(GetAsyncKeyState(VK_RETURN)){
		int k = 1;
		while(k!=2){
			if(GetAsyncKeyState(VK_RETURN))
				k = 2;
		}
	}
};
void SystemActions::finish()
{
	if(GetAsyncKeyState(VK_ESCAPE))
		exit(1);
};