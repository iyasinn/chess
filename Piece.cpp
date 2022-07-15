#include "Piece.h"
#include <cassert>
#include <utility>
using namespace std;


//---------------------- Pawn 

Piece::Piece(string nameIn, string colorIn) : name(nameIn), color(colorIn){}

string Piece::getName() const{
    return name;
}

string Piece::getColor() const {
    return color;
}

//--------------------- King 

pair<bool, string> King::validMove(int dx, int dy) const{
    if ((abs(dx) == 2 || abs(dx) == 3) && dy == 0){
        return make_pair(true, "castle");
    }
    else if ((abs(dx) == 1 && abs(dy) == 1)
            || (abs(dx) == 0 && abs(dy) == 1)
            || (abs(dx) == 1 && abs(dy) == 0)){
        return make_pair(true, "move");
    }

    return make_pair(false, "none");
}

pair<bool, string> Queen::validMove(int dx, int dy) const{
    if (abs(dx) == abs(dy) || (abs(dx) == 0 && abs(dy) != 0) || (abs(dy) == 0 && abs(dx) != 0)){
        return make_pair(true, "move");
    }
    return make_pair(false, "none");
}

pair<bool, string> Pawn::validMove(int dx, int dy) const{
    if (abs(dx) == 0 && ((dy == 1 && getColor() == WHITE)
                     || (dy == -1 && getColor() == BLACK))){
        return make_pair(true, "move");
    }
    else if (abs(dx) == 0 && ((dy == 2 && getColor() == WHITE)
                     || (dy == -2 && getColor() == BLACK))){
        return make_pair(true, "doublemove");
    }
    else if (abs(dx) == 1 && ((getColor() == WHITE && dy == 1) 
                     || (getColor() == BLACK && dy == -1))){
        return make_pair(true, "attack");
    }

    return make_pair(false, "none");
}

pair<bool, string> Knight::validMove(int dx, int dy) const{
    if ((abs(dx) == 2 && abs(dy) == 1) || (abs(dx) == 1 && abs(dy) == 2)){
        return make_pair(true, "move");
    }

    return make_pair(false, "none");
}

pair<bool, string> Bishop::validMove(int dx, int dy) const{
    if (abs(dx) == abs(dy)){
        return make_pair(true, "move");
    }

    return make_pair(false, "none");
}

pair<bool, string> Rook::validMove(int dx, int dy) const{
    if ((dx == 0 && dy != 0) || (dx != 0 && dy == 0)){
        return make_pair(true, "move");
    }
    return make_pair(false, "none");
}