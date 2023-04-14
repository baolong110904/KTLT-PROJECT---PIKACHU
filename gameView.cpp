//#include "gameView.h"
//
//
//int mapWidth = 10, mapHeight = 8;
//HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//DWORD dwMode = 0;
//
//char box[5][12] = {
//            {" --------- "},
//            {"|         |"},
//            {"|         |"},
//            {"|         |"},
//            {" --------- "}
//};
//
////char box[5][12] = {
////    {"╭─────────╮"},
////    {"│         │"},
////    {"│         │"},
////    {"│         │"},
////    {"╰─────────╯"}
////};
//
//void gotoxY(int x, int y){
//	COORD coord;
//    coord.X = x;
//    coord.Y = y;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
//
//void generateMap(pokemon **&map)
//{   
//    srand((unsigned int)time(NULL));
//    map = new pokemon* [mapHeight];
//
//    //Creating a 2D for game array
//    for (int i = 0; i < mapHeight; i++)
//    {
//        map[i] = new pokemon [mapWidth];
//    }
//
//    int timesRandom = 2;
//
//    for (int i = 0; i < mapHeight; i++)
//    {
//        for (int j = 0; j < mapWidth; j++)
//        {
//            if (i == 0 || i == mapHeight - 1 || j == 0 || j == mapWidth - 1)
//                map[i][j].matched = 1;
//        }
//    }
//
//    for (int i = 1; i < mapHeight - 1; i++)
//    {
//        for (int j = 1; j < mapWidth - 1; j++)
//        {
//            map[i][j].x = j;
//            map[i][j].y = i;
//        }
//    }
//
//
//    int totalCell = ((mapWidth - 2) * (mapHeight - 2)) / 2;
//
//    while (totalCell > 0)
//    {
//        char randomCharacter = 65 + rand() % 26;
//        while (timesRandom > 0)
//        {
//            int index = rand() % (mapWidth * mapHeight);
//            if (map[index / mapWidth][index % mapWidth].chr == ' ')
//            {
//                if (index / mapWidth != 0 && index / mapWidth != (mapHeight - 1) && index % mapWidth != 0 && index % mapWidth != (mapWidth - 1))
//                {
//                    map[index / mapWidth][index % mapWidth].chr = randomCharacter;
//                    timesRandom--;
//                }
//            }
//        }
//        timesRandom = 2;
//        totalCell--;
//    }
//}
//
//void deleteMap(pokemon **map)
//{
//    for (int i = 0; i < mapHeight; i++)
//    {
//        delete[] * (map + i);
//    }
//    delete[] map;
//}
//
//void printPokemons(pokemon **map)
//{
//    for (int i = 0; i < mapHeight; i++)
//    {
//        for (int j = 0; j < mapWidth; j++)
//        {
//            cout << map[i][j].chr << " ";
//        }
//        cout << endl;
//    }
//}
//
//void generateForTesting(pokemon**& map)
//{
//    map = new pokemon * [mapHeight];
//
//    //Creating a 2D for game array
//    for (int i = 0; i < mapHeight; i++)
//    {
//        map[i] = new pokemon[mapWidth];
//    }
//
//    for (int i = 0; i < mapHeight; i++)
//    {
//        for (int j = 0; j < mapWidth; j++)
//        {
//            if (i == 0 || i == mapHeight - 1 || j == 0 || j == mapWidth - 1)
//                map[i][j].matched = 1;
//        }
//    }
//
//    for (int i = 0; i < mapHeight; i++)
//    {
//        for (int j = 0; j < mapWidth; j++)
//        {
//            if (i != 0 && i != mapHeight - 1 && j != 0 && j != mapWidth - 1)
//                map[i][j].chr = 'A';
//        }
//    }
//}
//
//void pokemon::drawPlayingBox(int color)
//{   
//    if (matched == 1)
//        return;
//
//    for (int i = 0; i < 5; i++) {
//        gotoxY(x * 10, y * 4 + i);
//        cout << box[i];
//    }
//
//    if (selected == 1) {
//        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color + (chr % 6 + 1)); // white background
//        for (int i = 1; i < 4; i++) {
//            gotoxY(x * 10 + 1, y * 4 + i);
//            cout << "         ";
//        }
//
//        gotoxY(x * 10 + 5, y * 4 + 2);
//        cout << chr;
//        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//    }
//    else {
//        gotoxY(x * 10 + 5, y * 4 + 2);
//        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), chr % 6 + 1);
//        cout << chr;
//        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//    }
//}
//
//void pokemon::deleteBox() {
//    int xCurrent = x + 1, yCurrent = y + 1;
//
//    for (int i = 0; i < 5; i++) {
//        gotoxY(x * 10, y * 5 + i);
//        cout << "           ";
//    }
//}
//void renderBoard(pokemon** map) 
//{
//    for (int i = 1; i < mapHeight - 1; i++) {
//        for (int j = 1; j < mapWidth - 1; j++) {
//            map[i][j].drawPlayingBox(112);
//        }
//    }
//}