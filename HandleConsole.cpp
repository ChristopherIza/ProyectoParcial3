/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * 
 * @file HandleConsole.cpp
 * @author De Veintemilla Luca- Iza Christopher- Rea Denise - Vargas Kevin
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "HandleConsole.hpp"

void HandleConsole::setCursorPosition(SHORT x, SHORT y) {
    HANDLE consoleIndentificator{GetStdHandle(STD_OUTPUT_HANDLE)};
    COORD position{x, y};
    SetConsoleCursorPosition(consoleIndentificator, position);
}

void HandleConsole::setCursorVisibilitie(bool isEnabled) {
    HANDLE consoleIdentificator{GetStdHandle(STD_OUTPUT_HANDLE)};
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = isEnabled;
    const short DEFAULT_CURSOR_SIZE{3};
    const short INVISIBLE_CURSOR_SIZE{1};
    cursor.bVisible = isEnabled;
    cursor.dwSize = (isEnabled) ? INVISIBLE_CURSOR_SIZE: DEFAULT_CURSOR_SIZE;
    SetConsoleCursorInfo(consoleIdentificator, &cursor);
}