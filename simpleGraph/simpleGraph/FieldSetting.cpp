#include "Figure.h"
#include "DrawFirstCommandTank.h" 
#include "DrawSecondCommandTank.h"
#include <windows.h>
#include <iostream>

using namespace std;

int main() 
{
	Figure *tank = new DrawFirstCommandTank(5,5);
	Figure *enemyTank = new DrawSecondCommandTank(15,15);
	HANDLE oh = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD maxWindow = GetLargestConsoleWindowSize(oh); // ������ ������ �������� ���������� ����������� ����
	SMALL_RECT srctWindow = { 0, 0, maxWindow.X - 1, maxWindow.Y - 1};
	SMALL_RECT minWindow = { 0, 0, 0, 0 };
	SetConsoleWindowInfo(oh, true, &minWindow);
	SetConsoleScreenBufferSize(oh, maxWindow);
	SetConsoleWindowInfo(oh, true, &srctWindow);
	tank->Draw();
	enemyTank->Draw();
	getchar();
}

