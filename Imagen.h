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