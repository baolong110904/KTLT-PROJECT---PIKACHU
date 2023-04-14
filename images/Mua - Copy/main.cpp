#include<stdio.h>
#include<Windows.h>
#include<windows.h>
#include"mmsystem.h"
#include<time.h>
#include<thread>
#include<chrono>
#include "menu.h"
using namespace std;


void resizeConsole(int width, int height){
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

int main(){

    drawLogo();
    cout << endl;
    drawMenu();
	displayMenu(0);
	bool music_on = true;
    // Set console size and play background music
	resizeConsole(1000,600);
	
	
	
	return 0;
}

