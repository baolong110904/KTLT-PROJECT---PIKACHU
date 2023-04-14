//#include "console_setting.h"
//
//
//extern HWND consoleWindow = GetConsoleWindow();
//extern HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//
//// Function to set the console window size
//void setConsoleSize(int width, int height) {
//    HWND console = GetConsoleWindow();
//    RECT r;
//    GetWindowRect(console, &r);
//    MoveWindow(console, r.left, r.top, width, height, TRUE);
//}
//
//
//void hideConsoleScrollBar() 
//{
//    // Get the console window handle
//    HWND consoleWindow = GetConsoleWindow();
//
//    // Get the console window style
//    DWORD consoleStyle = GetWindowLong(consoleWindow, GWL_STYLE);
//
//    // Hide the vertical scroll bar
//    consoleStyle &= ~WS_VSCROLL;
//
//    // Set the new console window style
//    SetWindowLong(consoleWindow, GWL_STYLE, consoleStyle);
//}
//
//
//// Function to set the console font size and type
//void setConsoleFont(int size, const wchar_t* font) {
//    CONSOLE_FONT_INFOEX cfi;
//    cfi.cbSize = sizeof(cfi);
//    cfi.nFont = 0;
//    cfi.dwFontSize.X = 0;
//    cfi.dwFontSize.Y = size;
//    cfi.FontFamily = FF_DONTCARE;
//    cfi.FontWeight = FW_NORMAL;
//    wcscpy_s(cfi.FaceName, LF_FACESIZE, font);
//    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
//}
//
//// Function to set the console window to be resizable
//void setConsoleResizable(bool resizable) {
//    HWND console = GetConsoleWindow();
//    LONG style = GetWindowLong(console, GWL_STYLE);
//    if (resizable) {
//        style |= WS_THICKFRAME;
//    }
//    else {
//        style &= ~WS_THICKFRAME;
//    }
//    SetWindowLong(console, GWL_STYLE, style);
//}
//
//// Function to set the console window to be maximizable
//void setConsoleMaximizable(bool maximizable) {
//    HWND console = GetConsoleWindow();
//    LONG style = GetWindowLong(console, GWL_STYLE);
//    if (maximizable) {
//        style |= WS_MAXIMIZEBOX;
//    }
//    else {
//        style &= ~WS_MAXIMIZEBOX;
//    }
//    SetWindowLong(console, GWL_STYLE, style);
//}
//
//void disableMouseInput()
//{
//    DWORD prev_mode;
//    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
//    GetConsoleMode(hInput, &prev_mode);
//    SetConsoleMode(hInput, prev_mode & ~ENABLE_QUICK_EDIT_MODE);
//}
//void disableMaximize()
//{
//    //HWND consoleWindow = GetConsoleWindow();
//    SetWindowLong(consoleWindow, GWL_STYLE,
//        GetWindowLong(consoleWindow, GWL_STYLE) & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME));
//}
//
//
//
//void setAndCenterWindow()
//{
//    RECT rectClient, rectWindow;
//    GetClientRect(consoleWindow, &rectClient), GetWindowRect(consoleWindow, &rectWindow);
//    int width = 950;
//    int height = 650;
//    int posX = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
//    int posY = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
//    MoveWindow(GetConsoleWindow, posX, posY, width, height, TRUE);
//}
//
//void initConsole(int width, int height) {
//    // Set the console window size
//    //setConsoleSize(width, height);
//
//    // Set the console window title
//    SetConsoleTitle(TEXT("PIKACHU - THE MATCHING GAME"));
//    
//    //Maximizing the console when run
//    system("mode 650");
//    
//    // Set the console font size and type
//    setConsoleFont(16, L"Consolas");
//
//    // Set the console window to be resizable
//    setConsoleResizable(false);
//
//    // Set the console window to be maximizable
//    setConsoleMaximizable(false);
//
//    //Disable mouse input
//    disableMouseInput();
//
//    //Hide scroll bar
//    hideConsoleScrollBar();
//
//    //Set and center window
//    setAndCenterWindow();
//}
