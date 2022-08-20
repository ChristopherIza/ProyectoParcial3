#include "includes.h"

#include <string.h> // memcpy on linux

using namespace std;

#include "user_interface.h"
#include "chess.h"






class play{
    public:

    bool isMoveValid(Chess::Position present, Chess::Position future, Chess::EnPassant* S_enPassant, Chess::Castling* S_castling, Chess::Promotion* S_promotion);
    void makeTheMove(Chess::Position present, Chess::Position future, Chess::EnPassant* S_enPassant, Chess::Castling* S_castling, Chess::Promotion* S_promotion);
    void newGame(void);
    void undoMove(void);
    void movePiece(void);
    void saveGame(void);
    void loadGame(void);
    void start();
    private:

    Game* current_game = NULL;

};
