/**
 * @file PDFManager.cpp
 * @author De Veintemilla Luca- Iza Christopher- Rea Denise - Vargas Kevin
 * @brief Development
 * @version 0.1
 * @date 2022-08-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cmath>
#include "PDFManager.hpp"
#include "pdf.hpp"

#include <vector>

using std::ostringstream;
using std::ifstream;
using std::cout;
using std::endl;
using std::ios;

static vector <int> Order;

static void demoThree(PDF &p)
{
      vector<XY> points;
   ImageRow row1;
   ImageRow row2;

   row1.push_back(RGB(0, 0, 0));
   row1.push_back(RGB(255,255, 255));
   row1.push_back(RGB(  0, 0,  0));
   row1.push_back(RGB(255,255, 255));
   row1.push_back(RGB(  0, 0,  0));
   row1.push_back(RGB(255,255, 255));
   row1.push_back(RGB(  0, 0,  0));
   row1.push_back(RGB(  255, 255, 255));


   row2.push_back(RGB(  255, 255, 255));
   row2.push_back(RGB(0, 0,   0));
   row2.push_back(RGB(  255, 255, 255));
   row2.push_back(RGB(  0, 0,  0));
   row2.push_back(RGB(  255, 255, 255));
   row2.push_back(RGB(  0, 0,  0));
   row2.push_back(RGB(  255, 255, 255));
   row2.push_back(RGB(  0, 0,  0));


   Image anImage;

   anImage.push_back(row1);
   anImage.push_back(row2);
   anImage.push_back(row1);
   anImage.push_back(row2);
   anImage.push_back(row1);
   anImage.push_back(row2);
   anImage.push_back(row1);

   ImageInfo info = p.processImage(anImage);
   double scale   = 10.0;
   int xValue = 50 ; 
      int yValue =680 ;
   p.showImage(info, xValue, yValue, scale);
    p.drawRect(
         xValue,
         yValue,
         (int)(scale * info.mWidth  + 0.5),
         (int)(scale * info.mHeight + 0.5)
      );

   p.drawCircle(512,750,15);
   points.push_back(XY(527, 735));
   points.push_back(XY(495, 735));
   points.push_back(XY(495, 730));
   points.push_back(XY(527, 730));
   points.push_back(XY(527, 735));
   p.setLineColor(0, 0, 0);
   p.drawLine(points);
   points.clear();
   points.push_back(XY(500, 730));
   points.push_back(XY(495, 680));
   points.push_back(XY(532, 680));
   points.push_back(XY(523, 730));
   p.setLineColor(0, 0, 0);
   p.drawLine(points);
   //********************************Título***********************************
   p.setFont(PDF::TIMES_BOLD_ITALIC,35);
   p.showTextXY("  A J E D R E Z ",170, 710);
   //************************Pie de Página************************************
   p.setFont(PDF::TIMES_BOLD,10);
   p.showTextXY("Autores:      Iza Christopher    - * -    Rea Denise     - * -    De Veintimilla Luca     - * -    Vargas Kevin    ",30, 20);
}

void PDFManager::generatePDF()
{
    typedef void (*DemoFunction)(PDF &p);

   DemoFunction functions[] =
   {
      demoThree
   };
      ostringstream out;
      out << "Ajedrez_DV-I-R-V.pdf";
      string fileName = out.str();
      PDF pdf;
      functions[0](pdf);
      string errMsg;
      if(!pdf.writeToFile(fileName, errMsg))
      {
         cout << errMsg << endl;
      }
      else
      {
         cout << "(Reporte PDF Generado  de forma Exitosa, presione 2 veces Enter)" << endl;
         getchar();
         getchar();
      }
}

