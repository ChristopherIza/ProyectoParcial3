/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Juego de Ajedrez 
 * Autor:  De Veintemilla Luca- Iza Christopher- Rea Denise - Vargas Kevin
 * Fecha de creacion: 2022-07-12
 * Fecha de ultima modificación: 2022-07-13
 * Github: https://github.com/ChristopherIza/Arboles_AVL.git
 */

// #include "MenuPrincipal.hpp"
#include "Login.hpp"
#include "Marquee.hpp"
#include "GlobalVariables.hpp"

#include <thread>
using namespace std;


void menu(){
    Login menu;
    menu.start();
}
void marquee(std::string text) {
HANDLE conhandler = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int ancho, alto;
    GetConsoleScreenBufferInfo(conhandler, &csbi);
    ancho = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    SetConsoleCursorPosition(conhandler, { 0, 4 });

    while (true) {
        std::string temp = text;
        text.erase(0, 1);
        text += temp[0];
        CHAR_INFO* buff = (CHAR_INFO*)calloc(ancho, sizeof(CHAR_INFO));

        for (int i = 0; i < text.length(); i++) {
            buff[i].Char.AsciiChar = text.at(i);
            buff[i].Attributes = 15;
        }

        SMALL_RECT pos = { 0, 0, ancho, 1 };
        WriteConsoleOutputA(conhandler, buff, { (SHORT)ancho, 1 }, { 0, 0 }, &pos);
        free(buff);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

}

int main() {
    std::string texto = "      PROYECTO AJEDREZ       ";
	std::thread t2(marquee, texto);
	t2.detach();
	system("cls");
	cout << "\n";
    menu();
    return 0;
}