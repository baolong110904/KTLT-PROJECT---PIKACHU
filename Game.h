#ifndef GAME_H
#define GAME_H

//Key
#define KEY_UP 72	//Arrow up
#define KEY_DOWN 80 //Arrow down
#define KEY_LEFT 75 //Arrow left
#define KEY_RIGHT 77 //Arrow right
#define ESC_KEY 27 //Esc key
#define ENTER_KEY 13 //Enter key
#define SPACE_KEY 32    //Space key

#define W_UP 87//W
#define D_RIGHT 68//D
#define A_LEFT 65//A
#define S_DOWN 83//S

#define w_up 119//W
#define d_right 100//D
#define a_left 97//A
#define s_down 115//S

#include "BoardView.h"
#include "Controller.h"

#include <string>

struct player
{
	int point, life, hint;
	char playerName[50];
	char playerClass[20];
    char playerID[20];  
    char _mode[20];
    char modeChar[20];
};
struct pokemon
{
	char chr = ' ';
	bool isValid = 1, isSelected = 0;
	int x;
	int y;
	void drawPlayingBox(int);
	void deleteBox();
	void drawSuggestedBox(int);;	
};
struct position 
{
	int x, y;
};
class Game {
public:
	Board* board;
//	Game(int mode) : _mode(mode) {}
//	Game(player* p) : _mode(p->_mode) {}
    void setupGame(player &p);
    void saveData(player &p);
//    void savePoint(int &point);
    void startGameEasy(player &p);
    void startGameMedium(player &p);
    void startGameHard(player &p);
    
//    void printBackground();



	void moveEasy(pokemon** map, position& pos, int& status, player& p, position selectedPos[], int& couple, int heightEz, int widthEz);
	void moveMedium(pokemon** map, position& pos, int& status, player& p, position selectedPos[], int& couple);
	void moveHard(pokemon** map, position& pos, int& status, player& p, position selectedPos[], int& couple);
	
	void playGameEasy(player& p);
	void playGameMedium(player& p);
	void playGameHard(player& p);
	
	void renderBoardEasy(pokemon** map, int height, int width, player &p);
	void renderBoardMedium(pokemon** map, int height, int width, player &p);
	void renderBoardHard(pokemon** map, int height, int width, player &p);
	
	void generateMapEasy(pokemon **&map);
	void generateMapMedium(pokemon **&map);
	void generateMapHard(pokemon **&map);
	
	
	void printCongratulationBoardEasy(player& p);
	void printCongratulationBoardMedium(player& p);
	void printCongratulationBoardHard(player& p);
	
	void printLoseEasy(player &p);
	void printLoseMedium(player &p);
	void printLoseHard(player &p);
	
	
 	
	
    int score;
        

private:
   	int _mode;
	int _x, _y;
	bool isPlaying;
	int _lockedBlock;
	int _remainBlocks;
	

};




bool Icheck(pokemon **map, int x1, int y1, int x2, int y2);
bool Lcheck(pokemon **map, int x1, int y1, int x2, int y2);
bool Zcheck(pokemon **map, int x1, int y1, int x2, int y2);
bool Ucheck(pokemon **map, int x1, int y1, int x2, int y2);
bool checkNext(pokemon** map, int x1, int y1, int x2, int y2);

int findMax(int x, int y);
int findMin(int x, int y);

bool checkTwoCharacter(pokemon **map, int x1, int y1, int x2, int y2);
bool CheckSelectedAndMatched(pokemon **map, int x1, int y1, int x2, int y2);
void matchedCell(pokemon **& map, int x1, int y1, int x2, int y2);
void selectedCell(pokemon **&map, int x1, int y1, int x2, int y2);
void unselectedCell(pokemon **&map, int x1, int y1, int x2, int y2);

bool checkValidPair(pokemon** map, int width, int height);

bool allCheck(pokemon** map, int x1, int y1, int x2, int y2);

#endif
