#include <iostream>
#include "Game.h"

#include <windows.h>
#include <conio.h>
#include <fstream>
#include<stdio.h>
#include<Windows.h>
#include <string>
#include <chrono>


#define _EASY 4
#define _MEDIUM 6
#define _HARD 8
using namespace std;


HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursorpos; // used to set the position of the cursor

int mapMaxWidth = 18, mapMaxHeight = 10;
int cellWidth = 5, cellHeight = 3;
int** map;
string *background;
int heightEz = 6, widthEz = 6;
int mapWidth = 6, mapHeight = 6;
int xCur = 1, yCur = 1;
bool selected[16] = { false };
int width = 10, height = 10;
bool isDisplayBoard = false;
const int size = _EASY;
char pokemons[size*4][size*8];
void printInterface();
void printCongratulationBoard();
//void selectedBlock();
//void unselectedBlock();

void createBackground() {
	ifstream bg;
	if(size == 4)
		bg.open("images\\easy.txt");
	else
		bg.open("images\\medium.txt");
	int i = 0;
	while (!bg.eof()) {
		getline(bg, background[i]);
		i++;
	}
	bg.close();
}
void ShowCursor(bool show)
{
	CONSOLE_CURSOR_INFO info = { 1, show };
	SetConsoleCursorInfo(consoleOutput, &info);
}
void gotoxy(int x, int y){
	COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void clearconsole() // Xoá nội dung có sẵn trong console 
{
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

enum Consolecolor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Yellow = 6,
    White = 7,
    Gray = 8,
    DarkBlue = 9,
    DarkGreen = 10,
    Teal = 11,
    DarkRed = 12,
    Purple = 13,
    Orange = 14,
    LightGray = 15,
    DarkOrange = 16,
    LightBlue = 17,
    LightGreen = 18,
    LightYellow = 19,
    LightCyan = 20,
    Pink = 21,
    Lavender = 22
    
};

void setcolor(Consolecolor color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD)color);
}

void L(string fileName, int x, int y) {
    ifstream file("text\\L.txt");

    if (file.is_open()) {
        char c;
        int posX = 5, posY = 1;
        while (file.get(c)) {
            if (c == '|' || c == '.' || c == '_' || c == '\\' || c == '-' || c == '\'' || c == '/') {
                
                gotoxy(posX, posY);
                setcolor(Yellow);
                cout << c;
                posX++;
            }
            
            else if (c == '\n') {
                posY++;
                posX = x;
            }
            else {
                
                gotoxy(posX, posY);
                setcolor(Gray);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}
void O(string fileName, int x, int y) {
    ifstream file("text\\O.txt");

    if (file.is_open()) {
        char c;
        int posX = 25, posY = 1;
        while (file.get(c)) {
            if (c == '|' || c == '.' || c == '_' || c == '\\' || c == '-' || c == '\'' || c == '/' || c == '`') {
                
                gotoxy(posX, posY);
                setcolor(Magenta);
                cout << c;
                posX++;
            }
            
            else if (c == '\n') {
                posY++;
                posX = x;
            }
            else {
                
                gotoxy(posX, posY);
                setcolor(Gray);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}
void G(string fileName, int x, int y) {
    ifstream file("text\\G.txt");

    if (file.is_open()) {
        char c;
        int posX = 44, posY = 1;
        while (file.get(c)) {
            if (c == '|' || c == '.' || c == '_' || c == '\\' || c == '-' || c == '\'' || c == '/' || c == ']' || c == '`') {
                
                gotoxy(posX, posY);
                setcolor(Cyan);
                cout << c;
                posX++;
            }
            
            else if (c == '\n') {
                posY++;
                posX = x;
            }
            else {
                
                gotoxy(posX, posY);
                setcolor(Gray);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}
void I(string fileName, int x, int y) {
    ifstream file("text\\I.txt");

    if (file.is_open()) {
        char c;
        int posX = 63, posY = 1;
        while (file.get(c)) {
            if (c == '|' || c == '.' || c == '_' || c == '\\' || c == '-' || c == '\'' || c == '/') {
                
                gotoxy(posX, posY);
                setcolor(Teal);
                cout << c;
                posX++;
            }
            
            else if (c == '\n') {
                posY++;
                posX = x;
            }
            else {
                
                gotoxy(posX, posY);
                setcolor(Gray);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}
void N(string fileName, int x, int y) {
    ifstream file("text\\N.txt");

    if (file.is_open()) {
        char c;
        int posX = 83, posY = 1;
        while (file.get(c)) {
            if (c == '|' || c == '.' || c == '_' || c == '\\' || c == '-' || c == '\'' || c == '/') {
                
                gotoxy(posX, posY);
                setcolor(Blue);
                cout << c;
                posX++;
            }
            
            else if (c == '\n') {
                posY++;
                posX = x;
            }
            else {
                
                gotoxy(posX, posY);
                setcolor(Gray);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}


void printrectangle(int left, int top, int width, int height){
	gotoxy(left, top);
	putchar(218);
	for (int i = 0; i < width; i++)
		putchar(196);
	putchar(191);

	int i = 0;
	for (; i < height; i++)
	{
		gotoxy(left, top + i + 1);
		putchar(179);
		gotoxy(left + width + 1, top + i + 1);
		putchar(179);
	}

	gotoxy(left, top + i);
	putchar(192);
	for (i = 0; i < width; i++)
		putchar(196);
	putchar(217);
}
void setConsolecolor(int textColor, int bgColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor + (bgColor * 16)));
}

void Game::setupGame() {
	system("cls");
	// Print rectangle to cover the screen
	L("text\\L.txt", 5, 1);
	O("text\\0.txt", 25, 1);
	G("text\\G.txt", 44, 1);
	I("text\\I.txt", 63, 1);
	N("text\\N.txt", 83, 1);
	
	ShowCursor(true);
	// Print input fields and get player information
	setcolor(Orange);
	printrectangle(15, 13, 80, 12);
	gotoxy(30, 15);
	cout << "Please enter your name, ID, class shortly!";
	gotoxy(35, 18);
	cout << "Enter your Name:  ";
	cin.getline(playerName, 50);
		while (playerName[0] == '\0') {
			gotoxy(0, 27);
			cout << "Please enter a valid name! ";
			gotoxy(53, 18);
			cin.getline(playerName, 50);
		}
	
		
		gotoxy(35, 20);
		cout << "Enter your ID:  ";
		cin.getline(playerID, 20);
		while(playerID[0] == '\0'){
			gotoxy(0, 27);
			cout << "Please enter a valid ID! ";
			gotoxy(51, 20);
			cin.getline(playerID, 20);
		}

		gotoxy(35, 22);
		cout << "Enter your class's name:  ";
		cin.getline(playerClass, 20);
		
		// Check for empty input
		while (playerClass[0] == '\0') {
			gotoxy(0, 27);
			cout << "Please enter a valid class name! ";
			gotoxy(61, 22);
			cin.getline(playerClass, 20);
		
		}
	saveData();
	system("cls");
		
}

	


void Game::saveData() {
    std::ofstream outfile("player_info.dat", std::ios::binary|ios::out|ios::app);
    if (!outfile) {
        std::cerr << "Failed to open file for writing.\n";
        return;
    } 
//	char playerID = '\0';
	
	// Convert _mode to char
    char modeChar[20];
    switch (_mode) {
        case _EASY:
            strcpy(modeChar, "Easy");
            break;
        case _MEDIUM:
            strcpy(modeChar, "Medium");
            break;
        case _HARD:
            strcpy(modeChar, "Hard");
            break;
        default:
            modeChar[0] = '\0';
            break;
    }
    // Write data to binary file
    outfile.write(reinterpret_cast<char *>(&playerName), sizeof(playerName));
	outfile.write(reinterpret_cast<char *>(&playerID), sizeof(playerID));
    outfile.write(reinterpret_cast<char *>(&playerClass), sizeof(playerClass));
    outfile.write(reinterpret_cast<char *>(&modeChar), sizeof(modeChar));
    
	
    outfile.close();
   
    system("cls");
}

void Game::savePoint(int &point){
	
    std::ofstream file("point.bin", std::ios::binary|ios::out|ios::app);
    if(!file){
        std::cerr << "Error: could not open file for writing\n";
        return; 
    }
    file.write(reinterpret_cast<char *>(&point), sizeof(point));
    file.close();
}
int getConsoleinput(){
	int c = _getch();
	// Arrow key
	if (c == 0 || c == 224)
	{
		switch (_getch())
		{
		case KEY_UP:				//lên
			return 2;
		case KEY_LEFT:				//trái
			return 3;
		case KEY_RIGHT:				//phải
			return 4;
		case KEY_DOWN:				//xuống
			return 5;
		default:				//nút khác
			return 0;
		}
	}
	else
	{
		if (c == KEY_ESC)                  //esc
			return 1;
		else if (c == 87 || c == 119) //W, w
			return 2;
		else if (c == 65 || c == 97)  //A, a
			return 3;
		else if (c == 68 || c == 100) //D, d
			return 4;
		else if (c == 83 || c == 115) //S, s
			return 5;
		else if (c == 13)             //Enter
			return 6;
		else if (c == 72 || c == 104) //H, h
			return 7;
		else if (c == 77 || c == 109) // M, m
			return 8;
		else
			return 0;                 //nút khác
	}
}

void exitscreen(){
	system("cls");
	ShowCursor(false);
	
	
	
	printrectangle(34, 13, 35, 8);
	printrectangle(37, 18, 7, 2);
	printrectangle(60, 18, 6, 2);
	
	gotoxy(0, 0);
	
	gotoxy(42, 16);
	cout << "Do you want to exit?";
	string str[2] = { "Yes", "No" };
	int left[] = { 35,40,47,58,63,69 }, word[] = { 32,32,175,174 }, color[] = { BLACK, RED }, top = 19;
	bool choice = 0;
	bool loop = 1;
	bool exitProgram = false; // new variable
	auto print1 = [&]()
	{
		int i = 0;
		while (i < 2)
		{
			PlaySound("music\\click.wav", NULL, SND_ASYNC);
			
			gotoxy(left[choice * 3], top);        putchar(word[i * 2]);
			gotoxy(left[choice * 3 + 1], top);    cout << str[choice];
			gotoxy(left[choice * 3 + 2], top);    putchar(word[i * 2 + 1]);
			if (!i++)
				choice = !choice;
		}
		exitProgram = (choice == 0); // update exitProgram variable
	};
	print1();
	while (loop)
	{
		int key = getConsoleinput();
		if ((key == 3 && choice == 1) || (key == 4 && choice == 0))
		{	
			print1();
		}
		else if (key == 6)
        {
            if (!choice)
            {   
                
                system("cls");
                exitProgram = true;
                break;
            }
            
            else // add this else block to change color back to default
            {
            	system("cls");
                ShowCursor(false);	
                setConsolecolor(LIGHT_YELLOW, BLACK); 
                return;
            }
        }
	}
	if (exitProgram) // check if user wants to exit
		exit(0);
	else
		return;
//		else
//		{
//			Controller::playSound(ERROR_SOUND);
//		}
	
}
void instructionscreen(){
	ShowCursor(false);
	
	system("cls");
	int left = 5, top = 2, width = 85, height = 23;
	int line1 = 6, line2 = 19, line3 = 20, line4 = 15;
	printrectangle(left, top, width, height);
	gotoxy(left + 1, line1);
	for (int i = 0; i < width; i++)
	{
		putchar(196);
	}
	gotoxy(left + 1, line2);
	for (int i = 0; i < width; i++)
	{
		putchar(196);
	}
	gotoxy(left + 1, line4);
	for (int i = 0; i < width; i++)
	{
		putchar(196);
	}
	for (int i = 1; i < height; i++)
	{
		gotoxy(line3, top + i);
		putchar(179);
	}
	gotoxy(line3, line1);
	putchar(197);
	gotoxy(line3, line2);
	putchar(197);

	gotoxy(left + 3, top + 2);
	setcolor(White);
	
	cout << "Moves:";
	gotoxy(left + 20, top + 1);
	setcolor(Cyan);
	
	putchar(249); cout << "Up:    W, up arrow";
	gotoxy(left + 52, top + 1);
	setcolor(Cyan);
	putchar(249); cout << "Down:  S, down arrow";
	gotoxy(left + 20, top + 3);
	setcolor(Cyan);
	putchar(249); cout << "Left:  A, left arrow";
	gotoxy(left + 52, top + 3);
	setcolor(Cyan);
	putchar(249); cout << "Right: D, right arrow";
	
	
	gotoxy(left + 3, top + 8);
	setcolor(White);
	cout << "Rules:";
	gotoxy(left + 17, top + 5);
	int left1 = left + 17;
	
	setcolor(Orange);
	putchar(249); cout << " The Matching Game (commonly known as the Pikachu Puzzle Game)";
	gotoxy(left1, top + 6);
	cout << " includes a board of multiple cells, each of which presents a figure.";
	gotoxy(left1, top + 8);
	setcolor(Orange);
	putchar(249); cout << " The player finds and matches a pair of cells that contain the same";
	gotoxy(left1, top + 9);
	cout << " figure and connect each other in some particular pattern.";
	gotoxy(left1, top + 11);
	setcolor(Orange);
	putchar(249); cout << " A legal match will make the two cells disappear. The game ends when";
	gotoxy(left1, top + 12);
	cout << " all matching pairs are found.";
	setcolor(Orange);
	gotoxy(left + 3, top + 15);
	setcolor(White);
	cout << "Scoring:";
	

	gotoxy(left1 + 10, top + 14);
	putchar(249); cout << " I Matching: +3 points";
	
	gotoxy(left1 + 40, top + 14);
	putchar(249); cout << " L Matching: +3 points";
	setcolor(Yellow);
	gotoxy(left1 + 10, top + 15);
	putchar(249); cout << " Z Matching: +3 points";
	setcolor(Green);
	gotoxy(left1 + 40, top + 15);
	putchar(249); cout << " U Matching: +3 points";
	
	setcolor(Red);
	gotoxy(left1 + 10, top + 16);
	putchar(249); cout << " Not Matched: -3 points";
	
	setcolor(Red);
	gotoxy(left1 + 40, top + 16);
	putchar(249); cout << " Move suggestion: -2 points";
	
	
	gotoxy(left + 3, top + 20);
	setcolor(White);
	cout << "Developers:";
	gotoxy(left + 31, top + 19);
	setcolor(Teal);
	cout << "Dev 1: Nguyen Bao Long (22127243))";
	gotoxy(left + 31, top + 21);
	setcolor(Teal);
	cout << "Dev 2: Bui Minh Quan (22127342)";


	// code for the "Back" button
	printrectangle(45, 27, 8, 2);
	gotoxy(43, 28);
	putchar(175);
	gotoxy(48, 28);
	setcolor(Red);
	cout << "Back";
	gotoxy(56, 28);
	putchar(174);
	// wait for user input
	while (true) {
   		if (_kbhit()) {
        	char c = _getch();
        if (c == 'B' || c == 'b' || c == '\r') {  // check if the user pressed "B" or "b"
            system("cls");
            setConsolecolor(LIGHT_YELLOW, BLACK); 
            break;
        }
    }
}
//	while (getConsoleInput() != 6)
//	{
//		Controller::playSound(ERROR_SOUND);
//	}
}


////////////////////////////GAME CHECK///////////////////////////////////


bool linecheck(pokemon** map, int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        int y, x, dem = 0;
        x = min(y1, y2);
        y = max(y1, y2);
        for (int i = x; i <= y; i++) {
            if (map[x1][i].isValid) {
                dem++;
                if (dem == 2) return false;
            }
        }
        if ((dem == 1) && ((!map[x1][y1].isValid && map[x2][y2].isValid) || (map[x1][y1].isValid && !map[x2][y2].isValid))) {//sai
            return true;
        }
        else if (dem == 0) {
            return true;
        }
        return false;
    }
    if (y1 == y2) {
        int x, y, dem = 0;
        x = min(x1, x2);
        y = max(x1, x2);
        for (int i = x; i <= y; i++) {
            if (map[i][y1].isValid) {
                dem++;
                if (dem == 2) return false;
            }
        }
        if ((dem == 1) && ((!map[x1][y1].isValid && map[x2][y2].isValid) || (map[x1][y1].isValid && !map[x2][y2].isValid))) {//sai
            return true;
        }
        else if (dem == 0) {
            return true;
        }
        return false;
    }
    return false;
}


bool Icheck(pokemon** map, int x1, int y1, int x2, int y2) {
    if (x1 == x2) {

    for (int i = min(y1, y2) + 1; i < max(y1, y2); i++) {
        if (map[x1][i].isValid) {
            return false;
        }
    }
    return true;
    }
    else if (y1 == y2) {

    for (int i = min(x1, x2) + 1; i < max(x1,x2); i++) {
        if (map[i][y1].isValid) {
            return false;
        }
    }
    return true;
    }
    return false;
}

bool Lcheck(pokemon** map, int x1, int y1, int x2, int y2) {
    if (x1 == x2 || y1 == y2) {
        return false;
    }
    bool check1, check2;
    if (!map[x1][y2].isValid) {
        check1 = Icheck(map, x1, y1, x1, y2);
        check2 = Icheck(map, x2, y2, x1, y2);
        if (check1 && check2) {
            return true;
        }
    }
    if (!map[x2][y1].isValid) {
        check1 = Icheck(map, x1, y1, x2, y1);
        check2 = Icheck(map, x2, y2, x2, y1);
        if (check1 && check2) {
            return true;
        }
    }
    return false;
}



bool Zcheck(pokemon** map, int x1, int y1, int x2, int y2)
{
    if (x1 == x2 || y1 == y2)
        return false;
    bool check1, check2, check3;
    for (int i = min(y1, y2) + 1; i < max(y1, y2); i++)
    {
        check1 = Icheck(map, x1, y1, x1, i);
        check2 = Icheck(map, x1, i, x2, i);
        check3 = Icheck(map, x2, y2, x2, i);
        if (check1 && check2 && check3 && !map[x1][i].isValid && !map[x2][i].isValid)
            return true;
    }
    for (int i = min(x1, x2) + 1; i < max(x1, x2); i++)
    {
        check1 = Icheck(map, x1, y1, i, y1);
        check2 = Icheck(map, i, y1, i, y2);
        check3 = Icheck(map, x2, y2, i, y2);
        if (check1 && check2 && check3 && !map[i][y1].isValid && !map[i][y2].isValid)
            return true;
    }
    return false;
}
// Ucheck for easy level (4x4 size)
bool UcheckEasyLevel(pokemon** map, int x1, int y1, int x2, int y2) {
    if (((x1 == x2) && (x1 == 1 || x1 == 6 - 2) || ((y1 == y2) && (y1 == 1 || y2 == 6 - 2)))) {
        return true;
    }
    bool c1, c2, c3;
    int x, y;

    x = min(y2, y1);
    y = max(y2, y1);
    for (int i = 1; i < 6 - 1; i++) {
        if (i <= x || i >= y) {
            c3 = linecheck(map, x1, i, x2, i);
            if (c3) {
                c1 = linecheck(map, x1, y1, x1, i);
                c2 = linecheck(map, x2, y2, x2, i);
                if (c1 && c2) {
                    return true;
                }
            }
            else if (i == 1 || i == (6 - 2)) {
                c1 = linecheck(map, x1, y1, x1, i);
                c2 = linecheck(map, x2, y2, x2, i);
                if ((c1 && c2) || (c1 && y2 == i) || (y1 == i && c2)) {
                    return true;
                }
            }
        }
    }


    for (int i = 1; i < 6 - 1; i++) {
        if (i <= x || i >= y) {
            c3 = linecheck(map, i, y1, i, y2);
            if (c3) {
                c1 = linecheck(map, x1, y1, i, y1);
                c2 = linecheck(map, x2, y2, i, y2);
                if (c1 && c2) {
                    return true;
                }
            }
            else if (i == 1 || i == (6 - 2)) {
                c1 = linecheck(map, x1, y1, i, y1);
                c2 = linecheck(map, x2, y2, i, y2);
                if ((c1 && c2) || (c1 && x2 == i) || (x1 == i && c2)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool UcheckMedLevel(pokemon** map, int x1, int y1, int x2, int y2) {
    if (((x1 == x2) && (x1 == 1 || x1 == 8 - 2) || ((y1 == y2) && (y1 == 1 || y2 == 8-2)))) {
        return true;
    }
    bool c1, c2, c3;
    int x, y;

    x = min(y2, y1);
    y = max(y2, y1);
    for (int i = 1; i < 8 - 1; i++) {
        if (i <= x || i >= y) {
            c3 = linecheck(map, x1, i, x2, i);
            if (c3) {
                c1 = linecheck(map, x1, y1, x1, i);
                c2 = linecheck(map, x2, y2, x2, i);
                if (c1 && c2) {
                    return true;
                }
            }
            else if (i == 1 || i == (8 - 2)) {
                c1 = linecheck(map, x1, y1, x1, i);
                c2 = linecheck(map, x2, y2, x2, i);
                if ((c1 && c2) || (c1 && y2 == i) || (y1 == i && c2)) {
                    return true;
                }
            }
        }
    }


    for (int i = 1; i < 8 - 1; i++) {
        if (i <= x || i >= y) {
            c3 = linecheck(map, i, y1, i, y2);
            if (c3) {
                c1 = linecheck(map, x1, y1, i, y1);
                c2 = linecheck(map, x2, y2, i, y2);
                if (c1 && c2) {
                    return true;
                }
            }
            else if (i == 1 || i == (8-2)) {
                c1 = linecheck(map, x1, y1, i, y1);
                c2 = linecheck(map, x2, y2, i, y2);
                if ((c1 && c2) || (c1 && x2 == i) || (x1 == i && c2)) {
                    return true;
                }
            }
        }
    }
    return false;
}
bool UcheckHardLevel(pokemon** map, int x1, int y1, int x2, int y2) {
    if (((x1 == x2) && (x1 == 1 || x1 == 10 - 2) || ((y1 == y2) && (y1 == 1 || y2 == 10-2)))) {
        return true;
    }
    bool c1, c2, c3;
    int x, y;

    x = min(y2, y1);
    y = max(y2, y1);
    for (int i = 1; i < 10 - 1; i++) {
        if (i <= x || i >= y) {
            c3 = linecheck(map, x1, i, x2, i);
            if (c3) {
                c1 = linecheck(map, x1, y1, x1, i);
                c2 = linecheck(map, x2, y2, x2, i);
                if (c1 && c2) {
                    return true;
                }
            }
            else if (i == 1 || i == (10 - 2)) {
                c1 = linecheck(map, x1, y1, x1, i);
                c2 = linecheck(map, x2, y2, x2, i);
                if ((c1 && c2) || (c1 && y2 == i) || (y1 == i && c2)) {
                    return true;
                }
            }
        }
    }


    for (int i = 1; i < 10 - 1; i++) {
        if (i <= x || i >= y) {
            c3 = linecheck(map, i, y1, i, y2);
            if (c3) {
                c1 = linecheck(map, x1, y1, i, y1);
                c2 = linecheck(map, x2, y2, i, y2);
                if (c1 && c2) {
                    return true;
                }
            }
            else if (i == 1 || i == (10-2)) {
                c1 = linecheck(map, x1, y1, i, y1);
                c2 = linecheck(map, x2, y2, i, y2);
                if ((c1 && c2) || (c1 && x2 == i) || (x1 == i && c2)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool allCheckEasy(pokemon** map, int x1, int y1, int x2, int y2) {

    if (Icheck(map, x1, y1, x2, y2)) {
        return true;
    }
    else if (Lcheck(map, x1, y1, x2, y2)) {
        return true;
    }
    else if (Zcheck(map, x1, y1, x2, y2)) {
        return true;
    }
    else if (UcheckEasyLevel(map, x1, y1, x2, y2)) {
        return true;
    }
    return false;
}
bool allCheckMedium(pokemon** map, int x1, int y1, int x2, int y2) {

    if (Icheck(map, x1, y1, x2, y2)) {
        return true;
    }
    else if (Lcheck(map, x1, y1, x2, y2)) {
        return true;
    }
    else if (Zcheck(map, x1, y1, x2, y2)) {
        return true;
    }
    else if (UcheckMedLevel(map, x1, y1, x2, y2)) {
        return true;
    }
    return false;
}
bool allCheckHard(pokemon** map, int x1, int y1, int x2, int y2) {

    if (Icheck(map, x1, y1, x2, y2)) {
        return true;
    }
    else if (Lcheck(map, x1, y1, x2, y2)) {
        return true;
    }
    else if (Zcheck(map, x1, y1, x2, y2)) {
        return true;
    }
    else if (UcheckHardLevel(map, x1, y1, x2, y2)) {
        return true;
    }
    return false;
}

bool checkValidPairsEasyLevel(pokemon** map, int height, int width) 
{	
	const int heightMed = 6, widthMed = 6;
    char check = 'A';
    while (check >= 'A' && check <= 'Z') {
        int cnt = 0;
        int* pos = new int[heightMed * widthMed];
        for (int i = 1; i < heightMed - 1; i++) {
            for (int j = 1; j < widthMed - 1; j++) {
                if (map[i][j].chr == check && map[i][j].isValid) {
                    pos[cnt++] = i;
                    pos[cnt++] = j;
                }
            }
        }
        for (int i = 0; i < cnt - 2; i += 2) {
            for (int j = i + 2; j < cnt; j += 2) {
                if (allCheckEasy(map, pos[i], pos[i + 1], pos[j], pos[j + 1])) {
                    delete[] pos;
                    
                    return true;
                }
            }
        }
        check++;
        delete[] pos;
    }
    return false;
}
bool checkValidPairsMediumLevel(pokemon** map, int height, int width) 
{	
	const int heightMed = 8, widthMed = 8;
    char check = 'A';
    while (check >= 'A' && check <= 'Z') {
        int cnt = 0;
        int* pos = new int[heightMed * widthMed];
        for (int i = 1; i < heightMed - 1; i++) {
            for (int j = 1; j < widthMed - 1; j++) {
                if (map[i][j].chr == check && map[i][j].isValid) {
                    pos[cnt++] = i;
                    pos[cnt++] = j;
                }
            }
        }
        for (int i = 0; i < cnt - 2; i += 2) {
            for (int j = i + 2; j < cnt; j += 2) {
                if (allCheckMedium(map, pos[i], pos[i + 1], pos[j], pos[j + 1])) {
                    delete[] pos;
                    return true;
                }
            }
        }
        check++;
        delete[] pos;
    }
    return false;
}
bool checkValidPairsHardLevel(pokemon** map, int height, int width) 
{	
	const int heightMed = 10, widthMed = 10;
    char check = 'A';
    while (check >= 'A' && check <= 'Z') {
        int cnt = 0;
        int* pos = new int[heightMed * widthMed];
        for (int i = 1; i < heightMed - 1; i++) {
            for (int j = 1; j < widthMed - 1; j++) {
                if (map[i][j].chr == check && map[i][j].isValid) {
                    pos[cnt++] = i;
                    pos[cnt++] = j;
                }
            }
        }
        for (int i = 0; i < cnt - 2; i += 2) {
            for (int j = i + 2; j < cnt; j += 2) {
                if (allCheckHard(map, pos[i], pos[i + 1], pos[j], pos[j + 1])) {
                    delete[] pos;
                    return true;
                }
            }
        }
        check++;
        delete[] pos;
    }
    return false;
}
bool gameOver(pokemon** map, int height, int width)
{
    int dem = 0;
    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            if (map[i][j].isValid == 1)
                return false;
        }
    }

    return true;
}
//////////////////////////////////////////////
void moveSuggestionEasyLevel(pokemon** map, position guidePos[], int height, int width)
{   
	const int heightEz = 6; 
	const int widthEz = 6;
    for (int i = 1; i < heightEz - 1; i++)
    {
        for (int j = 1; j < widthEz - 1; j++)
        {
            if (!map[i][j].isValid)
                continue;
            
            for (int k = 1; k < heightEz - 1; k++)
            {
                for (int l = 1; l < widthEz - 1; l++)
                {
                    if (i == k && l == j)
                        continue;
                    if (map[k][l].isValid == false)
                        continue;
                    if (map[i][j].chr == map[k][l].chr)
                    {
                        if (allCheckEasy(map, i, j, k, l) == true)
                        {
                            guidePos[0].x = j;
                            guidePos[0].y = i;
                            guidePos[1].x = l;
                            guidePos[1].y = k;
                            return;
                        }
                    }
                }
            }
        }
    }
    
}
void moveSuggestionMediumLevel(pokemon** map, position guidePos[])
{   
	const int heightEz = 8; 
	const int widthEz = 8;
    for (int i = 1; i < heightEz - 1; i++)
    {
        for (int j = 1; j < widthEz - 1; j++)
        {
            if (!map[i][j].isValid)
                continue;
            
            for (int k = 1; k < heightEz - 1; k++)
            {
                for (int l = 1; l < widthEz - 1; l++)
                {
                    if (i == k && l == j)
                        continue;
                    if (map[k][l].isValid == false)
                        continue;
                    if (map[i][j].chr == map[k][l].chr)
                    {
                        if (allCheckMedium(map, i, j, k, l) == true)
                        {
                            guidePos[0].x = j;
                            guidePos[0].y = i;
                            guidePos[1].x = l;
                            guidePos[1].y = k;
                            return;
                        }
                    }
                }
            }
        }
    }
    
}
void moveSuggestionHardLevel(pokemon** map, position guidePos[])
{   
	const int heightEz = 10; 
	const int widthEz = 10;
    for (int i = 1; i < heightEz - 1; i++)
    {
        for (int j = 1; j < widthEz - 1; j++)
        {
            if (!map[i][j].isValid)
                continue;
            
            for (int k = 1; k < heightEz - 1; k++)
            {
                for (int l = 1; l < widthEz - 1; l++)
                {
                    if (i == k && l == j)
                        continue;
                    if (map[k][l].isValid == false)
                        continue;
                    if (map[i][j].chr == map[k][l].chr)
                    {
                        if (allCheckMedium(map, i, j, k, l) == true)
                        {
                            guidePos[0].x = j;
                            guidePos[0].y = i;
                            guidePos[1].x = l;
                            guidePos[1].y = k;
                            return;
                        }
                    }
                }
            }
        }
    }
    
}
void Game::moveEasy(pokemon** map, position& pos, int& status, player& p, position selectedPos[], int& couple, int heightEz, int widthEz) {
    
	int temp, key;
    temp = _getch();
//	const int height = 6;
//	const int width = 6;
    if (temp == 77 || temp == 109) 
    {
        if (p.hint == 0)
        {
            return;
        }

        position guidePos[2] = {{0,0},{0,0}};
        moveSuggestionEasyLevel(map, guidePos, 6, 6);

        map[guidePos[0].y][guidePos[0].x].isSelected = 1;
        map[guidePos[1].y][guidePos[1].x].isSelected = 1;

        map[guidePos[0].y][guidePos[0].x].drawPlayingBox(100);
        map[guidePos[1].y][guidePos[1].x].drawPlayingBox(100);

        Sleep(500);

        map[guidePos[0].y][guidePos[0].x].isSelected = 0;
        map[guidePos[1].y][guidePos[1].x].isSelected = 0;

        renderBoardEasy(map, height, width);

        p.hint--;
        p.point -= 2;
        gotoxy(80, 17);
        cout << p.point;
        gotoxy(71, 18);
        cout << p.hint;
    }
    if (temp && temp != 224) 
    { // neu ko phai la dau mui ten
        if (temp == ESC_KEY) // neu la ESC
        {
            exitscreen();
        }
        else if (temp == 'h' || temp == 'H'){
        	instructionscreen();       	
		}
        else if (temp == ENTER_KEY || temp == SPACE_KEY) { // neu la Enter
            if (pos.x == selectedPos[0].x && pos.y == selectedPos[0].y) {
                map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(70);
                Sleep(500);

                map[selectedPos[0].y][selectedPos[0].x].isSelected = 0;
                couple = 2;
                selectedPos[0] = { -1, -1 };
                p.life--;
                gotoxy(71, 19);
                cout << p.life;
                if(p.life == 0){
                	printLoseEasy();
				}
            } // kiem tra lap lai
            else {
                selectedPos[2 - couple].x = pos.x;
                selectedPos[2 - couple].y = pos.y;
                map[pos.y][pos.x].isSelected = 1;
                couple--;

                if (couple == 0) { // neu da chon 1 cap
                    if (map[selectedPos[0].y][selectedPos[0].x].chr == map[selectedPos[1].y][selectedPos[1].x].chr) {  // neu cap nay hop nhau
                        if (allCheckEasy(map, selectedPos[0].y, selectedPos[0].x, selectedPos[1].y, selectedPos[1].x)) {
                            PlaySound("music\\ye.wav", NULL, SND_ASYNC);
							p.point += 3;
                            gotoxy(80, 17);
                            cout << "          ";
                            gotoxy(80, 17);
                            cout << p.point;

                            map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(40);
                            map[selectedPos[1].y][selectedPos[1].x].drawPlayingBox(40);
                            Sleep(500);

                            map[selectedPos[0].y][selectedPos[0].x].isValid = 0;
                            map[selectedPos[0].y][selectedPos[0].x].deleteBox();
                            //if (selectedPos[0].x < 4) displayBackground(bg, selectedPos[0].x, selectedPos[0].y);

                            map[selectedPos[1].y][selectedPos[1].x].isValid = 0;
                            map[selectedPos[1].y][selectedPos[1].x].deleteBox();
                            //if (selectedPos[1].x < 4) displayBackground(bg, selectedPos[1].x, selectedPos[1].y);
                        }
                        else {
                            map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(70);
                            map[selectedPos[1].y][selectedPos[1].x].drawPlayingBox(70);
                            Sleep(500);
							PlaySound("music\\no.wav", NULL, SND_ASYNC);
                            p.point -= 3;
                            gotoxy(80, 17);
                            cout << "          ";
                            gotoxy(80, 17);
                            cout << p.point;

                            p.life--;
                            gotoxy(71, 19);
                            cout << p.life;
                            if(p.life == 0){
			                	printLoseEasy();
							}
                        }
                    }
                    else {
                        map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(70);
                        map[selectedPos[1].y][selectedPos[1].x].drawPlayingBox(70);
                        Sleep(500);
                        PlaySound("music\\no.wav", NULL, SND_ASYNC);
                        p.point -= 3;
                        gotoxy(80, 17);
                        cout << "          ";
                        gotoxy(80, 17);
                        cout << p.point;

                        p.life--;
                        gotoxy(71, 19);
                        cout << p.life;
                        if(p.life == 0){
			               	printLoseEasy();
						}
                    }
                    // tra ve noi san xuat
                    map[selectedPos[0].y][selectedPos[0].x].isSelected = 0;
                    map[selectedPos[1].y][selectedPos[1].x].isSelected = 0;
                    couple = 2;
                    selectedPos[0] = { -1, -1 };
                    selectedPos[1] = { -1, -1 };

                    for (int i = pos.y; i < heightEz - 1; i++) {
                        for (int j = pos.x; j < widthEz - 1; j++) {
                            if (map[i][j].isValid) {
                                pos.x = j;
                                pos.y = i;
                                return;
                            }
                        }
                    }

                    for (int i = 1; i <= pos.y; i++) { // chuyen den CELL_1 o tren
                        for (int j = 1; j <= pos.x; j++) {
                            if (map[i][j].isValid) {
                                pos.x = j;
                                pos.y = i;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    else //neu la dau mui ten
    {
        if ((pos.y != selectedPos[0].y || pos.x != selectedPos[0].x) && (pos.y != selectedPos[1].y || pos.x != selectedPos[1].x)) // ktra xem o nay co dang duoc chon hay khong
            map[pos.y][pos.x].isSelected = 0;
        switch (key = _getch())
        {
        case KEY_UP:
            for (int i = pos.x; i < widthEz - 1; i++) {
                for (int j = pos.y - 1; j > 0; j--) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\click.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i > 0; i--) {
                for (int j = pos.y - 1; j > 0; j--) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\click.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.x; i < widthEz - 1; i++) {
                for (int j = heightEz - 1; j > pos.y; j--) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\click.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.x; i > 0; i--) {
                for (int j = heightEz - 1; j > pos.y; j--) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\click.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            break;
        case KEY_DOWN:
            for (int i = pos.x; i < widthEz - 1; i++) {
                for (int j = pos.y + 1; j < heightEz - 1; j++) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\click.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i > 0; i--) {
                for (int j = pos.y + 1; j < heightEz - 1; j++) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\click.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.x; i < widthEz - 1; i++) {
                for (int j = 1; j < pos.y; j++) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\click.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i > 0; i--) {
                for (int j = 1; j < pos.y; j++) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\click.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }
            break;
        case KEY_LEFT:
            for (int i = pos.y; i > 0; i--) {
                for (int j = pos.x - 1; j > 0; j--) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\click.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < heightEz - 1; i++) {
                for (int j = pos.x - 1; j > 0; j--) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\click.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.y; i > 0; i--) {
                for (int j = widthEz - 1; j > pos.x; j--) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\click.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < heightEz - 1; i++) {
                for (int j = widthEz - 2; j > pos.x; j--) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\click.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }
            break;
        case KEY_RIGHT:
            for (int i = pos.y; i > 0; i--) {
                for (int j = pos.x + 1; j < widthEz - 1; j++) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\click.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < heightEz - 1; i++) {
                for (int j = pos.x + 1; j < widthEz - 1; j++) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\click.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.y; i > 0; i--) {
                for (int j = 1; j < pos.x; j++) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\click.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < heightEz - 1; i++) {
                for (int j = 1; j < pos.x; j++) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\click.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }
         
        default:
            break;
        }
    }
    
}
void Game::moveMedium(pokemon** map, position& pos, int& status, player& p, position selectedPos[], int& couple) {
    
	int temp, key;
    temp = _getch();
	const int height = 8;
	const int width = 8;
    if (temp == 77 || temp == 109) 
    {
        if (p.hint == 0)
        {
            return;
        }

        position guidePos[2] = {{0,0},{0,0}};
        moveSuggestionMediumLevel(map, guidePos);

        map[guidePos[0].y][guidePos[0].x].isSelected = 1;
        map[guidePos[1].y][guidePos[1].x].isSelected = 1;

        map[guidePos[0].y][guidePos[0].x].drawPlayingBox(100);
        map[guidePos[1].y][guidePos[1].x].drawPlayingBox(100);

        Sleep(500);

        map[guidePos[0].y][guidePos[0].x].isSelected = 0;
        map[guidePos[1].y][guidePos[1].x].isSelected = 0;

        renderBoardMedium(map, height, width);

        p.hint--;
        p.point -= 2;
        gotoxy(96, 17);
        cout << p.point;
        gotoxy(87, 18);
        cout << p.hint;
        //gotoxy(100, 1);
        //cout << "suggest y1: " << guidePos[1].y;
        //gotoxy(100, 2);
        //cout << "suggest x1: " << guidePos[1].x;
        //gotoxy(100, 3);
        //cout << "suggest y2: " << guidePos[0].y;
        //gotoxy(100, 4);
        //cout << "suggest x2: " << guidePos[0].x;
    }
    if (temp && temp != 224) 
    { // neu ko phai la dau mui ten
        if (temp == ESC_KEY) // neu la ESC
        {
            exitscreen();
        }
        else if (temp == 'h' || temp == 'H'){
         instructionscreen();       	
		}
        else if (temp == ENTER_KEY || temp == SPACE_KEY) { // neu la Enter
            if (pos.x == selectedPos[0].x && pos.y == selectedPos[0].y) {
                map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(70);
                Sleep(500);

                map[selectedPos[0].y][selectedPos[0].x].isSelected = 0;
                couple = 2;
                selectedPos[0] = { -1, -1 };
                p.life--;
                gotoxy(87, 19);
                cout << p.life;
                if(p.life == 0){
                	printLoseMedium();
				}
            } // kiem tra lap lai
            else {
                selectedPos[2 - couple].x = pos.x;
                selectedPos[2 - couple].y = pos.y;
                map[pos.y][pos.x].isSelected = 1;
                couple--;

                if (couple == 0) { // neu da chon 1 cap
                    if (map[selectedPos[0].y][selectedPos[0].x].chr == map[selectedPos[1].y][selectedPos[1].x].chr) {  // neu cap nay hop nhau
                        if (allCheckMedium(map, selectedPos[0].y, selectedPos[0].x, selectedPos[1].y, selectedPos[1].x)) {
                            PlaySound("music\\ye.wav", NULL, SND_ASYNC);
							p.point += 3;
                            gotoxy(96, 17);
                            cout << "          ";
                            gotoxy(96, 17);
                            cout << p.point;

                            map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(40);
                            map[selectedPos[1].y][selectedPos[1].x].drawPlayingBox(40);
                            Sleep(500);

                            map[selectedPos[0].y][selectedPos[0].x].isValid = 0;
                            map[selectedPos[0].y][selectedPos[0].x].deleteBox();
                            //if (selectedPos[0].x < 4) displayBackground(bg, selectedPos[0].x, selectedPos[0].y);

                            map[selectedPos[1].y][selectedPos[1].x].isValid = 0;
                            map[selectedPos[1].y][selectedPos[1].x].deleteBox();
                            //if (selectedPos[1].x < 4) displayBackground(bg, selectedPos[1].x, selectedPos[1].y);
                        }
                        else {
                            map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(70);
                            map[selectedPos[1].y][selectedPos[1].x].drawPlayingBox(70);
                            Sleep(500);
							PlaySound("music\\no.wav", NULL, SND_ASYNC);
                            p.point -= 3;
                            gotoxy(96, 17);
                            cout << "          ";
                            gotoxy(96, 17);
                            cout << p.point;

                            p.life--;
                            gotoxy(87, 19);
                            cout << p.life;
                            if(p.life == 0){
			                	printLoseMedium();
			                	
							}
                        }
                    }
                    else {
                        map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(70);
                        map[selectedPos[1].y][selectedPos[1].x].drawPlayingBox(70);
                        Sleep(500);
                        PlaySound("music\\no.wav", NULL, SND_ASYNC);
                        p.point -= 3;
                        gotoxy(96, 17);
                        cout << "          ";
                        gotoxy(96, 17);
                        cout << p.point;

                        p.life--;
                        gotoxy(87, 19);
                        cout << p.life;
                        if(p.life == 0){
		                	printLoseMedium();
		                	
						}
                    }
                    // tra ve noi san xuat
                    map[selectedPos[0].y][selectedPos[0].x].isSelected = 0;
                    map[selectedPos[1].y][selectedPos[1].x].isSelected = 0;
                    couple = 2;
                    selectedPos[0] = { -1, -1 };
                    selectedPos[1] = { -1, -1 };

                    for (int i = pos.y; i < height - 1; i++) {
                        for (int j = pos.x; j < width - 1; j++) {
                            if (map[i][j].isValid) {
                                pos.x = j;
                                pos.y = i;
                                return;
                            }
                        }
                    }

                    for (int i = 1; i <= pos.y; i++) { // chuyen den CELL_1 o tren
                        for (int j = 1; j <= pos.x; j++) {
                            if (map[i][j].isValid) {
                                pos.x = j;
                                pos.y = i;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    else //neu la dau mui ten
    {
        if ((pos.y != selectedPos[0].y || pos.x != selectedPos[0].x) && (pos.y != selectedPos[1].y || pos.x != selectedPos[1].x)) // ktra xem o nay co dang duoc chon hay khong
            map[pos.y][pos.x].isSelected = 0;
        switch (key = _getch())
        {
        case KEY_UP:
            for (int i = pos.x; i < width - 1; i++) {
                for (int j = pos.y - 1; j > 0; j--) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\pew.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i > 0; i--) {
                for (int j = pos.y - 1; j > 0; j--) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\pew.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.x; i < width - 1; i++) {
                for (int j = height - 1; j > pos.y; j--) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\pew.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.x; i > 0; i--) {
                for (int j = height - 1; j > pos.y; j--) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\pew.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            break;
        case KEY_DOWN:
            for (int i = pos.x; i < width - 1; i++) {
                for (int j = pos.y + 1; j < height - 1; j++) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\pew.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i > 0; i--) {
                for (int j = pos.y + 1; j < height - 1; j++) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\pew.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.x; i < width - 1; i++) {
                for (int j = 1; j < pos.y; j++) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\pew.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i > 0; i--) {
                for (int j = 1; j < pos.y; j++) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\pew.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }
            break;
        case KEY_LEFT:
            for (int i = pos.y; i > 0; i--) {
                for (int j = pos.x - 1; j > 0; j--) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\pew.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < height - 1; i++) {
                for (int j = pos.x - 1; j > 0; j--) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\pew.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.y; i > 0; i--) {
                for (int j = width - 1; j > pos.x; j--) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\pew.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < height - 1; i++) {
                for (int j = width - 2; j > pos.x; j--) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\pew.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }
            break;
        case KEY_RIGHT:
            for (int i = pos.y; i > 0; i--) {
                for (int j = pos.x + 1; j < width - 1; j++) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\pew.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < height - 1; i++) {
                for (int j = pos.x + 1; j < width - 1; j++) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\pew.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.y; i > 0; i--) {
                for (int j = 1; j < pos.x; j++) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\pew.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < height - 1; i++) {
                for (int j = 1; j < pos.x; j++) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\pew.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }
         
        default:
            break;
        }
    }
}
void Game::moveHard(pokemon** map, position& pos, int& status, player& p, position selectedPos[], int& couple) {
    
	int temp, key;
    temp = _getch();
	const int height = 10;
	const int width = 10;
    if (temp == 77 || temp == 109) 
    {
        if (p.hint == 0)
        {
            return;
        }

        position guidePos[2] = {{0,0},{0,0}};
        moveSuggestionHardLevel(map, guidePos);

        map[guidePos[0].y][guidePos[0].x].isSelected = 1;
        map[guidePos[1].y][guidePos[1].x].isSelected = 1;

        map[guidePos[0].y][guidePos[0].x].drawPlayingBox(100);
        map[guidePos[1].y][guidePos[1].x].drawPlayingBox(100);

        Sleep(500);

        map[guidePos[0].y][guidePos[0].x].isSelected = 0;
        map[guidePos[1].y][guidePos[1].x].isSelected = 0;

        renderBoardHard(map, height, width);

        p.hint--;
        p.point -= 2;
        gotoxy(123, 19);
        cout << p.point;
        gotoxy(114, 20);
        cout << p.hint;
        //gotoxy(100, 1);
        //cout << "suggest y1: " << guidePos[1].y;
        //gotoxy(100, 2);
        //cout << "suggest x1: " << guidePos[1].x;
        //gotoxy(100, 3);
        //cout << "suggest y2: " << guidePos[0].y;
        //gotoxy(100, 4);
        //cout << "suggest x2: " << guidePos[0].x;
    }
    if (temp && temp != 224) 
    { // neu ko phai la dau mui ten
        if (temp == ESC_KEY) // neu la ESC
        {
            exitscreen();
        }
        else if (temp == 'h' || temp == 'H'){
         instructionscreen();       	
		}
        else if (temp == ENTER_KEY || temp == SPACE_KEY) { // neu la Enter
            if (pos.x == selectedPos[0].x && pos.y == selectedPos[0].y) {
                map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(70);
                Sleep(500);

                map[selectedPos[0].y][selectedPos[0].x].isSelected = 0;
                couple = 2;
                selectedPos[0] = { -1, -1 };
                p.life--;
                gotoxy(114, 21);
                cout << p.life;
                if(p.life == 0){
                	printLoseHard();
				}
            } // kiem tra lap lai
            else {
                selectedPos[2 - couple].x = pos.x;
                selectedPos[2 - couple].y = pos.y;
                map[pos.y][pos.x].isSelected = 1;
                couple--;

                if (couple == 0) { // neu da chon 1 cap
                    if (map[selectedPos[0].y][selectedPos[0].x].chr == map[selectedPos[1].y][selectedPos[1].x].chr) {  // neu cap nay hop nhau
                        if (allCheckMedium(map, selectedPos[0].y, selectedPos[0].x, selectedPos[1].y, selectedPos[1].x)) {
                        	PlaySound("music\\ye.wav", NULL, SND_ASYNC);
                            p.point += 3;
                            gotoxy(123, 0);
                            cout << "          ";
                            gotoxy(123, 19);
                            cout << p.point;
                            

                            map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(40);
                            map[selectedPos[1].y][selectedPos[1].x].drawPlayingBox(40);
                            Sleep(500);

                            map[selectedPos[0].y][selectedPos[0].x].isValid = 0;
                            map[selectedPos[0].y][selectedPos[0].x].deleteBox();
                            //if (selectedPos[0].x < 4) displayBackground(bg, selectedPos[0].x, selectedPos[0].y);

                            map[selectedPos[1].y][selectedPos[1].x].isValid = 0;
                            map[selectedPos[1].y][selectedPos[1].x].deleteBox();
                            //if (selectedPos[1].x < 4) displayBackground(bg, selectedPos[1].x, selectedPos[1].y);
                        }
                        else {
                            map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(70);
                            map[selectedPos[1].y][selectedPos[1].x].drawPlayingBox(70);
                            Sleep(500);
							PlaySound("music\\no.wav", NULL, SND_ASYNC);
                            p.point -= 3;
                            gotoxy(123, 0);
                            cout << "          ";
                            gotoxy(123, 19);
                            cout << p.point;

                            p.life--;
                            gotoxy(114, 21);
                            cout << p.life;
                            if(p.life == 0){
			                	printLoseHard();
							}
                        }
                    }
                    else {
                        map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(70);
                        map[selectedPos[1].y][selectedPos[1].x].drawPlayingBox(70);
                        Sleep(500);
                        PlaySound("music\\no.wav", NULL, SND_ASYNC);
                        p.point -= 3;
                        gotoxy(123, 0);
                        cout << "          ";
                        gotoxy(123, 19);
                        cout << p.point;

                        p.life--;
                        gotoxy(114, 21);
                        cout << p.life;
                        if(p.life == 0){
		                	printLoseHard();
						}
                    }
                    // tra ve noi san xuat
                    map[selectedPos[0].y][selectedPos[0].x].isSelected = 0;
                    map[selectedPos[1].y][selectedPos[1].x].isSelected = 0;
                    couple = 2;
                    selectedPos[0] = { -1, -1 };
                    selectedPos[1] = { -1, -1 };

                    for (int i = pos.y; i < height - 1; i++) {
                        for (int j = pos.x; j < width - 1; j++) {
                            if (map[i][j].isValid) {
                                pos.x = j;
                                pos.y = i;
                                return;
                            }
                        }
                    }

                    for (int i = 1; i <= pos.y; i++) { // chuyen den CELL_1 o tren
                        for (int j = 1; j <= pos.x; j++) {
                            if (map[i][j].isValid) {
                                pos.x = j;
                                pos.y = i;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    else //neu la dau mui ten
    {
        if ((pos.y != selectedPos[0].y || pos.x != selectedPos[0].x) && (pos.y != selectedPos[1].y || pos.x != selectedPos[1].x)) // ktra xem o nay co dang duoc chon hay khong
            map[pos.y][pos.x].isSelected = 0;
        switch (key = _getch())
        {
        case KEY_UP:
            for (int i = pos.x; i < width - 1; i++) {
                for (int j = pos.y - 1; j > 0; j--) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\ha.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i > 0; i--) {
                for (int j = pos.y - 1; j > 0; j--) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\ha.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.x; i < width - 1; i++) {
                for (int j = height - 1; j > pos.y; j--) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\ha.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.x; i > 0; i--) {
                for (int j = height - 1; j > pos.y; j--) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\ha.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            break;
        case KEY_DOWN:
            for (int i = pos.x; i < width - 1; i++) {
                for (int j = pos.y + 1; j < height - 1; j++) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\ha.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i > 0; i--) {
                for (int j = pos.y + 1; j < height - 1; j++) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\ha.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.x; i < width - 1; i++) {
                for (int j = 1; j < pos.y; j++) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\ha.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i > 0; i--) {
                for (int j = 1; j < pos.y; j++) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        PlaySound("music\\ha.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }
            break;
        case KEY_LEFT:
            for (int i = pos.y; i > 0; i--) {
                for (int j = pos.x - 1; j > 0; j--) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\ha.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < height - 1; i++) {
                for (int j = pos.x - 1; j > 0; j--) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\ha.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.y; i > 0; i--) {
                for (int j = width - 1; j > pos.x; j--) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\ha.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < height - 1; i++) {
                for (int j = width - 2; j > pos.x; j--) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\ha.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }
            break;
        case KEY_RIGHT:
            for (int i = pos.y; i > 0; i--) {
                for (int j = pos.x + 1; j < width - 1; j++) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\ha.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < height - 1; i++) {
                for (int j = pos.x + 1; j < width - 1; j++) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\ha.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.y; i > 0; i--) {
                for (int j = 1; j < pos.x; j++) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\ha.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < height - 1; i++) {
                for (int j = 1; j < pos.x; j++) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        PlaySound("music\\ha.wav", NULL, SND_ASYNC);
                        return;
                    }
                }
            }
         
        default:
            break;
        }
    }
}
//char box[5][12] = {
//            {" --------- "},
//            {"|         |"},
//            {"|         |"},
//            {"|         |"},
//            {" --------- "}
//};
char box[5][12] = {
    {char(218), char(196), char(196), char(196),char(196), char(196), char(196), char(196), char(196), char(196), char(191)},
    {char(179), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(179)},
    {char(179), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(179)},
    {char(179), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(179)},
    {char(192), char(196), char(196), char(196), char(196), char(196), char(196), char(196), char(196), char(196), char(217)}
};


/////////////////GENERATE MAP///////////////////////////////////
void Game::generateMapEasy(pokemon **&map)
{   
    srand((unsigned int)time(NULL));
	const int mapEzHeight = 6; // set map height to 6
    const int mapEzWidth = 6; 
//    map = new pokemon* [mapHeight];

    //Creating a 2D for game array
    for (int i = 0; i < mapEzHeight; i++)
    {
        map[i] = new pokemon [mapEzWidth];
    }

    int timesRandom = 2;

    for (int i = 0; i < mapEzHeight; i++)
    {
        for (int j = 0; j < mapEzWidth; j++)
        {
            if (i == 0 || i == mapEzHeight - 1 || j == 0 || j == mapEzWidth - 1)
                map[i][j].isValid = 1;
        }
    }

    for (int i = 1; i < mapEzHeight - 1; i++)
    {
        for (int j = 1; j < mapEzWidth - 1; j++)
        {
            map[i][j].x = j;
            map[i][j].y = i;
        }
    }


    int totalCell = ((mapEzWidth - 2) * (mapEzHeight - 2)) / 2;

    while (totalCell > 0)
    {
        char randomCharacter = 65 + rand() % 26;
        while (timesRandom > 0)
        {
            int index = rand() % (mapEzWidth * mapEzHeight);
            if (map[index / mapEzWidth][index % mapEzWidth].chr == ' ')
            {
                if (index / mapEzWidth != 0 && index / mapEzWidth != (mapEzHeight - 1) && index % mapEzWidth != 0 && index % mapEzWidth != (mapEzWidth - 1))
                {
                    map[index / mapEzWidth][index % mapEzWidth].chr = randomCharacter;
                    timesRandom--;
                }
            }
        }
        timesRandom = 2;
        totalCell--;
    }
//    printInterface();

			

}
void Game::generateMapMedium(pokemon **&map)
{   
    srand((unsigned int)time(NULL));
    const int mapMedHeight = 8; // set map height to 6
    const int mapMedWidth = 8; // set map width to 6
//    map = new pokemon* [mapMedHeight];

    //Creating a 2D for game array
    for (int i = 0; i < mapMedHeight; i++)
    {
        map[i] = new pokemon [mapMedWidth];
    }

    int timesRandom = 2;

    for (int i = 0; i < mapMedHeight; i++)
    {
        for (int j = 0; j < mapMedWidth; j++)
        {
            if (i == 0 || i == mapMedHeight - 1 || j == 0 || j == mapMedWidth - 1)
                map[i][j].isValid = 1;
        }
    }

    for (int i = 1; i < mapMedHeight - 1; i++)
    {
        for (int j = 1; j < mapMedWidth - 1; j++)
        {
            map[i][j].x = j;
            map[i][j].y = i;
        }
    }


    int totalCell = ((8 - 2) * (8 - 2)) / 2;

    while (totalCell > 0)
    {
        char randomCharacter = 65 + rand() % 26;
        while (timesRandom > 0)
        {
            int index = rand() % (mapMedWidth * mapMedHeight);
            if (map[index / mapMedWidth][index % mapMedWidth].chr == ' ')
            {
                if (index / mapMedWidth != 0 && index / mapMedWidth != (mapMedHeight - 1) && index % mapMedWidth != 0 && index % mapMedWidth != (mapMedWidth - 1))
                {
                    map[index / mapMedWidth][index % mapMedWidth].chr = randomCharacter;
                    timesRandom--;
                }
            }
        }
        timesRandom = 2;
        totalCell--;
    }
    
    
}
void Game::generateMapHard(pokemon **&map)
{   
    srand((unsigned int)time(NULL));
    const int mapHardHeight = 10; // set map height to 10
    const int mapHardWidth = 10; // set map width to 10
//    map = new pokemon* [mapHardHeight];

    //Creating a 2D for game array
    for (int i = 0; i < mapHardHeight; i++)
    {
        map[i] = new pokemon [mapHardWidth];
    }

    int timesRandom = 2;

    for (int i = 0; i < mapHardHeight; i++)
    {
        for (int j = 0; j < mapHardWidth; j++)
        {
            if (i == 0 || i == mapHardHeight - 1 || j == 0 || j == mapHardWidth - 1)
                map[i][j].isValid = 1;
        }
    }

    for (int i = 1; i < mapHardHeight - 1; i++)
    {
        for (int j = 1; j < mapHardWidth - 1; j++)
        {
            map[i][j].x = j;
            map[i][j].y = i;
        }
    }


    int totalCell = ((10 - 2) * (10 - 2)) / 2;

    while (totalCell > 0)
    {
        char randomCharacter = 65 + rand() % 26;
        while (timesRandom > 0)
        {
            int index = rand() % (mapHardWidth * mapHardHeight);
            if (map[index / mapHardWidth][index % mapHardWidth].chr == ' ')
            {
                if (index / mapHardWidth != 0 && index / mapHardWidth != (mapHardHeight - 1) && index % mapHardWidth != 0 && index % mapHardWidth != (mapHardWidth - 1))
                {
                    map[index / mapHardWidth][index % mapHardWidth].chr = randomCharacter;
                    timesRandom--;
                }
            }
        }
        timesRandom = 2;
        totalCell--;
    }
    
}

void deleteMap(pokemon **map)
{
    for (int i = 0; i < mapHeight; i++)
    {
        delete[] * (map + i);
    }
    delete[] map;
}


void printPokemons(pokemon **map)
{
    for (int i = 0; i < mapHeight; i++)
    {
        for (int j = 0; j < mapWidth; j++)
        {
            cout << map[i][j].chr << " ";
        }
        cout << endl;
    }
}


void pokemon::drawPlayingBox(int color)
{   
    if (!isValid)
        return;

    for (int i = 0; i < 5; i++) {
        gotoxy(x * 10, y * 4 + i);
        cout << box[i];
    }

    if (isSelected) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color + (chr % 6 + 1)); // white background
        for (int i = 1; i < 4; i++) {
            gotoxy(x * 10 + 1, y * 4 + i);
            cout << "         ";
        }

        gotoxy(x * 10 + 5, y * 4 + 2);
        cout << chr;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else {
        gotoxy(x * 10 + 5, y * 4 + 2);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), chr % 6 + 1);
        cout << chr;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
}

void pokemon::deleteBox() {
    int xCurrent = x + 1, yCurrent = y + 1;

    for (int i = 0; i < 5; i++) {
        gotoxy(x * 10, y * 4 + i);
        cout << "           ";
    }
}
void pokemon::drawSuggestedBox(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color + (chr % 6 + 1)); // white background
    for (int i = 1; i < 4; i++) {
        gotoxy(x * 10 + 1, y * 4 + i);
        cout << "         ";
    }

    gotoxy(x * 10 + 5, y * 4 + 2);
    cout << chr;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}

void displayTimeRemaining(int counter) {
    COORD pos = { 65, 20 };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD written;
    std::string message = "\rTime remaining: " + std::to_string(counter);
    WriteConsoleOutputCharacterA(output, message.c_str(), message.length(), pos, &written);
}

void Game::renderBoardEasy(pokemon** map, int height, int width) 
{
	int counter = 60; //amount of seconds
    
	const int mapEzHeight = 6; // set map height to 6
    const int mapEzWidth = 6; // set map width to 6
    for (int i = 1; i < mapEzHeight - 1; i++) {
        for (int j = 1; j < mapEzWidth - 1; j++) {
            map[i][j].drawPlayingBox(112);
        }
    }
          
		printrectangle(59, 1, 33, 10);
		printrectangle(59, 12, 33, 10);
		
		printrectangle(60, 2, 31, 2);
	   
		gotoxy(67, 3);
		cout << "PLAYER'S INFORMATION";
		
		gotoxy(65, 5);
		if(playerName[0] == '\0') {
		    strcpy(playerName, "unknown");
		    cout << "Player's name: " << playerName;
		} else {
		    cout << "Player's name: " << playerName;
		}
		gotoxy(65, 7);
		if(playerID[0] == '\0') {
			strcpy(playerName, "unknown");
//		    playerID = -1;
		    cout << "Player's ID: " << playerID;
		} else {
			 cout << "Student's ID: " << playerID;
		}
		gotoxy(65, 9);
		if(playerClass[0] == '\0') {
		    strcpy(playerClass, "unknown");
		    cout << "Class: " << playerClass;
		} else {
		    cout << "Class: " << playerClass;
		}
		
		
		printrectangle(60, 13, 31, 2);
		
		gotoxy(69, 14);
		cout << "GAME INFORMATION";
		
		
		gotoxy(65, 17);
		cout << "Current score:";
		gotoxy(65, 18);
		cout << "Hint: ";
		gotoxy(65,19);
		cout << "Life: ";
		gotoxy(65, 20);
	   
		printrectangle(59, 24, 33, 2);
		printrectangle(59, 27, 14, 2);
		printrectangle(78, 27, 14, 2);
		
		gotoxy(67, 25);
		cout << "M : Move suggestion";
		
		gotoxy(63, 28);
		cout << "H : Help";
		gotoxy(81, 28);
		cout << "Esc : Exit";
		 
	
		
}
		 
void Game::renderBoardMedium(pokemon** map, int height, int width) 
{	
    
	const int mapMedHeight = 8; // set map height to 6
    const int mapMedWidth = 8; // set map width to 6
    for (int i = 1; i < mapMedHeight - 1; i++) {
        for (int j = 1; j < mapMedWidth - 1; j++) {
            map[i][j].drawPlayingBox(112);
        }
    }
    		
		
	    printrectangle(75, 1, 33, 10);
		printrectangle(75, 12, 33, 10);
		
		printrectangle(76, 2, 31, 2);
	   
		gotoxy(83, 3);
		cout << "PLAYER'S INFORMATION";
		
		gotoxy(81, 5);
		if(playerName[0] == '\0') {
		    strcpy(playerName, "unknown");
		    cout << "Player's name: " << playerName;
		} else {
		    cout << "Player's name: " << playerName;
		}
		gotoxy(81, 7);
		if(playerID[0] == '\0') {
			strcpy(playerName, "unknown");
//		    playerID = -1;
		    cout << "Player's ID: " << playerID;
		} else {
			 cout << "Student's ID: " << playerID;
		}
		gotoxy(81, 9);
		if(playerClass[0] == '\0') {
		    strcpy(playerClass, "unknown");
		    cout << "Class: " << playerClass;
		} else {
		    cout << "Class: " << playerClass;
		}
		
		
		printrectangle(76, 13, 31, 2);
		
		gotoxy(85, 14);
		cout << "GAME INFORMATION";
		

		gotoxy(81, 17);
		cout << "Current score:";
		gotoxy(81, 18);
		cout << "Hint: ";
		gotoxy(81,19);
		cout << "Life: ";
		
		printrectangle(75, 24, 33, 2);
		printrectangle(75, 27, 14, 2);
		printrectangle(94, 27, 14, 2);
		
		gotoxy(83, 25);
		cout << "M : Move suggestion";
		
		gotoxy(79, 28);
		cout << "H : Help";
		gotoxy(97, 28);
		cout << "Esc : Exit";
}
void Game::renderBoardHard(pokemon** map, int height, int width) 
{	
	const int mapHardHeight = 10; // set map height to 10
    const int mapHardWidth = 10; // set map width to 10
    for (int i = 1; i < mapHardHeight - 1; i++) {
        for (int j = 1; j < mapHardWidth - 1; j++) {
            map[i][j].drawPlayingBox(112);
        }
    }
    
	    printrectangle(102, 3, 33, 10);
		printrectangle(102, 14, 33, 10);
		
		printrectangle(103, 4, 31, 2);
	   
		gotoxy(110, 5);
		cout << "PLAYER'S INFORMATION";
		
		gotoxy(108, 7);
		if(playerName[0] == '\0') {
		    strcpy(playerName, "unknown");
		    cout << "Player's name: " << playerName;
		} else {
		    cout << "Player's name: " << playerName;
		}
		gotoxy(107, 9);
		if(playerID[0] == '\0') {
			strcpy(playerID, "unknown");
//			playerID = -1;
			cout << "Player's ID: " << playerID;
		} else {
			
		    cout << "Student's ID: " << playerID;
		}
		gotoxy(108, 11);
		if(playerName[0] == '\0') {
		    strcpy(playerClass, "unknown");
		    cout << "Class: " << playerClass;
		} else {
		    cout << "Class: " << playerClass;
		}
		
		
		printrectangle(103, 15, 31, 2);
		
		gotoxy(112, 16);
		cout << "GAME INFORMATION";
		

		gotoxy(108, 19);
		cout << "Current score:";
//		gotoxy(123, 19);
//		cout << score;
		
		gotoxy(108, 20);
		cout << "Hint: ";
		
		gotoxy(108, 21);
		cout << "Life: ";
		
		
		printrectangle(102, 26, 33, 2);
		printrectangle(102, 29, 14, 2);
		printrectangle(120, 29, 14, 2);
		
		gotoxy(106, 27);
		cout << "M : Move suggestion";
		
		gotoxy(106, 30);
		cout << "H : Help";
		gotoxy(124, 30);
		cout << "Esc : Exit";
		ShowCursor(false);
		
}
void drawCongrats(string fileName, int x, int y) {
    ifstream file("text\\congratulations.txt");

    if (file.is_open()) {
        char c;
        int posX = 0, posY = 0;
        while (file.get(c)) {
            if (c == ')' || c == '(' || c == '\\' || c == '/') {
                
                gotoxy(posX, posY);
                setcolor(Yellow);
                cout << c;
                posX++;
            }
            else if (c == '`' || c == '<' || c == '>' || c == '`' || c == '*'){
            	gotoxy(posX, posY);
                setcolor(Orange);
                cout << c;
                posX++;
			}
      		
            else if (c == '\n') {
                posY++;
                posX = x;
            }
            else {
                
                gotoxy(posX, posY);
                setcolor(Red);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}

void Won(string fileName, int x, int y) {
    ifstream file("text\\won.txt");

    if (file.is_open()) {
        char c;
        int posX = 0, posY = 9;
        while (file.get(c)) {
            if (c == '_' || c == '|' || c == '\\' || c == '/' || c == '`' || c == '-' || c == '\'' || c == '.' || c == '\(' || c == ')' ) {
                
                gotoxy(posX, posY);
                setcolor(Orange);
                cout << c;
                posX++;
            }
           
      		
            else if (c == '\n') {
                posY++;
                posX = x;
            }
            else {
                
                gotoxy(posX, posY);
                setcolor(Red);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}
void Lose(string fileName, int x, int y) {
    ifstream file("text\\lose.txt");

    if (file.is_open()) {
        char c;
        int posX = 0, posY = 6;
        while (file.get(c)) {
            if (c == '_' || c == '|' || c == '\\' || c == '/' || c == '`' || c == '-' || c == '\'' || c == '.' || c == '\(' || c == ')' ) {
                
                gotoxy(posX, posY);
                setcolor(Blue);
                cout << c;
                posX++;
            }
           
      		
            else if (c == '\n') {
                posY++;
                posX = x;
            }
            else {
                
                gotoxy(posX, posY);
                setcolor(Red);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}
void Game::printCongratulationBoardEasy(player& p){
	
	system("cls");
	
	gotoxy(0,0);
	drawCongrats("text\\congratulations.txt", 0, 0);
	Won("text\\won.txt", 0, 9);
	
	gotoxy(41, 17);
	cout << "Your score: " << endl;
	gotoxy(53, 17);
	cout << p.point;
	
	savePoint(p.point);
	
	
	
//	gotoxy(0, 0);
//	
//	printlogo();
	setcolor(Cyan);
	printrectangle(34, 19, 35, 8);
	printrectangle(37, 24, 7, 2);
	printrectangle(60, 24, 6, 2);
	gotoxy(40, 22);
	cout << "Do you want to play again?";
	string str[2] = { "Yes", "No" };
	int left[] = { 35,40,47,58,63,69 }, word[] = { 32,32,175,174 }, color[] = { BLACK, GREEN }, top = 19;
	bool choice = 1;
	auto print1 = [&]()
	{
		int i = 0;
		while (i < 2)
		{
			PlaySound("music\\click.wav", NULL, SND_ASYNC | SND_NOSTOP);
			gotoxy(left[choice * 3], top + 6);        putchar(word[i * 2]);
			gotoxy(left[choice * 3 + 1], top + 6);    cout << str[choice];
			gotoxy(left[choice * 3 + 2], top + 6);    putchar(word[i * 2 + 1]);
			if (!i++)
				choice = !choice;
		}
	};
	print1();
	while (true)
	{
		int key = getConsoleinput();
		if ((key == 3 && choice == 1) || (key == 4 && choice == 0))
			print1();
		else if (key == 6)
		{
			if (!choice)
				startGameEasy();
			else
				isPlaying = false;
				system("cls");
				exit(0);
			return;
		}
//		else
//			Controller::playSound(ERROR_SOUND);
//	}
//	playSound(WIN_SOUND);
	
	}
	
 
}
void Game::printCongratulationBoardMedium(player& p){
	
	system("cls");
	
	gotoxy(0,0);
	drawCongrats("text\\congratulations.txt", 0, 0);
	Won("text\\won.txt", 0, 9);

	gotoxy(41, 17);
	cout << "Your score: " << endl;
	gotoxy(53, 17);
	cout << p.point;
	savePoint(p.point);
	
	
	
//	gotoxy(0, 0);
//	
//	printlogo();
	setcolor(Cyan);
	printrectangle(34, 19, 35, 8);
	printrectangle(37, 24, 7, 2);
	printrectangle(60, 24, 6, 2);
	gotoxy(40, 22);
	cout << "Do you want to play again?";
	string str[2] = { "Yes", "No" };
	int left[] = { 35,40,47,58,63,69 }, word[] = { 32,32,175,174 }, color[] = { BLACK, GREEN }, top = 19;
	bool choice = 1;
	auto print1 = [&]()
	{
		int i = 0;
		while (i < 2)
		{
			PlaySound("music\\click.wav", NULL, SND_ASYNC | SND_NOSTOP);
			gotoxy(left[choice * 3], top + 6);        putchar(word[i * 2]);
			gotoxy(left[choice * 3 + 1], top + 6);    cout << str[choice];
			gotoxy(left[choice * 3 + 2], top + 6);    putchar(word[i * 2 + 1]);
			if (!i++)
				choice = !choice;
		}
	};
	print1();
	while (true)
	{
		int key = getConsoleinput();
		if ((key == 3 && choice == 1) || (key == 4 && choice == 0))
			print1();
		else if (key == 6)
		{
			if (!choice)
				startGameEasy();
			else
				isPlaying = false;
				system("cls");
				exit(0);
			return;
		}
//		else
//			Controller::playSound(ERROR_SOUND);
//	}
//	playSound(WIN_SOUND);
	
	}


}
void Game::printCongratulationBoardHard(player& p){
	
system("cls");
	
	gotoxy(0,0);
	drawCongrats("text\\congratulations.txt", 0, 0);
	Won("text\\won.txt", 0, 9);

	gotoxy(41, 17);
	cout << "Your score: " << endl;
	gotoxy(53, 17);
	cout << p.point;
	savePoint(p.point);
	
	
	
//	gotoxy(0, 0);
//	
//	printlogo();
	setcolor(Cyan);
	printrectangle(34, 19, 35, 8);
	printrectangle(37, 24, 7, 2);
	printrectangle(60, 24, 6, 2);
	gotoxy(36, 22);
	cout << "Do you want to play next round?";
	string str[2] = { "Yes", "No" };
	int left[] = { 35,40,47,58,63,69 }, word[] = { 32,32,175,174 }, color[] = { BLACK, GREEN }, top = 19;
	bool choice = 1;
	auto print1 = [&]()
	{
		int i = 0;
		while (i < 2)
		{
			PlaySound("music\\click.wav", NULL, SND_ASYNC | SND_NOSTOP);
			gotoxy(left[choice * 3], top + 6);        putchar(word[i * 2]);
			gotoxy(left[choice * 3 + 1], top + 6);    cout << str[choice];
			gotoxy(left[choice * 3 + 2], top + 6);    putchar(word[i * 2 + 1]);
			if (!i++)
				choice = !choice;
		}
	};
	print1();
	while (true)
	{
		int key = getConsoleinput();
		if ((key == 3 && choice == 1) || (key == 4 && choice == 0))
			print1();
		else if (key == 6)
		{
			if (!choice)
				startGameHard();
			else
				isPlaying = false;
				system("cls");
				exit(0);
			return;
		}
//		else
//			Controller::playSound(ERROR_SOUND);
//	}
//	playSound(WIN_SOUND);
	
	}


}

void Game::printLoseEasy(){
	system("cls");
	
	Lose("text\\lose.txt", 0, 6);
	
	setcolor(Cyan);
	printrectangle(34, 14, 35, 8);
	printrectangle(37, 19, 7, 2);
	printrectangle(60, 19, 6, 2);
	gotoxy(40, 17);
	cout << "Do you want to play again?";
	string str[2] = { "Yes", "No" };
	int left[] = { 35,40,47,58,63,69 }, word[] = { 32,32,175,174 }, color[] = { BLACK, GREEN }, top = 19;
	bool choice = 1;
	auto print1 = [&]()
	{
		int i = 0;
		while (i < 2)
		{
			PlaySound("music\\click.wav", NULL, SND_ASYNC | SND_NOSTOP);
			gotoxy(left[choice * 3], top + 1);        putchar(word[i * 2]);
			gotoxy(left[choice * 3 + 1], top + 1);    cout << str[choice];
			gotoxy(left[choice * 3 + 2], top + 1);    putchar(word[i * 2 + 1]);
			if (!i++)
				choice = !choice;
		}
	};
	print1();
	while (true)
	{
		int key = getConsoleinput();
		if ((key == 3 && choice == 1) || (key == 4 && choice == 0))
			print1();
		else if (key == 6)
		{
			if (!choice){
				
				startGameEasy();
			}
				
			else{
				isPlaying = false;
				system("cls");
				exit(0);
				return;
				
			
			}
	
	}
	
}
}
void Game::printLoseMedium(){
	system("cls");
	
	Lose("text\\lose.txt", 0, 6);
	
	setcolor(Cyan);
	printrectangle(34, 14, 35, 8);
	printrectangle(37, 19, 7, 2);
	printrectangle(60, 19, 6, 2);
	gotoxy(36, 17);
	cout << "Do you want to play again?";
	string str[2] = { "Yes", "No" };
	int left[] = { 35,40,47,58,63,69 }, word[] = { 32,32,175,174 }, color[] = { BLACK, GREEN }, top = 19;
	bool choice = 1;
	auto print1 = [&]()
	{
		int i = 0;
		while (i < 2)
		{
			PlaySound("music\\click.wav", NULL, SND_ASYNC | SND_NOSTOP);
			gotoxy(left[choice * 3], top + 1);        putchar(word[i * 2]);
			gotoxy(left[choice * 3 + 1], top + 1);    cout << str[choice];
			gotoxy(left[choice * 3 + 2], top + 1);    putchar(word[i * 2 + 1]);
			if (!i++)
				choice = !choice;
		}
	};
	print1();
	while (true)
	{
		int key = getConsoleinput();
		if ((key == 3 && choice == 1) || (key == 4 && choice == 0))
			print1();
		else if (key == 6)
		{
			if (!choice){
				
				startGameMedium();
			}
				
			else{
				isPlaying = false;
				system("cls");
				exit(0);
				return;
				
			
			}
	
	}
	
}
}
void Game::printLoseHard(){
	system("cls");
	
	Lose("text\\lose.txt", 0, 6);
	
	setcolor(Cyan);
	printrectangle(34, 14, 35, 8);
	printrectangle(37, 19, 7, 2);
	printrectangle(60, 19, 6, 2);
	gotoxy(36, 17);
	cout << "Do you want to play again?";
	string str[2] = { "Yes", "No" };
	int left[] = { 35,40,47,58,63,69 }, word[] = { 32,32,175,174 }, color[] = { BLACK, GREEN }, top = 19;
	bool choice = 1;
	auto print1 = [&]()
	{
		int i = 0;
		while (i < 2)
		{
			PlaySound("music\\click.wav", NULL, SND_ASYNC | SND_NOSTOP);
			gotoxy(left[choice * 3], top + 1);        putchar(word[i * 2]);
			gotoxy(left[choice * 3 + 1], top + 1);    cout << str[choice];
			gotoxy(left[choice * 3 + 2], top + 1);    putchar(word[i * 2 + 1]);
			if (!i++)
				choice = !choice;
		}
	};
	print1();
	while (true)
	{
		int key = getConsoleinput();
		if ((key == 3 && choice == 1) || (key == 4 && choice == 0))
			print1();
		else if (key == 6)
		{
			if (!choice){
				
				startGameHard();
			}
				
			else{
				isPlaying = false;
				system("cls");
				exit(0);
				return;
				
			
			}
	
	}
	
}
}
void Game::playGameEasy(player& p) {
    //srand(time(0));
    //getBackground(bg);
    int counter = 60;
	const int heightEz = 6;
	const int widthEz = 6;
    pokemon** map = new pokemon * [heightEz];
    generateMapEasy(map);

    position selectedPos[] = { {-1, -1}, {-1, -1} };
    int couple = 2;
    position curPosition{ 1, 1 };
    int status = 0; //0. dang choi game //1. het game //2. nguoi choi chon thoat

    while (!status && p.life && counter >= 1) {
        map[curPosition.y][curPosition.x].isSelected = 1;
		
        renderBoardEasy(map, 6, 6);
		
        moveEasy(map, curPosition, status, p, selectedPos, couple, 6, 6);
    
    	
        if (checkValidPairsEasyLevel(map, 6, 6) == false) {
	        printCongratulationBoardEasy(p);
	        
    	}
//    	savePoint(p);
    	
    }
 
    Sleep(500);
    
    system("cls");

}
void Game::playGameMedium(player& p) {
    //srand(time(0));
    //getBackground(bg);

    pokemon** map = new pokemon * [height];
    generateMapMedium(map);

	
    gotoxy(86, 18);
    cout << p.life;



    position selectedPos[] = { {-1, -1}, {-1, -1} };
    int couple = 2;
    position curPosition{ 1, 1 };
    int status = 0; //0. dang choi game //1. het game //2. nguoi choi chon thoat


    while (status == 0 && p.life != 0) {
        map[curPosition.y][curPosition.x].isSelected = 1;
		
        renderBoardMedium(map, 8, 8);
	
        moveMedium(map, curPosition, status, p, selectedPos, couple);
       
       if (checkValidPairsMediumLevel(map, 8, 8) == false)
        {
            printCongratulationBoardMedium(p);
//            savePoint(p);
        }
    	
	

//        system("cls");
        //if ((!checkValidPairs(board))) status = 1;
    }

    renderBoardMedium(map, 8, 8);
    deleteMap(map);
    Sleep(500);
    
    system("cls");

}
void Game::playGameHard(player& p) {
    //srand(time(0));
    //getBackground(bg);

    pokemon** map = new pokemon * [height];
    generateMapHard(map);

	
    gotoxy(86, 18);
    cout << p.life;



    position selectedPos[] = { {-1, -1}, {-1, -1} };
    int couple = 2;
    position curPosition{ 1, 1 };
    int status = 0; //0. dang choi game //1. het game //2. nguoi choi chon thoat


   while (!status && p.life) {
        map[curPosition.y][curPosition.x].isSelected = 1;
        renderBoardHard(map, 10, 10);

        moveHard(map, curPosition, status, p, selectedPos, couple);
        if (checkValidPairsHardLevel(map, 10, 10) == false)
        {
            printCongratulationBoardHard(p);
//            savePoint(p);
        }
    }

    renderBoardHard(map, 10, 10);
    deleteMap(map);
    Sleep(500);
    
    system("cls");

}


void Game::startGameEasy() 
{
	system("cls");
	int mapWidth = 6, mapHeight = 6;
	int xCur = 1, yCur = 1;
	player p;
	bool isPlaying = true;
	p.hint = 5;
	p.point = 0;
	p.life = 5;
	while(isPlaying){
		bool isPause = false;
		playGameEasy(p);
		}
	
	saveData();
}
void Game::startGameMedium() 
{
	system("cls");
	int mapWidth = 8, mapHeight = 8;
	int xCur = 1, yCur = 1;
	player p;
	p.hint = 10;
	p.point = 0;
	p.life = 10;
	while(isPlaying = true){
		bool isPause = false;
		playGameMedium(p);
		

	}
}

void Game::startGameHard() 
{
	system("cls");
	int mapWidth = 10, mapHeight = 10;
	int xCur = 1, yCur = 1;
	player p;
	p.hint = 10;
	p.point = 0;
	p.life = 15;
	while(isPlaying = true){
		
		playGameHard(p);
	
		
	
	}	
saveData();
}