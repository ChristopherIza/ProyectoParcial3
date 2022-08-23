/**
 * @file chess.h
 * @author De Veintemilla Luca- Iza Christopher- Rea Denise - Vargas Kevin
 * @brief // Descripción de la clase 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "includes.h"

class Chess
{
public:

   /**
    * @brief Get the Piece Color object
    * 
    * @param chPiece 
    * @return int 
    */
   static int getPieceColor( char chPiece );

   /**
    * @brief determines if the piece is white
    * 
    * @param chPiece 
    * @return true 
    * @return false 
    */
   static bool isWhitePiece( char chPiece );

   /**
    * @brief determines if the piece is black
    * 
    * @param chPiece 
    * @return true 
    * @return false 
    */
   static bool isBlackPiece( char chPiece );

   /**
    * @brief Returns the description of the piece
    * (pawn, rook, king, bishop, queen, knight, etc.)
    * 
    * @param chPiece 
    * @return std::string 
    */
   static std::string describePiece( char chPiece );

   enum PieceColor
   {
      WHITE_PIECE = 0,
      BLACK_PIECE = 1
   };

   enum Player
   {
      WHITE_PLAYER = 0,
      BLACK_PLAYER = 1
   };

   enum Side
   {
      QUEEN_SIDE = 2,
      KING_SIDE  = 3
   };

   enum Direction
   {
      HORIZONTAL = 0,
      VERTICAL,
      DIAGONAL,
      L_SHAPE
   };

   struct Position
   {
      int iRow;
      int iColumn;
   };

   struct EnPassant
   {
      bool bApplied;
      Position PawnCaptured;
   };

   struct Castling
   {
      bool bApplied;
      Position rook_before;
      Position rook_after;
   };

   struct Promotion
   {
      bool bApplied;
      //Position  pos;
      char chBefore;
      char chAfter;
   };

   struct IntendedMove
   {
      char chPiece;
      Position from;
      Position to;
   };

   struct Attacker
   {
      Position  pos;
      Direction dir;
   };

   struct UnderAttack
   {
      bool bUnderAttack;
      int iNumAttackers;
      Attacker attacker[9]; //maximum theorical number of attackers
   };

   const char initial_board[8][8] =
   {
      // This represents the pieces on the board.
      // Keep in mind that pieces[0][0] represents A1
      // pieces[1][1] represents B2 and so on.
      // Letters in CAPITAL are white
      { 'R',  'N',  'B',  'Q',  'K',  'B',  'N',  'R' },
      { 'P',  'P',  'P',  'P',  'P',  'P',  'P',  'P' },
      { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
      { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
      { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
      { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
      { 'p',  'p',  'p',  'p',  'p',  'p',  'p',  'p' },
      { 'r',  'n',  'b',  'q',  'k',  'b',  'n',  'r' },
   };
};

class Game : Chess
{
public:
   /**
    * @brief Construct a new Game object
    * 
    */
   Game();
   ~Game();

   /**
    * @brief move the piece
    * 
    * @param present 
    * @param future 
    * @param S_enPassant 
    * @param S_castling 
    * @param S_promotion 
    */
   void movePiece( Position present, Position future, Chess::EnPassant* S_enPassant, Chess::Castling* S_castling, Chess::Promotion* S_promotion );

   /**
    * @brief undoes the movement previously made
    * 
    */
   void undoLastMove();

   /**
    * @brief Determine whether a transaction can be undone
    * 
    * @return true 
    * @return false 
    */
   bool undoIsPossible();

   /**
    * @brief 
    * 
    * @param iSide 
    * @param iColor 
    * @return true 
    * @return false 
    */
   bool castlingAllowed( Side iSide, int iColor );

   /**
    * @brief Get the Piece At Position object
    * 
    * @param iRow 
    * @param iColumn 
    * @return char 
    */
   char getPieceAtPosition( int iRow, int iColumn );

   /**
    * @brief Get the Piece At Position object
    * 
    * @param pos 
    * @return char 
    */
   char getPieceAtPosition( Position pos );

   /**
    * @brief Get the Piece considerMove object
    * 
    * @param iRow 
    * @param iColumn 
    * @param intended_move 
    * @return char 
    */
   char getPiece_considerMove( int iRow, int iColumn, IntendedMove* intended_move = nullptr );

   /**
    * @brief Determines if the piece is in danger or under attack
    * 
    * @param iRow 
    * @param iColumn 
    * @param iColor 
    * @param pintended_move 
    * @return UnderAttack 
    */
   UnderAttack isUnderAttack( int iRow, int iColumn, int iColor, IntendedMove* pintended_move = nullptr );

   /**
    * @brief Determines if the piece is Reachable
    * 
    * @param iRow 
    * @param iColumn 
    * @param iColor 
    * @return true 
    * @return false 
    */
   bool isReachable( int iRow, int iColumn, int iColor );

   /**
    * @brief Evaluates if the space is occupied
    * 
    * @param iRow 
    * @param iColumn 
    * @return true 
    * @return false 
    */
   bool isSquareOccupied( int iRow, int iColumn );

   /**
    * @brief  Evaluates if the Peah is Free
    * 
    * @param startingPos 
    * @param finishingPos 
    * @param iDirection 
    * @return true 
    * @return false 
    */
   bool isPathFree( Position startingPos, Position finishingPos, int iDirection ); 

   /**
    * @brief Evaluates if the piece can be locked
    *  
    * @param startingPos 
    * @param finishinPos 
    * @param iDirection 
    * @return true 
    * @return false 
    */
   bool canBeBlocked( Position startingPos, Position finishinPos, int iDirection );

   /**
    * @brief Determines if the piece is in Jake
    * 
    * @return true 
    * @return false 
    */
   bool isCheckMate();

   /**
    * @brief Determines if the King is in Check
    * 
    * @param iColor 
    * @param intended_move 
    * @return true 
    * @return false 
    */
   bool isKingInCheck( int iColor, IntendedMove* intended_move = nullptr );

   /**
    * @brief 
    * 
    * @param intended_move 
    * @return true 
    * @return false 
    */
   bool playerKingInCheck( IntendedMove* intended_move = nullptr );

   /**
    * @brief Determines if the piece would be in check
    * 
    * @param chPiece 
    * @param present 
    * @param future 
    * @param S_enPassant 
    * @return true 
    * @return false 
    */
   bool wouldKingBeInCheck( char chPiece, Position present, Position future, EnPassant* S_enPassant );

   /**
    * @brief Returns the position of the King
    * 
    * @param iColor 
    * @return Position 
    */
   Position findKing( int iColor );

   /**
    * @brief Change turns
    * 
    */
   void changeTurns( void );

   /**
    * @brief Determines if the game finished
    * 
    * @return true 
    * @return false 
    */
   bool isFinished( void );

   /**
    * @brief Get the Current Turn object
    * 
    * @return int 
    */
   int getCurrentTurn( void );

   /**
    * @brief Get the Opponent Color object
    * 
    * @return int 
    */
   int getOpponentColor( void );

   /**
    * @brief Parse Move the piece 
    * 
    * @param move 
    * @param pFrom 
    * @param pTo 
    * @param chPromoted 
    */
   void parseMove( string move, Position* pFrom, Position* pTo, char* chPromoted = nullptr );

   /**
    * @brief Log the moves
    * 
    * @param to_record 
    */
   void logMove( std::string &to_record );

   /**
    * @brief Get the Last Move object
    * 
    * @return string 
    */
   string getLastMove( void );

   /**
    * @brief erase the last move
    * 
    */
   void deleteLastMove( void );

   // Save all the moves
   struct Round
   {
      string white_move;
      string black_move;
   };

   //std::deque<std::string> moves;
   std::deque<Round> rounds;

   // Save the captured pieces
   std::vector<char> white_captured;
   std::vector<char> black_captured;

private:

   // Represent the pieces in the board
   char board[8][8];
 
   // Undo is possible?
   struct Undo
   {
      bool bCanUndo;
      bool bCapturedLastMove;

      bool bCastlingKingSideAllowed;
      bool bCastlingQueenSideAllowed;

      EnPassant en_passant;
      Castling  castling;
      Promotion promotion;
   } m_undo;

   // Castling requirements
   bool m_bCastlingKingSideAllowed[2];
   bool m_bCastlingQueenSideAllowed[2];

   // Holds the current turn
   int  m_CurrentTurn;

   // Has the game finished already?
   bool m_bGameFinished;
};
