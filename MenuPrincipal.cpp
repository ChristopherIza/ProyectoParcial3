/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * 
 * @file MenuPrincipal.cpp
 * @author De Veintemilla Luca- Iza Christopher- Rea Denise - Vargas Kevin
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "MenuPrincipal.hpp"
#include "MenuGUI.hpp"
#include "Input.hpp"
#include "GlobalVariables.hpp"
#include "PDFManager.hpp"
#include "ConsoleDataInput.hpp"
#include <iostream>
#include "Imagen.h"
#include "play.hpp"

MenuGUI MenuPrincipal::menuGraphic;


bool MenuPrincipal::switchOption(int optionSelected) {
    switch (optionSelected) {
        case 1:
            printTree();
            break;
        case 2:
            printImage();    
            break;
        case 3:
            generatePDF();
            break;
        case 4:
            openHelp();
            break;
        case 5:
            signOut();
            return true;
            break;
    }

    return false;
}

void MenuPrincipal::printTree() {
    system("cls");
    play p;
    p.start();
    system("pause > nul");
}


void MenuPrincipal::printImage() {
    Imagen image;
     system("cls");
    image.Imagenes();
    system("pause>nul");
    //GlobalVariables::printImageAvailable = true;
}

void MenuPrincipal::generatePDF() {
    PDFManager pd;
    pd.generatePDF();
}

void MenuPrincipal::openHelp() {
    system("start Ajedrez.chm");
    system("pause > nul");
}

void MenuPrincipal::signOut() {

}

void MenuPrincipal::start() {
    menuGraphic.setTitleMenu("MENU PRINCIPAL");

    const size_t AMOUNT_OPTIONS{5};
    menuGraphic.setListOptions(
        new std::string[AMOUNT_OPTIONS] {
            "Abrir Ajedrez",
            "Imprimir imagen",
            "Generar PDF",
            "Ayuda",
            "Cerrar sesion"
        },
        AMOUNT_OPTIONS
    );

    menuGraphic.setPositionOfMenu({12, 5});

    bool exit{false};

    while (!exit) {
        exit = switchOption(menuGraphic.print());
    }
}
