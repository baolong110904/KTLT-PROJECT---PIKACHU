#include "BoardView.h"
#include <iostream>


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursorPos; // used to set the position of the cursor

void SetColor(int color) {
    SetConsoleTextAttribute(console, color);
}
void gotoXy(int x, int y){
	COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setconsoleColor(int textColor, int bgColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor + (bgColor * 16)));
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

void SetColor(ConsoleColor color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD)color);
}

//BoardView::BoardView(int psize, int pX, int pY) : size(psize), left(pX), top(pY)
//{
//	pokemons = new int*[size];
//	for (int i = 0; i < psize; i++)
//		pokemons[i] = new int[size];
//	pBoard = new Point * [psize];
//	for (int i = 0; i < psize; i++)		
//		pBoard[i] = new Point[psize];
//	background = new string[psize * 10];
//}
//
//BoardView::~BoardView()
//{
//	for (int i = 0; i < size; i++)
//		delete[] pBoard[i];
//	delete[] pBoard,
//	pBoard = nullptr;
//	delete[] background;
//	background = nullptr;
//}
//
//int BoardView::getSize()
//{
//	return size;
//}
//
//int BoardView::getLeft()
//{
//	return left;
//}
//
//int BoardView::getTop()
//{
//	return top;
//}
//
//int BoardView::getXAt(int i, int j)
//{
//	return pBoard[i][j].getX();
//}
//
//int BoardView::getYAt(int i, int j)
//{
//	return pBoard[i][j].getY();
//}
//
//int BoardView::getRAt(int x, int y)
//{
//	return (y - 2 - top) / 4;
//}
//
//int BoardView::getCAt(int x, int y)
//{
//	return (x - 5 - left) / 8;
//}
//
//char BoardView::getPokemons(int x, int y)
//{
//	return pBoard[getRAt(x,y)][getCAt(x,y)].getPokemons();
//}
//
//int BoardView::getCheckAtXY(int pX, int pY)
//{
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			if (pBoard[i][j].getX() == pX && pBoard[i][j].getY() == pY)
//				return pBoard[i][j].getCheck();
//		}
//	}
//	throw "Problem with cursor position";
//}
//int BoardView::getCheck(int x, int y)
//{
//	int r = getRAt(x, y);
//	int c = getCAt(x, y);
//	return pBoard[r][c].getCheck();
//}
/////////////////////////////////////////////////////////////////////

//
//void BoardView::renderBoard() {
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			pBoard[i][j].setX(8 * j + left + 5); // x-value of boardgame
//			pBoard[i][j].setY(4 * i + top + 2); // y-value of boardgame
//			pBoard[i][j].setCheck(0);
//
//			int r = pBoard[i][j].getX();
//			int c = pBoard[i][j].getY();
//
//			Controller::gotoXY(r, c);
//			putchar(pBoard[i][j].getPokemons());
//		}
//	}
//}
//
//void BoardView::buildBoardData() {
//	srand((unsigned int)time(NULL));
//
//	bool* checkDuplicate = new bool[size * size];
//	int* pos = new int[size * size];
//
//	// Random pokemons
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; j+=2) {
//			pokemons[i][j] = pokemons[i][j + 1] = rand() % 26 + 'A';
//		}
//	}
//
//	// Random pokemons position 
//	for (int i = 0; i < size * size; i++) 
//		checkDuplicate[i] = 0;
//	for (int i = 0; i < size * size; i++) {
//		int tmp = 0;
//		do {
//			tmp = rand() % (size * size);
//		} while (checkDuplicate[tmp]);
//		checkDuplicate[tmp] = 1;
//		pos[i] = tmp;
//	}
//
//	// Construct pokemons matrix
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; j++) {
//			int r = pos[size * i + j] / size;
//			int c = pos[size * i + j] % size;
//			pBoard[i][j].setPokemons(pokemons[r][c]);
//		}
//	}
//
//	delete[] pos;
//	delete[] checkDuplicate;
//}