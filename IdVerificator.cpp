/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * 
 * @file IdVerificator.cpp
 * @author De Veintemilla Luca- Iza Christopher- Rea Denise - Vargas Kevin
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "IdVerificator.hpp"
#include <iostream>

bool IdVerificator::isValid(const std::string &idCard) {
    int oddSum{};

    for (int i{}; i < 9; i += 2) {
        int value = (idCard[i] - '0') * 2;

        if (value > 9)
            value -= 9;

        oddSum += value;
    }

    int evenSum{};
    
    for (int i{1}; i < 8; i += 2) {
        evenSum += (idCard[i] - '0');
    }

    int verificationDigit = ((oddSum + evenSum) % 10 != 0) ? 10 - (oddSum + evenSum) % 10 : 0;

    return verificationDigit == (idCard[9] - '0');
}