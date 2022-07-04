#include <iostream>
#include <cassert>
#include <ostream>
#include <optional>

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

// REQUIRES: Pieces is a pointer to a dynamically allocated object, row and col are valid coordinates.
// MODIFIES: board
// EFFECTS: Places the piece at that specfic spot. 
void placePiece(T* piece, const int& row, const int& col){
    assert(piece && abs(row) < BOARD_SIZE && abs(col) < BOARD_SIZE && !board[row][col]);
    board[row][col] = piece;
}

// REQUIRES: row and col are valid coordinates
// MODIFIES: board
// EFFECTS: Removes the piece at row, col. Deletes it from dynamic memory.  
void removePiece(const int& row, const int& col){
    assert(abs(row) < BOARD_SIZE && abs(col) < BOARD_SIZE);
    if (board[row][col]){
        delete board[row][col];
        board[row][col] = nullptr;
    }    
}

// REQUIRES: Valid start point and end point, and that your start point has a valid piece. 
// MODIFIES: board
// EFFECTS: Moves the piece at (row, col) to (endRow, endCol). If there is a piece at (endRow, endCol), 
//          then the piece at (endRow, endCol) is removed. 
void movePiece(const int& row, const int& col, const int& endRow, const int& endCol){

    // Basic checks
    assert(abs(row) < BOARD_SIZE && abs(col) < BOARD_SIZE && abs(endRow) < BOARD_SIZE && abs(endCol) < BOARD_SIZE
                        && board[row][col]);
    removePiece(endRow, endCol);
    board[endRow][endCol] = board[row][col];
    board[row][col] = nullptr;
}

// REQUIRES: row and col are valid coordinates
// MODIFIES: N/A
// EFFECTS: Returns an optional value for the type if it exists at the coordinages. If nothing exists
//          then an empty value is returned. 
std::optional<T> operator ()(const int& row, const int& col) const{
    assert(abs(row) < BOARD_SIZE && abs(col) < BOARD_SIZE);
    if (board[row][col]) return *(board[row][col]);
    return {};
}

// EFFECTS: Destructor for the object
~Board(){
    for (int r = 0; r < BOARD_SIZE; r++){
        for (int c = 0; c < BOARD_SIZE; c++){
            removePiece(r, c);
        }
    }
}

private:
    T* board[BOARD_SIZE][BOARD_SIZE];
    int numPieces = 0; 
};

// REQUIRES: os is a valid ostream, board is a valid object, and type T has the extraction operator overloaded
// MODIFIES: os
// EFFECTS: Prints the board to the output screen. 
template<typename T, int BOARD_SIZE>
std::ostream& operator<<(std::ostream& os, const Board<T, BOARD_SIZE>& board) {

    for (int row = BOARD_SIZE - 1; row >= 0; row--){
        os << " " << row + 1 << " ";
        for (int col = 0; col < BOARD_SIZE; col++){
            
            if (board(row, col).has_value()){
                os << board(row, col).value() << " ";
            }
            else {
                os << "  ";
            }

        }
        os << std::endl << std::endl;
    }

    os << "   ";

    for (int col = 1; col <= BOARD_SIZE; col++){
        os << col << " ";
    }

    return os;
}
