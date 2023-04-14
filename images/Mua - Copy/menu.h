#include <windows.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include "Controller.h"
#include <random>
#include <fstream>
#include <conio.h>
#include<stdio.h>
#include<Windows.h>
#include "Game.cpp"
#include "Game.h"


#define _EASY 4
#define _MEDIUM 6

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursorPos; // used to set the position of the cursor
void displayMenu(int option);
void displayStartMenu();
void exitScreen();

void setColor(int color) {
    SetConsoleTextAttribute(console, color);
}
void gotoXY(int x, int y){
	COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setConsoleColor(int textColor, int bgColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor + (bgColor * 16)));
}
int getWindowWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}


enum ConsoleColor {
    black = 0,
    blue = 1,
    green = 2,
    cyan = 3,
    red = 4,
    magenta = 5,
    yellow = 6,
    white = 7,
    gray = 8,
    darkBlue = 9,
    darkGreen = 10,
    teal = 11,
    darkRed = 12,
    purple = 13,
    orange = 14,
    lightGray = 15,
    darkOrange = 16,
    lightBlue = 17,
    lightGreen = 18,
    lightYellow = 19,
    lightCyan = 20,
    pink = 21,
    lavender = 22
    
};

void setColor(ConsoleColor color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD)color);
}

void drawLogo() {
	
	setColor(Orange);
	gotoXY(50,5);
	unsigned char logo[] = R"(
	  ____                      _  __         _           ____       _       _   _  
	U|  _"\ u      ___         |"|/ /     U  /"\  u   U /"___|    |'| |'|    U |"|u| | 
	\| |_) |/     |_"_|        | ' /       \/ _ \/    \| | u     /| |_| |\    \| |\| | 
	 |  __/        | |       U/| . \\u     / ___ \     | |/__    U|  _  |u     | |_| | 
	 |_|         U/| |\u       |_|\_\     /_/   \_\     \____|    |_| |_|     <<\___/  
	 ||>>_    .-,_|___|_,-.  ,-,>> \\,-.   \\    >>    _// \\     //   \\    (__) )(   
	(__)__)    \_)-' '-(_/    \.)   (_/   (__)  (__)  (__)(__)   (_") ("_)       (__)  
	)";
	cout << logo;
	gotoXY(30, 0);
	setColor(White);
	cout << "Nguyen Bao Long - Bui Minh Quan";
	gotoXY(37, 1);
	cout << "22127243 - 22127342";
	
	
	setColor(DarkGreen);
	cout << R"(
  _____  _  _  ___   __  __    _  _____  ___  _  _  ___  _  _   ___    ___    _    __  __  ___ 
 |_   _|| || || __| |  \/  |  /_\|_   _|/ __|| || ||_ _|| \| | / __|  / __|  /_\  |  \/  || __|
   | |  | __ || _|  | |\/| | / _ \ | | | (__ | __ | | | | .` || (_ | | (_ | / _ \ | |\/| || _| 
   |_|  |_||_||___| |_|  |_|/_/ \_\|_|  \___||_||_||___||_|\_| \___|  \___|/_/ \_\|_|  |_||___|
	)";

}
void drawImage1(){
	setColor(DarkRed);
    const char* image1 = R"(
 
	.______    __   __  ___      ___         .______    __   __  ___      ___          __   __   __  
	|   _  \  |  | |  |/  /     /   \        |   _  \  |  | |  |/  /     /   \        |  | |  | |  | 
	|  |_)  | |  | |  '  /     /  ^  \       |  |_)  | |  | |  '  /     /  ^  \       |  | |  | |  | 
	|   ___/  |  | |    <     /  /_\  \      |   ___/  |  | |    <     /  /_\  \      |  | |  | |  | 
	|  |      |  | |  .  \   /  _____  \     |  |      |  | |  .  \   /  _____  \     |__| |__| |__| 
	| _|      |__| |__|\__\ /__/     \__\    | _|      |__| |__|\__\ /__/     \__\    (__) (__) (__) 
                                                                                                                                   
    )";
    gotoXY(10,0);
	cout << image1;
	setColor(LightGray); // reset the console color
}
//void drawImage2(){
//	const char* image2 = R"(
//    `;-.          ___,
//      `.`\_...._/`.-"`
//        \        /      ,
//        /()   () \    .' `-._
//       |)  .    ()\  /   _.'
//       \  -'-     ,; '. <
//        ;.__     ,;|   > \
//       / ,    / ,  |.-'.-'
//      (_/    (_/ ,;|.<`
//        \    ,     ;-`
//         >   \    /
//        (_,-'`> .'
//             (_,'
//    )";
//	
//	cout << image2;
//	
//}

void drawImage3(){	
	
    const char* image3 = R"(
           ,___          .-;'
           `"-.`\_...._/`.`
        ,      \        /
     .-' ',    / ()   ()\
    `'._   \  /()    .  (|
        > .' ;,     -'-  /
       / <   |;,     __.;
       '-.'-.|  , \    , \
          `>.|;, \_)    \_)
           `-;     ,    /
              \    /   <
               '. <`'-,_)
                '._)
    )";
    gotoXY(70,12);
	cout << image3;
}    
 

void drawMenu(){
	setColor(Teal);
  	gotoXY(30, 15);
	 // Draw the top border
    std::cout << "+------------------------------------------+" << std::endl;
	
    // Draw the game title
    gotoXY(30, 16);
    std::cout << "|            PIKACHU MAIN MENU             |" << std::endl;

    // Draw the middle border
    gotoXY(30, 17);
    std::cout << "+-----+------------------------------------+" << std::endl;

    // Draw the menu options
    gotoXY(30, 18);    
    std::cout << "|     |  Start Game                        |" << std::endl;
    gotoXY(30, 19);
	std::cout << "|     |  Instructions                      |" << std::endl;
    gotoXY(30, 20);
	std::cout << "|     |  High Scores                       |" << std::endl;
    gotoXY(30, 21);
	std::cout << "|     |  Quit                              |" << std::endl;
    gotoXY(30, 22);
	std::cout << "|     |  Press M to turn on/off music      |" << std::endl;
	
	gotoXY(30, 23);
    std::cout << "+-----+------------------------------------+" << std::endl;
	
    // Reset the text color
    setColor(7);
}
void drawStartMenu() {
    // Clear the console
    system("cls");
    
	
	drawImage1();
//	gotoXY(70,15);
//	drawImage2();
	
	drawImage3();
	
	
	setColor(Teal);
    // Draw the top border
    gotoXY(30, 15);
    std::cout << "+------------------------------------------+" << std::endl;
    
    // Draw the game title
    gotoXY(30, 16);
    std::cout << "|               PIKACHU GAME               |" << std::endl;

    // Draw the middle border
    gotoXY(30, 17);
    std::cout << "+-----+------------------------------------+" << std::endl;

    // Draw the menu options
    gotoXY(30, 18);    
    std::cout << "|     |  Easy Mode                         |" << std::endl;
    gotoXY(30, 19);
    std::cout << "|     |  Medium Mode                       |" << std::endl;
    gotoXY(30, 20);
    std::cout << "|     |  Back                              |" << std::endl;
    gotoXY(30, 21);
    std::cout << "|     |  Exit                              |" << std::endl;

    // Draw the bottom border
    gotoXY(30, 22);
    std::cout << "+-----+------------------------------------+" << std::endl;

    // Reset the text color
    setColor(7);
}

void playEasy(){
	string* background;
	Game game(_EASY);
    game.setupGame();
    PlaySound(NULL, NULL, SND_PURGE);
    game.startGame();
    
}

void playMedium(){
	Game game(_MEDIUM);
    game.setupGame();
//    createBackground("images\\medium.txt"); // Set the background for medium mode
	PlaySound(NULL, NULL, SND_PURGE);
    game.startGame();
    
}

void displayStartMenu() {
    int option = 0;
    
    while (true) {
        drawStartMenu(); // call the function to draw the start menu
	
        // display the selected option
        gotoXY(33, 18 + option);
        std::cout << "-->";
		
        // wait for user input
        char input = _getch();

        switch (input) {
            case 72: // up arrow
            case 'w':
            	PlaySound("click.wav", NULL, SND_ASYNC);
                option = max(0, option - 1);
                break;
            case 80: // down arrow
            case 's':
            	PlaySound("click.wav", NULL, SND_ASYNC);
                option = min(3, option + 1);
                break;
            case 13: // enter key
                switch (option)
                {
                case 0:
                    playEasy();
                    
                    break;
                case 1:
                    playMedium();
                   
                    break;
                case 2:
                    displayMenu(0); // return to main menu
                    
                    break;
                case 3:
                    exitScreen();
                    break;
                }
                _getch(); // wait for user to press a key
                break;
                Sleep(500);
        }
    }
    
}
void printRectangle(int left, int top, int width, int height){
	gotoXY(left, top);
	putchar(218);
	for (int i = 0; i < width; i++)
		putchar(196);
	putchar(191);

	int i = 0;
	for (; i < height; i++)
	{
		gotoXY(left, top + i + 1);
		putchar(179);
		gotoXY(left + width + 1, top + i + 1);
		putchar(179);
	}

	gotoXY(left, top + i);
	putchar(192);
	for (i = 0; i < width; i++)
		putchar(196);
	putchar(217);
}
int getConsoleInput(){
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

void exitScreen(){
	system("cls");
	ShowCursor(false);
	setConsoleColor(BRIGHT_WHITE, BLACK);
	
	setConsoleColor(BRIGHT_WHITE, BLACK);
	printRectangle(34, 13, 35, 8);
	printRectangle(37, 18, 7, 2);
	printRectangle(60, 18, 6, 2);
	setConsoleColor(BRIGHT_WHITE, RED);
	gotoXY(0, 0);
	drawLogo();
	gotoXY(42, 16);
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
			PlaySound("click.wav", NULL, SND_ASYNC);
			setConsoleColor(BRIGHT_WHITE, color[i]);
			gotoXY(left[choice * 3], top);        putchar(word[i * 2]);
			gotoXY(left[choice * 3 + 1], top);    cout << str[choice];
			gotoXY(left[choice * 3 + 2], top);    putchar(word[i * 2 + 1]);
			if (!i++)
				choice = !choice;
		}
		exitProgram = (choice == 0); // update exitProgram variable
	};
	print1();
	while (loop)
	{
		int key = getConsoleInput();
		if ((key == 3 && choice == 1) || (key == 4 && choice == 0))
		{	
			print1();
		}
		else if (key == 6)
		{
			if (!choice)
			{	
				
				setConsoleColor(BLACK, BRIGHT_WHITE);
				system("cls");
				exit(0);
			}
			return;
		}
//		else
//		{
//			Controller::playSound(ERROR_SOUND);
//		}
	}
	 
}
void instructionScreen(){
	ShowCursor(false);
	
	system("cls");
	int left = 5, top = 2, width = 85, height = 23;
	int line1 = 6, line2 = 19, line3 = 20, line4 = 15;
	printRectangle(left, top, width, height);
	gotoXY(left + 1, line1);
	for (int i = 0; i < width; i++)
	{
		putchar(196);
	}
	gotoXY(left + 1, line2);
	for (int i = 0; i < width; i++)
	{
		putchar(196);
	}
	gotoXY(left + 1, line4);
	for (int i = 0; i < width; i++)
	{
		putchar(196);
	}
	for (int i = 1; i < height; i++)
	{
		gotoXY(line3, top + i);
		putchar(179);
	}
	gotoXY(line3, line1);
	putchar(197);
	gotoXY(line3, line2);
	putchar(197);

	gotoXY(left + 3, top + 2);
	setColor(White);
	
	cout << "Moves:";
	gotoXY(left + 20, top + 1);
	setColor(Cyan);
	
	putchar(249); cout << "Up:    W, up arrow";
	gotoXY(left + 52, top + 1);
	setColor(Cyan);
	putchar(249); cout << "Down:  S, down arrow";
	gotoXY(left + 20, top + 3);
	setColor(Cyan);
	putchar(249); cout << "Left:  A, left arrow";
	gotoXY(left + 52, top + 3);
	setColor(Cyan);
	putchar(249); cout << "Right: D, right arrow";
	
	
	gotoXY(left + 3, top + 8);
	setColor(White);
	cout << "Rules:";
	gotoXY(left + 17, top + 5);
	int left1 = left + 17;
	
	setColor(Orange);
	putchar(249); cout << " The Matching Game (commonly known as the Pikachu Puzzle Game)";
	gotoXY(left1, top + 6);
	cout << " includes a board of multiple cells, each of which presents a figure.";
	gotoXY(left1, top + 8);
	setColor(Orange);
	putchar(249); cout << " The player finds and matches a pair of cells that contain the same";
	gotoXY(left1, top + 9);
	cout << " figure and connect each other in some particular pattern.";
	gotoXY(left1, top + 11);
	setColor(Orange);
	putchar(249); cout << " A legal match will make the two cells disappear. The game ends when";
	gotoXY(left1, top + 12);
	cout << " all matching pairs are found.";
	setColor(Orange);
	gotoXY(left + 3, top + 15);
	setColor(White);
	cout << "Scoring:";
	

	gotoXY(left1 + 10, top + 14);
	putchar(249); cout << " I Matching: +1 BTC";
	
	gotoXY(left1 + 40, top + 14);
	putchar(249); cout << " L Matching: +2 BTC";
	setColor(Yellow);
	gotoXY(left1 + 10, top + 15);
	putchar(249); cout << " Z Matching: +3 BTC";
	setColor(Green);
	gotoXY(left1 + 40, top + 15);
	putchar(249); cout << " U Matching: +4 BTC";
	
	setColor(Red);
	gotoXY(left1 + 10, top + 16);
	putchar(249); cout << " Not Matched: -2 BTC";
	
	setColor(Red);
	gotoXY(left1 + 40, top + 16);
	putchar(249); cout << " Move suggestion: -2 BTC";
	
	
	gotoXY(left + 3, top + 20);
	setColor(White);
	cout << "Developers:";
	gotoXY(left + 31, top + 19);
	setColor(Teal);
	cout << "Dev 1: Nguyen Bao Long (22127243))";
	gotoXY(left + 31, top + 21);
	setColor(Teal);
	cout << "Dev 2: Bui Minh Quan (22127342)";


	// code for the "Back" button
	printRectangle(45, 27, 8, 2);
	gotoXY(43, 28);
	putchar(175);
	gotoXY(48, 28);
	setColor(Red);
	cout << "Back";
	gotoXY(56, 28);
	putchar(174);
	// wait for user input
	while (true) {
   		if (_kbhit()) {
        	char c = _getch();
        if (c == 'B' || c == 'b' || c == '\r') {  // check if the user pressed "B" or "b"
            displayMenu(0);  // call the main menu function
            break;
        }
    }
}
//	while (getConsoleInput() != 6)
//	{
//		Controller::playSound(ERROR_SOUND);
//	}
}

void displayMenu(int option)
{	
	system("cls");	
    while (true) {
        system("cls");	
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    	COORD curdsorPos = {0, 4}; // declare and initialize cursorPos

    	SetConsoleCursorPosition(console, cursorPos);
    	bool music_on = true;
    	bool music_paused = true;
		
		drawLogo();
		
    	PlaySound(TEXT("Wallpaper.wav"), NULL, SND_ASYNC);
    	
    	while (true){
    	
    	drawMenu(); // draw the menu
		
		
        // display the selected option
        gotoXY(33, 18 + option);
        std::cout << "->";

        // wait for user input
        char input = _getch();

        switch (input) {
            case 72: // up arrow
            case 'w':
            	PlaySound("click.wav", NULL, SND_ASYNC);
                option = max(0, option - 1);
                break;
            case 80: // down arrow
            case 's':
            	PlaySound("click.wav", NULL, SND_ASYNC);
                option = min(4, option + 1);
                break;
            case 13: // enter key
                switch (option)
                {
                case 0:
                	displayStartMenu();
                	
                    break;
                case 1:
                    instructionScreen();
                    break;
                case 2:
                    std::cout << "High Scores";
                    break;
                case 3:
                    exitScreen();
                    return; // exit the program if user chooses to exit
                
                break;
                case 4:
                    music_paused = !music_paused;
                    if (music_paused) {
                        PlaySound(NULL, NULL, SND_PURGE); // stop currently playing sound
                    } else {
                        if (!PlaySound(TEXT("Wallpaper.wav"), NULL, SND_ASYNC)) {
                            MessageBox(NULL, "Error playing sound!", "Error", MB_OK | MB_ICONERROR);
                        }   
                    }
                    // Print the volume image based on the current music status
   				
					gotoXY(0, 23); // go to the top-left corner of the output screen
					std::cout << "Music: " << (music_paused ? "OFF" : "ON") << " "; // print the on/off volume image
					
                }
                _getch(); // wait for user to press a key
                break;
            case 109: // M key
    
   				_getch(); // wait for user to press a key
    			music_paused = !music_paused;
    			if (music_paused) {
        			PlaySound(NULL, NULL, SND_PURGE); // stop currently playing sound
    			} else {
        			if (!PlaySound(TEXT("Wallpaper.wav"), NULL, SND_ASYNC)) {
            		MessageBox(NULL, "Error playing sound!", "Error", MB_OK | MB_ICONERROR);
        			}   
    			}
    		
				gotoXY(0, 23); // go to the top-left corner of the output screen
				std::cout << "Music: " << (music_paused ? "OFF" : "ON") << " "; // print the on/off volume image
				break;
        	}
    	}
	}
}



