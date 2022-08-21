/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * 
 * @file user_interface.h
 * @author De Veintemilla Luca- Iza Christopher- Rea Denise - Vargas Kevin
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include "chess.h"

#define WHITE_SQUARE 0xDB
#define BLACK_SQUARE 0xFF
#define EMPTY_SQUARE 0x20

/**
 * @brief Create a Next Message object
 * 
 * @param msg 
 */
void createNextMessage( string msg );

/**
 * @brief 
 * 
 * @param msg 
 */
void appendToNextMessage( string msg );

/**
 * @brief 
 * 
 */
void clearScreen( void );

/**
 * @brief 
 * 
 */
void printLogo( void );

/**
 * @brief 
 * 
 */
void printLogo( void );

/**
 * @brief 
 * 
 */
void printMenu( void );

/**
 * @brief 
 * 
 */
void printMessage( void );

/**
 * @brief 
 * 
 * @param iLine 
 * @param iColor1 
 * @param iColor2 
 * @param game 
 */
void printLine( int iLine, int iColor1, int iColor2, Game& game );

/**
 * @brief 
 * 
 * @param game 
 */
void printSituation( Game& game );

/**
 * @brief 
 * 
 * @param game 
 */
void printBoard(Game& game);