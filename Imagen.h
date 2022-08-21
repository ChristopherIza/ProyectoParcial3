/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * 
 * @file Imagen.h
 * @author De Veintemilla Luca- Iza Christopher- Rea Denise - Vargas Kevin
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <vector>
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <sstream>
#pragma once
#include <stdio.h>
#include "EasyBMP.h"

class Imagen {
	public:
	/**
	 * @brief 
	 * 
	 */
	void Imagenes();

	/**
	 * @brief 
	 * 
	 * @return int 
	 */
	int runIMG();

	/**
	 * @brief 
	 * 
	 * @param imagePath 
	 * @param console 
	 */
	void drawImage(std::string imagePath, HDC* console);
};