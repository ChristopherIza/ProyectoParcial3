/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * 
 * @file PDFManager.hpp
 * @author De Veintemilla Luca- Iza Christopher- Rea Denise - Vargas Kevin
 * @brief Manage PDF report 
 * @version 0.1
 * @date 2022-08-16
 * Date last modification: 2022-08-16
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef PDF_MANAGER_HPP
#define PDF_MANAGER_HPP
#include <string>
#include <vector>
//#include "pdf.hpp"


class PDFManager
{
private:

public:
    /**
     * @brief generate report in PDF 
     * 
     */
    void generatePDF();

    /**
     * @brief Obtain data of game
     * 
     * @return std::vector <std::string> 
     */
    std::vector <std::string> Obtener_datos(std::string);

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool verif_nombreArch(std::string);

    /**
     * @brief 
     * 
     * @return std::string 
     */
    std::string IngresarNombre();
};
#endif