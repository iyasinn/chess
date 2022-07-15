
#include "unit_test_framework.h"
#include "Piece.h"
#include <utility>

using namespace std;

TEST(king){

    pair<bool, string> output;

    Piece* ptr = new King("black");
    ASSERT_EQUAL(ptr->getColor(), BLACK);
    ASSERT_EQUAL(ptr->getName(), KING);

    // Testing moving in each direction 
    for (int dx = -1; dx <= 1; dx++){
        for (int dy = -1; dy <= 1; dy++){
            output = ptr->validMove(dx, dy);
            
            if (dx == 0 && dy == 0){
                ASSERT_EQUAL(output.first, false);
                ASSERT_EQUAL(output.second, "none")   
                continue;          
            }
            ASSERT_EQUAL(output.first, true);
            ASSERT_EQUAL(output.second, "move")
        }
    }

    // Technically -2, -3 will work as well. 

    for (int x : {2, 3, -2, -3}){
        output = ptr->validMove(x, 0);
        ASSERT_EQUAL(output.first, true);
        ASSERT_EQUAL(output.second, "castle");      

    }

    output = ptr->validMove(5, 4);
    ASSERT_EQUAL(output.first, false);
    ASSERT_EQUAL(output.second, "none");

    // Do I need this?
    delete ptr;
}

TEST(queen){

    pair<bool, string> output;

    Piece* ptr = new Queen("white");
    ASSERT_EQUAL(ptr->getColor(), WHITE);
    ASSERT_EQUAL(ptr->getName(), QUEEN);  


    for (int dx = -3; dx <= 3; dx++){
        for (int dy = -3; dy <= 3; dy++){

            output = ptr->validMove(dx, dy);

            if (abs(dx) == abs(dy)){
                ASSERT_EQUAL(output.first, true);
                ASSERT_EQUAL(output.second, "move")
            }
            else if ((dx == 0 and dy != 0) || (dx != 0 && dy == 0)){
                ASSERT_EQUAL(output.first, true);
                ASSERT_EQUAL(output.second, "move")
            }
            else{
                ASSERT_EQUAL(output.first, false);
                ASSERT_EQUAL(output.second, "none")
            }
        }
    }

    delete ptr;
}

TEST(bishop){

    pair<bool, string> output;

    Piece* ptr = new Bishop("black");
    ASSERT_EQUAL(ptr->getColor(), BLACK);
    ASSERT_EQUAL(ptr->getName(), BISHOP);  


    for (int dx = -3; dx <= 3; dx++){
        for (int dy = -3; dy <= 3; dy++){

            output = ptr->validMove(dx, dy);

            if (abs(dx) == abs(dy)){
                ASSERT_EQUAL(output.first, true);
                ASSERT_EQUAL(output.second, "move")
            }
            else{
                ASSERT_EQUAL(output.first, false);
                ASSERT_EQUAL(output.second, "none")
            }
        }
    }

    delete ptr;
}

TEST(rook){

    pair<bool, string> output;

    Piece* ptr = new Rook("white");
    ASSERT_EQUAL(ptr->getColor(), WHITE);
    ASSERT_EQUAL(ptr->getName(), ROOK);  


    for (int dx = -3; dx <= 3; dx++){
        for (int dy = -3; dy <= 3; dy++){

            output = ptr->validMove(dx, dy);

            if ((dx == 0 and dy != 0) || (dx != 0 && dy == 0)){
                ASSERT_EQUAL(output.first, true);
                ASSERT_EQUAL(output.second, "move")
            }
            else{
                ASSERT_EQUAL(output.first, false);
                ASSERT_EQUAL(output.second, "none")
            }
        }
    }

    delete ptr;
}

TEST(pawn){

    pair<bool, string> output;

    Piece* ptr = new Pawn("white");
    ASSERT_EQUAL(ptr->getColor(), WHITE);
    ASSERT_EQUAL(ptr->getName(), PAWN);  


    // This checks for white and black pawns
    for (int dx = -3; dx <= 3; dx++){
        for (int dy = -3; dy <= 3; dy++){

            output = ptr->validMove(dx, dy);

            if ((abs(dx) == 0 && dy == 1)){
                ASSERT_EQUAL(output.first, true);
                ASSERT_EQUAL(output.second, "move")
            }
            else if (abs(dx) == 0 && dy == 2){
                ASSERT_EQUAL(output.first, true);
                ASSERT_EQUAL(output.second, "doublemove")    
                 }
            else if (abs(dx) == 1 && dy == 1){
                ASSERT_EQUAL(output.first, true);
                ASSERT_EQUAL(output.second, "attack")
            }
            else{
                ASSERT_EQUAL(output.first, false);
                ASSERT_EQUAL(output.second, "none")
            }
        }
    }

    delete ptr;
}



TEST_MAIN()