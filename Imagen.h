#include <vector>
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <sstream>
#pragma once
#include <stdio.h>
#include "EasyBMP.h"

class Imagen {
	// Private section
	public:
	void Imagenes();
	int runIMG();
	void drawImage(std::string imagePath, HDC* console);
	


};