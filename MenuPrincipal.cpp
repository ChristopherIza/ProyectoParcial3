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
            insertValue();
            break;
        case 2:
            deleteValue();
            break;
        case 3:
            searchValue();
            break;
        case 4:
            printTree();
            break;
        case 5:
            startMenuBackup();
            break;
        case 6:
            printImage();
            
            break;
        case 7:
            generatePDF();
            break;
        case 8:
            openHelp();
            break;
        case 9:
            signOut();
            return true;
            break;
    }

    return false;
}

void MenuPrincipal::insertValue() {
    std::cout << "Ingresa valor entero a guardar: ";
    //binaryAVLTree.add(Input::integerNumber(MINIMUM_DIGITS, MAXIMUM_DIGITS));
    int dato;
    ConsoleDataInput console;
    dato = console.integerNumber(MINIMUM_DIGITS, MAXIMUM_DIGITS,45,16);
    /*binaryAVLTree.add(dato);

    if (FileManager::saveTree(binaryAVLTree))
        std::cout << "\nArbol guardado en txt con exito\n";
    else
        std::cout << "\nInformacion de arbol no guardada en txt\n";
*/
    system("pause > nul");
}

void MenuPrincipal::deleteValue() {
    std::cout << "Ingresa valor entero a eliminar: ";
    //binaryAVLTree.remove(Input::integerNumber(MINIMUM_DIGITS, MAXIMUM_DIGITS));
    
    int dato;
    ConsoleDataInput console;
    dato = console.integerNumber(MINIMUM_DIGITS, MAXIMUM_DIGITS,45,16);
   /* binaryAVLTree.remove(dato);

    if (FileManager::saveTree(binaryAVLTree))
        std::cout << "\nArbol guardado en txt con exito\n";
    else
        std::cout << "\nInformacion de arbol no guardada en txt\n";
*/
    system("pause > nul");
}

void MenuPrincipal::searchValue() {
    std::cout << "Ingresa valor entero a buscar: ";
    int dato;
    ConsoleDataInput console;
    dato = console.integerNumber(MINIMUM_DIGITS, MAXIMUM_DIGITS,45,16);

   /* std::cout << (binaryAVLTree.search(dato) ? "Valor encontrado" : "Valor no encontrado");
   */
    system("pause > nul");
}

void MenuPrincipal::printTree() {
    system("cls");
    play p;
    p.start();
   // PrintTree::printGraphic(binaryAVLTree);
    system("pause > nul");
}

void MenuPrincipal::startMenuBackup() {
    //MenuBackup::start(binaryAVLTree);
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
    system("start help.chm");
    system("pause > nul");
}

void MenuPrincipal::signOut() {

}

void MenuPrincipal::start() {
    menuGraphic.setTitleMenu("MENU PRINCIPAL");

    const size_t AMOUNT_OPTIONS{9};
    menuGraphic.setListOptions(
        new std::string[AMOUNT_OPTIONS] {
            "Insertar valor",
            "Eliminar valor",
            "Buscar valor",
            "Imprimir arbol",
            "Backup",
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
