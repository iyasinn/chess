#include <iostream>
#include <cassert>
#include <ostream>

template<int BOARD_SIZE>
bool inBoard(const int row, const int col){
    return (0 <= row && row < BOARD_SIZE && 0 <= col && col < BOARD_SIZE);
}

template<typename T, int BOARD_SIZE>
class Board{

public:

// EFFECTS: Default Constructor for a Board object 
Board(){
    for (int r = 0; r < BOARD_SIZE; r++){
        for (int c = 0; c < BOARD_SIZE; c++){
            board[r][c] = nullptr;
        }
    }
}

// REQUIRES: Pieces is a pointer to a dynamically allocated object, row and col are valid coordinates
//           Note: the coordinates must be actual coordinates, don't worry about underlying array 
// MODIFIES: board
// EFFECTS: Places the piece at that specfic spot. If piece exists in spot, replaces it with the new piece.  
void placePiece(T* piece, int row, int col){
    // Reindexing the row/col and seeing if it's in the board
    assert(piece && inBoard<BOARD_SIZE>(row -= 1, col -= 1));

    if (board[row][col]){
        removePiece(row, col);
    }
    board[row][col] = piece;
}

// REQUIRES: row and col are valid coordinates
// MODIFIES: board
// EFFECTS: Removes the piece at row, col. Deletes it from dynamic memory.
//          If no piece at spot, then since this deletes thing, it actually delets from all spots 
void removePiece(int row, int col){
    assert(inBoard<BOARD_SIZE>(row -= 1, col -= 1));
    if (board[row][col]){
        delete board[row][col];
        board[row][col] = nullptr;
    }    
}

// REQUIRES: Valid start point and end point, and that your start point has a valid piece. 
// MODIFIES: board
// EFFECTS: Moves the piece at (row, col) to (endRow, endCol). If there is a piece at (endRow, endCol), 
//          then the piece at (endRow, endCol) is removed. 
bool movePiece(int row, int col, int endRow, int endCol){
    // Basic checks
    // Don't need to reassign row and col by subtracting one because removePiece and 
    // placePiece to thats
    assert(inBoard<BOARD_SIZE>(row -= 1, col -= 1) 
            && inBoard<BOARD_SIZE>(endRow -=1, endCol -= 1)
            && board[row][col]);

    if ((row == endRow && col == endCol) || (!board[row][col])) return false;
    
    board[endRow][endCol] = board[row][col];
    board[row][col] = nullptr;
    return true;
}

// REQUIRES: row and col are valid coordinates
// MODIFIES: N/A
// EFFECTS: Returns an optional value for the type if it exists at the coordinages. If nothing exists
//          then an empty value is returned. 
T* operator ()(int row, int col) const{
    assert(inBoard<BOARD_SIZE>(row -= 1, col -= 1));
    if (board[row][col]) {
        return board[row][col];
    }
    return nullptr;
}

// Why do I need to return T rather than T*?

// EFFECTS: Destructor for the object
~Board(){
    for (int row = 1; row <= BOARD_SIZE; row++){
        for (int col = 1; col <= BOARD_SIZE; col++){
            removePiece(row, col);
        }
    }
}

private:
    T* board[BOARD_SIZE][BOARD_SIZE];
    int numPieces = 0;
};

// REQUIRES: os is a valid ostream, board is a valid object, and type T has the extraction operator overloaded
// MODIFIES: os
// EFFECTS: Prints the board to the output screen. in the format 
//          This function uses the abstraction for the board, so don't worry about 
//          the unerlying array. Just enter coordintes as if playing a normal game. 
// (7, 1), (7, 2)
// (6, 1) 
template<typename T, int BOARD_SIZE>
std::ostream& operator<<(std::ostream& os, const Board<T, BOARD_SIZE>& board) {

    for (int row = BOARD_SIZE; row >= 1; row--){
        os << std::endl << " " << row << "| ";
        for (int col = 1; col <= BOARD_SIZE; col++){
            
            if (board(row, col)){
                os << board(row, col) << " ";
            }
            else {
                os << "  ";
            }

        }

        if (row != 1) os << "\n  |";
    }

    os << "\n    ";

    for (int col = 1; col <= BOARD_SIZE; col++){
        os << "__";
    }
    
    os << std::endl;
    os << "    ";

    for (int col = 1; col <= BOARD_SIZE; col++){
        os << " " << col << "  ";
    }

    return os;
}
