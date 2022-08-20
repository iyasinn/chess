#pragma once
#include<iostream> 

const std::string WHITE = "white";
const std::string BLACK = "black";

const std::string KING = "king";
const std::string QUEEN = "queen";
const std::string PAWN = "pawn";
const std::string BISHOP = "bishop";
const std::string KNIGHT = "knight";
const std::string ROOK = "rook";

class Piece {
public:
    Piece(std::string nameIn, std::string colorIn);
    std::string getName() const;
    std::string getColor() const;
    virtual std::pair<bool, std::string> validMove(int dx, int dy) const = 0;

    // Do I need this?
    virtual ~Piece(){}

private:
    std::string name;
    std::string color;
};

class King : public Piece{
public:
    King(std::string colorIn) : Piece(KING, colorIn){}
    std::pair<bool, std::string> validMove(int dx, int dy) const override;
};

class Queen : public Piece{
public:
    Queen(std::string colorIn) : Piece(QUEEN, colorIn){}
    std::pair<bool, std::string> validMove(int dx, int dy) const override;
};

class Pawn : public Piece{
public:
    Pawn(std::string colorIn) : Piece(PAWN, colorIn){}
    std::pair<bool, std::string> validMove(int dx, int dy) const override;
};

class Rook : public Piece{
public:
    Rook(std::string colorIn) : Piece(ROOK, colorIn){}
    std::pair<bool, std::string> validMove(int dx, int dy) const override;
};

class Bishop : public Piece{
public:
    Bishop(std::string colorIn) : Piece(BISHOP, colorIn){}
    std::pair<bool, std::string> validMove(int dx, int dy) const override;
};

class Knight : public Piece{
public:
    Knight(std::string colorIn) : Piece(KNIGHT, colorIn){}
    std::pair<bool, std::string> validMove(int dx, int dy) const override;
};


Piece* pieceFactory(std::string name, std::string color);

inline std::ostream& operator<<(std::ostream& os, Piece* ptr){

    os << "\033[1;31m";

    if (ptr->getColor() == WHITE){
        os << "\033[1;36m";
    }

    if (ptr->getName() == QUEEN){
        os << " ♛ ";
    }
    else if (ptr->getName() == KING){
        os << " ♚ ";
    }
    else if (ptr->getName() == PAWN){
        os << " ♟ ";
    }
    else if (ptr->getName() == BISHOP){
        os << " ♝ ";
    }
    else if (ptr->getName() == KNIGHT){
        os << " ♞ ";
    }
    else if (ptr->getName() == ROOK){
        os << " ♜ ";
    }

    os << "\033[0m";

    return os;
}

// ╔═╤═╤═╤═╤═╤═╤═╤═╗
// ║♜│♞│♝│♛│♚│♝│♞│♜║
// ╟─┼─┼─┼─┼─┼─┼─┼─╢
// ║♟│♟│♟│♟│♟│♟│♟│♟║
// ╟─┼─┼─┼─┼─┼─┼─┼─╢
// ║ │░│ │░│ │░│ │░║
// ╟─┼─┼─┼─┼─┼─┼─┼─╢
// ║░│ │░│ │░│ │░│ ║
// ╟─┼─┼─┼─┼─┼─┼─┼─╢
// ║ │░│ │░│ │░│ │░║
// ╟─┼─┼─┼─┼─┼─┼─┼─╢
// ║░│ │░│ │░│ │░│ ║
// ╟─┼─┼─┼─┼─┼─┼─┼─╢
// ║♙│♙│♙│♙│♙│♙│♙│♙║
// ╟─┼─┼─┼─┼─┼─┼─┼─╢
// ║♖│♘│♗│♕│♔│♗│♘│♖║
// ╚═╧═╧═╧═╧═╧═╧═╧═╝




/*
What do I need in a good chess piece?
To be honest, I definitely need name and color, but what else? 
I'll need to overload the << operator so I can print out a chess piece easily
I also might need a bool for hasMoved

Actually, even better, for has moved, I could probably just have a set for pieces that have moved
And a set for pieces that moved the turn before. That would allow me to account for things like en passant 
I guess I do need to do things as references though 

*/






















