/**
 * @file play.hpp
 * @author De Veintemilla Luca- Iza Christopher- Rea Denise - Vargas Kevin
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "includes.h"

#include <string.h> // memcpy on linux

using namespace std;

#include "user_interface.h"
#include "chess.h"

class play{
    public:

    /**
     * @brief 
     * 
     * @param present 
     * @param future 
     * @param S_enPassant 
     * @param S_castling 
     * @param S_promotion 
     * @return true 
     * @return false 
     */
    bool isMoveValid(Chess::Position present, Chess::Position future, Chess::EnPassant* S_enPassant, Chess::Castling* S_castling, Chess::Promotion* S_promotion);

    /**
     * @brief 
     * 
     * @param present 
     * @param future 
     * @param S_enPassant 
     * @param S_castling 
     * @param S_promotion 
     */
    void makeTheMove(Chess::Position present, Chess::Position future, Chess::EnPassant* S_enPassant, Chess::Castling* S_castling, Chess::Promotion* S_promotion);

    /**
     * @brief 
     * 
     */
    void newGame(void);

    /**
     * @brief 
     * 
     */
    void undoMove(void);

    /**
     * @brief 
     * 
     */
    void movePiece(void);

    /**
     * @brief 
     * 
     */
    void saveGame(void);

    /**
     * @brief 
     * 
     */
    void loadGame(void);

    /**
     * @brief 
     * 
     */
    void start();
    private:
    Game* current_game = NULL;

};
