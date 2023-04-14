//#include "menu.h"
//
//HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//COORD cursorPos; // used to set the position of the cursor
//
//
//
//
//void centerConsole() {
//
//    // Get the handle of the console window
//    HWND consoleHandle = GetConsoleWindow();
//
//    // Get the size of the console window
//    RECT consoleRect;
//    GetWindowRect(consoleHandle, &consoleRect);
//    int consoleWidth = consoleRect.right - consoleRect.left;
//    int consoleHeight = consoleRect.bottom - consoleRect.top;
//
//    // Get the size of the screen
//    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
//    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
//
//    // Calculate the position of the console window to center it on the screen
//    int consoleX = (screenWidth - consoleWidth) / 2;
//    int consoleY = (screenHeight - consoleHeight) / 2;
//
//    // Set the position of the console window
//    SetWindowPos(consoleHandle, NULL, consoleX, consoleY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
//}
//void setFontInfo()
//{
//	// 12 - 24
//	CONSOLE_FONT_INFOEX info;
//	info.cbSize = sizeof(info);
//	GetCurrentConsoleFontEx(console, FALSE, &info);
//	info.dwFontSize.X = 12;
//	info.dwFontSize.Y = 17;
//	wcscpy_s(info.FaceName, L"Consolas");
//	SetCurrentConsoleFontEx(console, FALSE, &info);
//}
//void showCursor(bool show)
//{
//	CONSOLE_CURSOR_INFO info = { 1, show };
//	SetConsoleCursorInfo(console, &info);
//}
//void clearConsole() // Xoá nội dung có sẵn trong console 
//{
//    COORD cursorPosition;
//    cursorPosition.X = 0;
//    cursorPosition.Y = 0;
//
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
//    
//}
//
//void setColor(int color) {
//    SetConsoleTextAttribute(console, color);
//}
//void gotoXY(int x, int y){
//	COORD coord;
//    coord.X = x;
//    coord.Y = y;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
//
//void setConsoleColor(int textColor, int bgColor) {
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor + (bgColor * 16)));
//}
//int getWindowWidth() {
//    CONSOLE_SCREEN_BUFFER_INFO csbi;
//    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
//    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
//}
//
//
//enum ConsoleColor {
//    black = 0,
//    blue = 1,
//    green = 2,
//    cyan = 3,
//    red = 4,
//    magenta = 5,
//    yellow = 6,
//    white = 7,
//    gray = 8,
//    darkBlue = 9,
//    darkGreen = 10,
//    teal = 11,
//    darkRed = 12,
//    purple = 13,
//    orange = 14,
//    lightGray = 15,
//    darkOrange = 16,
//    lightBlue = 17,
//    lightGreen = 18,
//    lightYellow = 19,
//    lightCyan = 20,
//    pink = 21,
//    lavender = 22
//    
//};
//
//void setColor(ConsoleColor color) {
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//    SetConsoleTextAttribute(hConsole, (WORD)color);
//}
//
//
//
//
//void drawLogo() {
//	
//	setColor(Orange);
//	gotoXY(50,5);
//	unsigned char logo[] = R"(
//	  ____                      _  __         _           ____       _       _   _  
//	U|  _"\ u      ___         |"|/ /     U  /"\  u   U /"___|    |'| |'|    U |"|u| | 
//	\| |_) |/     |_"_|        | ' /       \/ _ \/    \| | u     /| |_| |\    \| |\| | 
//	 |  __/        | |       U/| . \\u     / ___ \     | |/__    U|  _  |u     | |_| | 
//	 |_|         U/| |\u       |_|\_\     /_/   \_\     \____|    |_| |_|     <<\___/  
//	 ||>>_    .-,_|___|_,-.  ,-,>> \\,-.   \\    >>    _// \\     //   \\    (__) )(   
//	(__)__)    \_)-' '-(_/    \.)   (_/   (__)  (__)  (__)(__)   (_") ("_)       (__)  
//	)";
//	cout << logo;
//	gotoXY(30, 0);
//	setColor(White);
//	cout << "Nguyen Bao Long - Bui Minh Quan";
//	gotoXY(37, 1);
//	cout << "22127243 - 22127342";
//	
//	
//	setColor(DarkGreen);
//	cout << R"(
//  _____  _  _  ___   __  __    _  _____  ___  _  _  ___  _  _   ___    ___    _    __  __  ___ 
// |_   _|| || || __| |  \/  |  /_\|_   _|/ __|| || ||_ _|| \| | / __|  / __|  /_\  |  \/  || __|
//   | |  | __ || _|  | |\/| | / _ \ | | | (__ | __ | | | | .` || (_ | | (_ | / _ \ | |\/| || _| 
//   |_|  |_||_||___| |_|  |_|/_/ \_\|_|  \___||_||_||___||_|\_| \___|  \___|/_/ \_\|_|  |_||___|
//	)";
//
//
//}
//void drawImage1(){
//	setColor(DarkRed);
//    const char* image1 = R"(
// 
//	.______    __   __  ___      ___         .______    __   __  ___      ___          __   __   __  
//	|   _  \  |  | |  |/  /     /   \        |   _  \  |  | |  |/  /     /   \        |  | |  | |  | 
//	|  |_)  | |  | |  '  /     /  ^  \       |  |_)  | |  | |  '  /     /  ^  \       |  | |  | |  | 
//	|   ___/  |  | |    <     /  /_\  \      |   ___/  |  | |    <     /  /_\  \      |  | |  | |  | 
//	|  |      |  | |  .  \   /  _____  \     |  |      |  | |  .  \   /  _____  \     |__| |__| |__| 
//	| _|      |__| |__|\__\ /__/     \__\    | _|      |__| |__|\__\ /__/     \__\    (__) (__) (__) 
//                                                                                                                                   
//    )";
//    gotoXY(10,0);
//	cout << image1;
//	setColor(LightGray); // reset the console color
//}
//
//
//void drawImage3(){	
//	setColor(Orange);
//    const char* image3 = R"(
//           ,___          .-;'
//           `"-.`\_...._/`.`
//        ,      \        /
//     .-' ',    / ()   ()\
//    `'._   \  /()    .  (|
//        > .' ;,     -'-  /
//       / <   |;,     __.;
//       '-.'-.|  , \    , \
//          `>.|;, \_)    \_)
//           `-;     ,    /
//              \    /   <
//               '. <`'-,_)
//                '._)
//    )";
//    gotoXY(70,12);
//	cout << image3;
//}    
//int getRandomInt(int begin, int end)
//{
//	static random_device rd;
//	static mt19937 mt(rd());
//	uniform_int_distribution<int> dist(0, end);
//	return dist(mt);
//}
// 
//void printAnimation()
//{
//	setConsoleColor(BRIGHT_WHITE, BLACK);
//	clearConsole();
//	char symbolpos[] = { 5,0,19,0,33,0,47,0,61,0,75,0,89,0,0,103,5,13,19,
//							   13,33,13,47,13,61,13,75,13,89,13,13,103,13,18,26,18,40,18,
//							   54,18,68,18,82,18,18,96,5,24,19,24,33,24,47,24,61,24,75,24,
//							   89,24,24,103,12,30,26,30,40,30,54,30,68,30,82,30,96,30 };
//	int n = (sizeof(symbolpos) / sizeof(symbolpos[0])) / 2;
//	bool turn = 0;
//	unsigned char symbol[] = { 4,15 };
//
//	int color[] = { LIGHT_AQUA, AQUA, LIGHT_BLUE, BLUE, LIGHT_PURPLE, PURPLE };
//	int colorcount = 0;
//	int loop = 10;
//	bool stopped = false; // flag to indicate whether the animation is stopped or nots
//	while (loop--)
//	{	
//		if (GetAsyncKeyState('S') & 0x8000) // check if the 'S' key is pressed
//	        {
//	            stopped = true;
//	            break;
//	        }
//		for (int i = 0; i < n; i += 2)
//		{
//			setConsoleColor(BRIGHT_WHITE, getRandomInt(0, 15));
//			gotoXY(symbolpos[i * 2], symbolpos[i * 2 + 1]);
//			putchar(symbol[turn]);
//		}
//		for (int i = 1; i < n; i += 2)
//		{
//			setConsoleColor(BRIGHT_WHITE, getRandomInt(0, 15));
//			gotoXY(symbolpos[i * 2], symbolpos[i * 2 + 1]);
//			putchar(symbol[!turn]);
//		}
//		gotoXY(0, 0);
//		drawLogo();
//		colorcount++;
//		turn = !turn;
//		// Flash the color for 5 seconds
//    	 if (colorcount == 20) // flash the color every 20 iterations (approx. 5 seconds)
//        {
//            setConsoleColor(BRIGHT_WHITE, color[colorcount % 6]);
//            system("cls");
//            colorcount = 0;
//        }
//        Sleep(250);
//
//    }
//		  // Reset the color back to default
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//    if (stopped) // clear the console if the animation is stopped
//    {
//        system("cls");
//    }
//}
//
//void drawMenu(){
//	setColor(Teal);
//  	gotoXY(30, 15);
//	 // Draw the top border
//    std::cout << "+------------------------------------------+" << std::endl;
//	
//    // Draw the game title
//    gotoXY(30, 16);
//    std::cout << "|            PIKACHU MAIN MENU             |" << std::endl;
//
//    // Draw the middle border
//    gotoXY(30, 17);
//    std::cout << "+-----+------------------------------------+" << std::endl;
//
//    // Draw the menu options
//    gotoXY(30, 18);    
//    std::cout << "|     |  Start Game                        |" << std::endl;
//    gotoXY(30, 19);
//	std::cout << "|     |  Instructions                      |" << std::endl;
//    gotoXY(30, 20);
//	std::cout << "|     |  High Scores                       |" << std::endl;
//	gotoXY(30, 21);
//	std::cout << "|     |  Music List                        |" << std::endl;
//	gotoXY(30, 22);
//	std::cout << "|     |  Quit			         |" << std::endl;
//	gotoXY(30, 23);
//    std::cout << "+-----+------------------------------------+" << std::endl;
//	
//    setColor(7);
//    
//}
//
//void pokemon(string fileName, int x, int y) {
//    ifstream file("picture.txt");
//
//    if (file.is_open()) {
//        char c;
//        int posX = 75, posY = 13;
//        while (file.get(c)) {
//            if (c == '/' || c == '(' || c == '_' || c == '|' || c == ',' || c == '.' || c == '>' || c == '-' || c == ';' || c == '`' || c == '<' || c == '"' || c == ')' || c == '\\' || c == '\'') {
//                
//                gotoXY(posX, posY);
//                setColor(Yellow);
//                cout << c;
//                posX++;
//            }
//            else if (c == '^') {
//                
//                gotoXY(posX, posY);
//                setColor(Yellow);
//                cout << c;
//                posX++;
//            }
//            else if (c == 'W'){
//            	gotoXY(posX, posY);
//                setColor(White);
//                cout << c;
//                posX++;
//			}
//			else if (c == 'B' || c == ':' || c == '.'){
//            	gotoXY(posX, posY);
//                setColor(Red);
//                cout << c;
//                posX++;
//			}
//            else if (c == '\n') {
//                posY++;
//                posX = x;
//            }
//            else {
//                
//                gotoXY(posX, posY);
//                setColor(Gray);
//                cout << c;
//                posX++;
//            }
//        }
//        file.close();
//    }
//}
//
//void drawStartMenu() {
//    // Clear the console
//    
//    clearConsole();
//    drawImage1();
// 
//	pokemon("picture.txt", 75, 15);
////	drawImage2();
//	
//     // Close the file
//  
//	drawImage3();
//	
//	
//	setColor(Teal);
//    // Draw the top border
//    gotoXY(32, 15);
//    std::cout << "+------------------------------------------+" << std::endl;
//    
//    // Draw the game title
//    gotoXY(32, 16);
//    std::cout << "|               PIKACHU GAME               |" << std::endl;
//
//    // Draw the middle border
//    gotoXY(32, 17);
//    std::cout << "+-----+------------------------------------+" << std::endl;
//
//    // Draw the menu options
//    gotoXY(32, 18);    
//    std::cout << "|     |  Easy Mode                         |" << std::endl;
//    gotoXY(32, 19);
//    std::cout << "|     |  Medium Mode                       |" << std::endl;
//    gotoXY(32, 20);
//    std::cout << "|     |  Hard Mode                         |" << std::endl;
//    gotoXY(32, 21);
//    std::cout << "|     |  Back                              |" << std::endl;
//    gotoXY(32, 22);
//    std::cout << "|     |  Exit                              |" << std::endl;
//
//    // Draw the bottom border
//    gotoXY(32, 23);
//    std::cout << "+-----+------------------------------------+" << std::endl;
//
//    // Reset the text color
//    setColor(7);
//    
//}
//
//void playEasy(){
//	string* background;
//	Game game(_EASY);
//    game.setupGame();
//    PlaySound(NULL, NULL, SND_PURGE);
//    game.startGame();
//    
//}
//
//void playMedium(){
//	Game game(_MEDIUM);
//  	game.setupGame();
////    createBackground("images\\medium.txt"); // Set the background for medium mode
//	PlaySound(NULL, NULL, SND_PURGE);
//    game.startGame();
//    
//}
//void playHard(){
//	Game game(_HARD);
//    game.setupGame();
////    createBackground("images\\medium.txt"); // Set the background for medium mode
//	PlaySound(NULL, NULL, SND_PURGE);
//    game.startGameHard();
//}
//void displayStartMenu() {
//    int option = 0;
//    system("cls");
//    while (true) {
//        drawStartMenu(); // call the function to draw the start menu
//	
//        // display the selected option
//        gotoXY(35, 18 + option);
//        std::cout << "-->";
//		
//        // wait for user input
//        char input = _getch();
//
//        switch (input) {
//            case 72: // up arrow
//            case 'w':
//            	PlaySound("click.wav", NULL, SND_ASYNC);
//                option = max(0, option - 1);
//                break;
//            case 80: // down arrow
//            case 's':
//            	PlaySound("click.wav", NULL, SND_ASYNC);
//                option = min(4, option + 1);
//                break;
//            case 13: // enter key
//                switch (option)
//                {
//                case 0:
//                    playEasy();
//                    
//                    break;
//                case 1:
//                    playMedium();
//                   
//                    break;
//                case 2:
//                    playHard();
//                    break;
//                case 3:
//                    displayMenu(0); // return to main menu
//                    break;
//                case 4:
//                    exitScreen();
//                    break;
//                }
//                _getch(); // wait for user to press a key
//                break;
//                Sleep(500);
//        }
//    }
//    
//}
//void printRectangle(int left, int top, int width, int height){
//	gotoXY(left, top);
//	putchar(218);
//	for (int i = 0; i < width; i++)
//		putchar(196);
//	putchar(191);
//
//	int i = 0;
//	for (; i < height; i++)
//	{
//		gotoXY(left, top + i + 1);
//		putchar(179);
//		gotoXY(left + width + 1, top + i + 1);
//		putchar(179);
//	}
//
//	gotoXY(left, top + i);
//	putchar(192);
//	for (i = 0; i < width; i++)
//		putchar(196);
//	putchar(217);
//}
//int getConsoleInput(){
//	int c = _getch();
//	// Arrow key
//	if (c == 0 || c == 224)
//	{
//		switch (_getch())
//		{
//		case KEY_UP:				//lên
//			return 2;
//		case KEY_LEFT:				//trái
//			return 3;
//		case KEY_RIGHT:				//phải
//			return 4;
//		case KEY_DOWN:				//xuống
//			return 5;
//		default:				//nút khác
//			return 0;
//		}
//	}
//	else
//	{
//		if (c == KEY_ESC)                  //esc
//			return 1;
//		else if (c == 87 || c == 119) //W, w
//			return 2;
//		else if (c == 65 || c == 97)  //A, a
//			return 3;
//		else if (c == 68 || c == 100) //D, d
//			return 4;
//		else if (c == 83 || c == 115) //S, s
//			return 5;
//		else if (c == 13)             //Enter
//			return 6;
//		else if (c == 72 || c == 104) //H, h
//			return 7;
//		else if (c == 77 || c == 109) // M, m
//			return 8;
//		else
//			return 0;                 //nút khác
//	}
//}
//
//void exitScreen(){
//	system("cls");
//	ShowCursor(false);
//	setConsoleColor(BRIGHT_WHITE, BLACK);
//	
//	setConsoleColor(BRIGHT_WHITE, BLACK);
//	printRectangle(34, 13, 35, 8);
//	printRectangle(37, 18, 7, 2);
//	printRectangle(60, 18, 6, 2);
//	setConsoleColor(BRIGHT_WHITE, RED);
//	gotoXY(0, 0);
//	drawLogo();
//	gotoXY(42, 16);
//	cout << "Do you want to exit?";
//	string str[2] = { "Yes", "No" };
//	int left[] = { 35,40,47,58,63,69 }, word[] = { 32,32,175,174 }, color[] = { BLACK, RED }, top = 19;
//	bool choice = 0;
//	bool loop = 1;
//	bool exitProgram = false; // new variable
//	auto print1 = [&]()
//	{
//		int i = 0;
//		while (i < 2)
//		{
//			PlaySound("click.wav", NULL, SND_ASYNC | SND_NOSTOP);
//		
//			gotoXY(left[choice * 3], top);        putchar(word[i * 2]);
//			gotoXY(left[choice * 3 + 1], top);    cout << str[choice];
//			gotoXY(left[choice * 3 + 2], top);    putchar(word[i * 2 + 1]);
//			if (!i++)
//				choice = !choice;
//		}
//		exitProgram = (choice == 0); // update exitProgram variable
//	};
//	print1();
//	while (loop)
//	{
//		int key = getConsoleInput();
//		if ((key == 3 && choice == 1) || (key == 4 && choice == 0))
//		{	
//			print1();
//		}
//		else if (key == 6)
//        {
//            if (!choice)
//            {   
//                
//                system("cls");
//                exitProgram = true;
//                break;
//            }
//            
//            else // add this else block to change color back to default
//            {
//                setConsolecolor(BRIGHT_WHITE, BLACK);
//                return;
//            }
//        }
////		else
////		{
////			Controller::playSound(ERROR_SOUND);
////		}
//	}
//	if (exitProgram) // check if user wants to exit
//		exit(0);
//	 
//}
//void instructionScreen(){
//	ShowCursor(false);
//	
//	system("cls");
//	int left = 5, top = 2, width = 85, height = 23;
//	int line1 = 6, line2 = 19, line3 = 20, line4 = 15;
//	printRectangle(left, top, width, height);
//	gotoXY(left + 1, line1);
//	for (int i = 0; i < width; i++)
//	{
//		putchar(196);
//	}
//	gotoXY(left + 1, line2);
//	for (int i = 0; i < width; i++)
//	{
//		putchar(196);
//	}
//	gotoXY(left + 1, line4);
//	for (int i = 0; i < width; i++)
//	{
//		putchar(196);
//	}
//	for (int i = 1; i < height; i++)
//	{
//		gotoXY(line3, top + i);
//		putchar(179);
//	}
//	gotoXY(line3, line1);
//	putchar(197);
//	gotoXY(line3, line2);
//	putchar(197);
//
//	gotoXY(left + 3, top + 2);
//	setColor(White);
//	
//	cout << "Moves:";
//	gotoXY(left + 20, top + 1);
//	setColor(Cyan);
//	
//	putchar(249); cout << "Up:    W, up arrow";
//	gotoXY(left + 52, top + 1);
//	setColor(Cyan);
//	putchar(249); cout << "Down:  S, down arrow";
//	gotoXY(left + 20, top + 3);
//	setColor(Cyan);
//	putchar(249); cout << "Left:  A, left arrow";
//	gotoXY(left + 52, top + 3);
//	setColor(Cyan);
//	putchar(249); cout << "Right: D, right arrow";
//	
//	
//	gotoXY(left + 3, top + 8);
//	setColor(White);
//	cout << "Rules:";
//	gotoXY(left + 17, top + 5);
//	int left1 = left + 17;
//	
//	setColor(Orange);
//	putchar(249); cout << " The Matching Game (commonly known as the Pikachu Puzzle Game)";
//	gotoXY(left1, top + 6);
//	cout << " includes a board of multiple cells, each of which presents a figure.";
//	gotoXY(left1, top + 8);
//	setColor(Orange);
//	putchar(249); cout << " The player finds and matches a pair of cells that contain the same";
//	gotoXY(left1, top + 9);
//	cout << " figure and connect each other in some particular pattern.";
//	gotoXY(left1, top + 11);
//	setColor(Orange);
//	putchar(249); cout << " A legal match will make the two cells disappear. The game ends when";
//	gotoXY(left1, top + 12);
//	cout << " all matching pairs are found.";
//	setColor(Orange);
//	gotoXY(left + 3, top + 15);
//	setColor(White);
//	cout << "Scoring:";
//	
//
//	gotoXY(left1 + 10, top + 14);
//	putchar(249); cout << " I Matching: +1 points";
//	
//	gotoXY(left1 + 40, top + 14);
//	putchar(249); cout << " L Matching: +2 points";
//	setColor(Yellow);
//	gotoXY(left1 + 10, top + 15);
//	putchar(249); cout << " Z Matching: +3 points";
//	setColor(Green);
//	gotoXY(left1 + 40, top + 15);
//	putchar(249); cout << " U Matching: +4 points";
//	
//	setColor(Red);
//	gotoXY(left1 + 10, top + 16);
//	putchar(249); cout << " Not Matched: -2 points";
//	
//	setColor(Red);
//	gotoXY(left1 + 40, top + 16);
//	putchar(249); cout << " Move suggestion: -2 points";
//	
//	
//	gotoXY(left + 3, top + 20);
//	setColor(White);
//	cout << "Developers:";
//	gotoXY(left + 31, top + 19);
//	setColor(Teal);
//	cout << "Dev 1: Nguyen Bao Long (22127243))";
//	gotoXY(left + 31, top + 21);
//	setColor(Teal);
//	cout << "Dev 2: Bui Minh Quan (22127342)";
//
//
//	// code for the "Back" button
//	printRectangle(45, 27, 8, 2);
//	gotoXY(43, 28);
//	putchar(175);
//	gotoXY(48, 28);
//	setColor(Red);
//	cout << "Back";
//	gotoXY(56, 28);
//	putchar(174);
//	// wait for user input
//	while (true) {
//   		if (_kbhit()) {
//        	char c = _getch();
//        if (c == 'B' || c == 'b' || c == '\r') {  // check if the user pressed "B" or "b"
//            displayMenu(2);  // call the main menu function
//            break;
//        	}
//    	}
//	}
////	while (getConsoleInput() != 6)
////	{
////		Controller::playSound(ERROR_SOUND);
////	}
//}
////void playMusic(string filename) {
////    PlaySound(filename.c_str(), NULL, SND_ASYNC);
////}
////void displayCurrentSong() {
////    // Move the cursor to the bottom right corner of the screen
////    gotoXY(78, 27);
////    // Display the current playing song
////    std::cout << "Now Playing: " << songList[currentSongIndex];
////}
//
////    std::string filekey;
////    // Stop the current song
////    PlaySound(NULL, NULL, 0);
////    vector<string> musicList = {"Despacito.wav", "See_You_Again.wav", "Wallpaper.wav"};
////    int currentSongIndex = 0;
////    // Update the current song index
////    currentSongIndex = key - 1; // Subtract 1 since the index starts at 0
////    if (currentSongIndex < 0) {
////        currentSongIndex = 0;
////    } else if (currentSongIndex >= musicList.size()) {
////        currentSongIndex = musicList.size() - 1;
////    }
////    
////    // Play the new song
////    playMusic(musicList[currentSongIndex]);
////}
//
//
//void displayMusicList() {
//    system("cls");
//    
//    vector<string> musicList = {
//    "Despacito.wav",
//    "See_You_Again.wav",
//    "Wallpaper.wav",
//    "Senorita.wav",
//    "Shape_of_you.wav",
//    "Dance_monkey.wav",
//    "Memories.wav",
//    "Closer.wav"
//	};
//	
//	
//    printrectangle(7, 2, 104, 20); // draw a rectangle around the music list
////    drawLogo();
//	gotoxy(45, 2);
//    setColor(Yellow);
//    cout << R"(
//		.___  ___.  __    __       _______. __    ______     __       __       _______..___________.
//		|   \/   | |  |  |  |     /       ||  |  /      |   |  |     |  |     /       ||           |
//		|  \  /  | |  |  |  |    |   (----`|  | |  ,----'   |  |     |  |    |   (----``---|  |----`
//		|  |\/|  | |  |  |  |     \   \    |  | |  |        |  |     |  |     \   \        |  |     
//		|  |  |  | |  `--'  | .----)   |   |  | |  `----.   |  `----.|  | .----)   |       |  |     
//		|__|  |__|  \______/  |_______/    |__|  \______|   |_______||__| |_______/        |__|  
//		                                                                                     
//	)";
//	setColor(Green);
//    gotoxy(50, 12);
//    std::cout << "1. Despacito \n";
//    gotoxy(50, 13);
//    std::cout << "2. See You Again \n";
//    gotoxy(50, 14);
//    std::cout << "3. Game Theme Song\n";
//    gotoxy(50, 15);
//    std::cout << "4. Senorita \n";
//    gotoxy(50, 16);
//    std::cout << "5. Shape of you \n";
//    gotoxy(50, 17);
//    std::cout << "6. Dance Monkeys \n";
//    gotoxy(50, 18);
//    std::cout << "7. Memories \n";
//    gotoxy(50, 19);
//    std::cout << "8. Closer \n";
//    
//    setColor(White);
//    gotoxy(18, 10);
//   	//Input choice
//   	cout << "Please choose a song to play, (or press B to return)!";
//   	
//	// code for the "Back" button
//	printRectangle(50, 27, 8, 2);
//	gotoXY(47, 28);
//	putchar(175);
//	gotoXY(53, 28);
//	setColor(Cyan);
//	cout << "Back";
//	gotoXY(60, 28);
//	putchar(174);
//	
//
//	setColor(Orange);
//	
//    while (true) {
//
//        char input = _getch();
//        switch (input) {
//            case '1':
//                PlaySound(TEXT("Despacito.wav"), NULL, SND_ASYNC);
//                selectedSong = 1;
//                gotoxy(18, 24);
//            	std::cout << "\nPlaying Despacito!  Press 'B' to go back ";
//                break;
//            case '2':
//                PlaySound(TEXT("See_You_Again.wav"), NULL, SND_ASYNC);
//                selectedSong= 2;
//                gotoxy(18, 24);
//            	std::cout << "\nPlaying See You Again! Press 'B' to go back ";
//                break;
//            case '3':
//                PlaySound(TEXT("Wallpaper.wav"), NULL, SND_ASYNC);
//                selectedSong = 3;
//                gotoxy(18, 24);
//            	std::cout << "\nPlaying Game Theme Song! Press 'B' to go back ";
//                break;
//            case '4':
//                PlaySound(TEXT("Senorita.wav"), NULL, SND_ASYNC);
//                selectedSong = 4;
//                gotoxy(18, 24);
//            	std::cout << "\nPlaying Senorita! Press 'B' to go back ";
//                break;
//            case '5':
//                PlaySound(TEXT("Shape_of_you.wav"), NULL, SND_ASYNC);
//                selectedSong = 5;
//                gotoxy(18, 24);
//            	std::cout << "\nPlaying Shape of You! Press 'B' to go back ";
//                break;
//            case '6':
//                PlaySound(TEXT("Dance_monkey.wav"), NULL, SND_ASYNC);
//                selectedSong = 6;
//                gotoxy(18, 24);
//            	std::cout << "\nPlaying Dance Monkey! Press 'B' to go back ";
//                break;
//            case '7':
//                PlaySound(TEXT("Memories.wav"), NULL, SND_ASYNC);
//                selectedSong = 7;
//                gotoxy(18, 24);
//            	std::cout << "\nPlaying Memories! Press 'B' to go back ";
//                break;
//            case '8':
//                PlaySound(TEXT("Closer.wav"), NULL, SND_ASYNC);
//                selectedSong = 8;
//                gotoxy(18, 24);
//            	std::cout << "\nPlaying Closer! Press 'B' to go back ";
//                break;
//            case 'b':
//            case 'B':
//        	case '\r':
//        		displayMenu(3); // pass selectedSong as a parameter
//        		break;
//			
//            default:
//            	gotoxy(18, 23);
//            	setColor(Orange);
//                std::cout << "\nInvalid input. Enter a number to play a song (or press 'b' to go back)! ";
//                continue; // continue waiting for valid input
//        system("cls");
//        
//    }
//    
//	}
//	
//}
//void playSelectedSong() {
//    switch (selectedSong) {
//        case 1:
//            PlaySound(TEXT("Despacito.wav"), NULL, SND_ASYNC);
//            break;
//        case 2:
//            PlaySound(TEXT("See_You_Again.wav"), NULL, SND_ASYNC);
//            break;
//        case 3:
//            PlaySound(TEXT("Wallpaper.wav"), NULL, SND_ASYNC);
//            break;
//        case 4:
//            PlaySound(TEXT("Senorita.wav"), NULL, SND_ASYNC);
//            break;
//        case 5:
//            PlaySound(TEXT("Shape_of_you.wav"), NULL, SND_ASYNC);
//            break;
//        case 6:
//            PlaySound(TEXT("Dance_monkey.wav"), NULL, SND_ASYNC);
//            break;
//        case 7:
//            PlaySound(TEXT("Memories.wav"), NULL, SND_ASYNC);
//            break;
//        case 8:
//            PlaySound(TEXT("Closer.wav"), NULL, SND_ASYNC);
//            break;
//        default:
//            PlaySound(TEXT("Wallpaper.wav"), NULL, SND_ASYNC);
//            break;
//    }
//}
//
//void intro(){
//	system("cls");
//	printAnimation();
//}
//
//void drawLeaderBoard() {
//	system("cls");
////	Player p[100];
//	setColor(Teal);
//	cout << R"(
//     _      U _____ u     _        ____    U _____ u    ____        ____      U  ___ u     _         ____       ____    
//    |"|     \| ___"|/ U  /"\  u   |  _"\   \| ___"|/ U |  _"\ u  U | __")u     \/"_ \/ U  /"\  u  U |  _"\ u   |  _"\   
//  U | | u    |  _|"    \/ _ \/   /| | | |   |  _|"    \| |_) |/   \|  _ \/     | | | |  \/ _ \/    \| |_) |/  /| | | |  
//   \| |/__   | |___    / ___ \   U| |_| |\  | |___     |  _ <      | |_) | .-,_| |_| |  / ___ \     |  _ <    U| |_| |\ 
//    |_____|  |_____|  /_/   \_\   |____/ u  |_____|    |_| \_\     |____/   \_)-\___/  /_/   \_\    |_| \_\    |____/ u 
//    //  \\   <<   >>   \\    >>    |||_     <<   >>    //   \\_   _|| \\_        \\     \\    >>    //   \\_    |||_    
//   (_")("_) (__) (__) (__)  (__)  (__)_)   (__) (__)  (__)  (__) (__) (__)      (__)   (__)  (__)  (__)  (__)  (__)_)   
//	)";
//	
//	setColor(Orange);
//	printRectangle(5, 10, 105, 17);
//
//	setColor(Yellow);
//	gotoXY(9, 11);
//	cout << "Rank";
//	setColor(Orange);
//	for (int i = 1; i < 17; i++)
//	{
//		gotoXY(15, 10 + i);
//		putchar(179);
//	}
//	for (int i = 6; i < 15; i++)
//	{
//		gotoXY(i, 12);
//		putchar(196);
//	}
//	setColor(Teal);
//	gotoXY(21, 11);
//	cout << "Name";
//	setColor(Orange);
//	for (int i = 1; i < 17; i++)
//	{
//		gotoXY(30, 10 + i);
//		putchar(179);
//	}
//	for (int i = 16; i < 30; i++)
//	{
//		gotoXY(i, 12);
//		putchar(196);
//	}
//	setColor(Green);
//	gotoXY(37, 11);
//	cout << "ID";
//	setColor(Orange);
//	for (int i = 1; i < 17; i++)
//	{
//		gotoXY(45, 10 + i);
//		putchar(179);
//	}
//	for (int i = 31; i < 45; i++)
//	{
//		gotoXY(i, 12);
//		putchar(196);
//	}
//	setColor(Blue);
//	gotoXY(52, 11);
//	cout << "Class";
//	setColor(Orange);
//	for (int i = 1; i < 17; i++)
//	{
//		gotoXY(62, 10 +i);
//		putchar(179);
//	}
//	for (int i = 46; i < 62; i++)
//	{
//		gotoXY(i, 12);
//		putchar(196);
//	}
//	setColor(Magenta);
//	gotoXY(69, 11);
//	cout << "Mode";
//	setColor(Orange);
//	for (int i = 1; i < 17; i++)
//	{
//		gotoXY(78, 10 + i);
//		putchar(179);
//	}
//	for (int i = 63; i < 78; i++)
//	{
//		gotoXY(i, 12);
//		putchar(196);
//	}
//
//	setColor(Red);
//	gotoXY(84, 11);
//	cout << "Score";
//	setColor(Orange);
//	for (int i = 1; i < 17; i++)
//	{
//		gotoXY(94, 10 + i);
//		putchar(179);
//	}
//	for (int i = 79; i < 94; i++)
//	{
//		gotoXY(i, 12);
//		putchar(196);
//	}
//	setColor(Purple);
//	gotoXY(101, 11);
//	cout << "Time";
//	setColor(Orange);
//	for (int i = 95; i < 111; i++)
//	{
//	    gotoXY(i, 12);
//	    putchar(196);
//	}
////	int y = 11;
////	int lines = 8;
////	int n = 0;
////	string tmp;
//// Read data from binary file
//	std::vector<Player> players;
//	Player p;
//	std::string playerName;
//	int playerID;
//	std::string playerClass;
//	    
//	fstream fs("player_info.dat", ios::binary|ios::in|ios::app);
//	if (!fs) {
//	    std::cerr << "Failed to open file for reading.\n";
//	    return;
//	}
//	
//	while (fs.read((char*)&playerName, sizeof(playerName))) {
//	    fs.read((char*)&playerID, sizeof(playerID));
//	    fs.read((char*)&playerClass, sizeof(playerClass));
//	       
//	    Player p = {playerName, playerID, playerClass};
//	    
//	    players.push_back(p);
//	}
//	fs.close();
////	for (int i = 0; i < n; i++) {
////		for (int j = i + 1; j < n; j++) {
////			if (p[j].score > p[i].score) {
////				swap(p[i], p[j]);
////			}
////		}
////	}
//
//// Display leaderboard
//	for (size_t i = 0; i < players.size(); i++) {
//	    gotoXY(10, 13 + i);
//	    std::cout << i + 1 << std::endl;
//	
//	    gotoXY(21, 13 + i);
//	    std::cout << players[i].playerName << std::endl;
//	
//	    gotoXY(33, 13 + i);
//	    std::cout << players[i].playerID << std::endl;
//	
//	    gotoXY(52, 13 + i);
//	    std::cout << players[i].playerClass << std::endl;
////	
////	    gotoXY(84, 13 + i);
////	    std::cout << players[i].score << std::endl;
////	
////	    gotoXY(101, 13 + i);
////	    std::cout << players[i].time << std::endl;
//	} 
//	
//	printRectangle(49, 29, 8, 2);
//	setColor(Orange);
//	gotoXY(47, 30);
//	putchar(175);
//	gotoXY(52, 30);
//	cout << "Back";
//	gotoXY(60, 30);
//	putchar(174);
//	while (true) {
//   		if (_kbhit()) {
//        	char c = _getch();
//        if (c == 'B' || c == 'b' || c == '\r') {  // check if the user pressed "B" or "b"
//            displayMenu(2);  // call the main menu function
//            break;
//        }
//    }
//}
//
//}
//void displayMenu(int option)
//{	
//	
//	
//	system("cls");
//    bool music_paused = true;
//	int selectedSong = 0;
//	showCursor(false);
//	
//	bool loadMenu = 1;	
////	intro();
//
//	
//	
//    while (true) {
//       
//        
//		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//    	COORD curdsorPos = {0, 4}; // declare and initialize cursorPos
//
//    	SetConsoleCursorPosition(console, cursorPos);
//    	
//		printAnimation();
//		 if (loadMenu)
//			drawLogo();
//			
//		
//		playSelectedSong();
//    
////		PlaySound(TEXT("Wallpaper.wav"), NULL, SND_ASYNC);
//    	
//    	
//    	while (true){
//    	
//    	drawMenu(); // draw the menu
//		
//		
//        // display the selected option
//        gotoXY(33, 18 + option);
//        std::cout << "-->";
//
//        // wait for user input
//        char input = _getch();
//		
//        switch (input) {
//            case 72: // up arrow
//            case 'w':
//            	PlaySound("click.wav", NULL, SND_ASYNC | SND_NOSTOP);
//                option = max(0, option - 1);
//                break;
//            case 80: // down arrow
//            case 's':
//            	PlaySound("click.wav", NULL, SND_ASYNC | SND_NOSTOP);
//                option = min(4, option + 1);
//                break;
//            case 13: // enter key
//                switch (option)
//                {
//                case 0:
//                	displayStartMenu();
//                	loadMenu = 0;
//                    break;
//                case 1:
//                    instructionScreen();
//                    loadMenu = 0;
//                    break;
//                case 2:
//					drawLeaderBoard();
//                    loadMenu = 0;
//                    break;
//                case 3:
//                	displayMusicList();
//                	playSelectedSong();
//                	loadMenu = 0;
//                	system("cls");
//                	break;
//                
//                case 4:
//                    exitScreen();
//                    loadMenu = 0;
//                    return; // exit the program if user chooses to exit
//					break;
//				}
//                _getch(); // wait for user to press a key
//                break;
//            case 109: // M key
//    
//   				_getch(); // wait for user to press a key
//    			music_paused = !music_paused;
//    			if (music_paused) {
//        			PlaySound(NULL, NULL, SND_PURGE); // stop currently playing sound
//    			} else {
//        			playSelectedSong();  
//    			}
//    			gotoXY(0, 23); // go to the top-left corner of the output screen
//				std::cout << "Music: " << (music_paused ? "OFF" : "ON") << " "; // print the on/off volume image
//				break;
//    		
//				
//        	}
//    	}
//	}
// system("cls");
//}                               
