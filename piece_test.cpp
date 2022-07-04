
#include "unit_test_framework.h"
#include "Piece.h"
#include <utility>

using namespace std;

TEST(piece){

    pair<bool, string> output;

    Piece* ptr = new King("black");
    ASSERT_EQUAL(ptr->getColor(), BLACK);
    ASSERT_EQUAL(ptr->getName(), KING);

    // Testing moving in each direction 
    for (int dx = -1; dx <= 1; dx++){
        for (int dy = -1; dy <= 1; dy++){
            output = ptr->validMove(dx, dy);
            ASSERT_EQUAL(output, make_pair(true, "move"));
        }
    }

    pair<bool, string> test;

    test = ptr->validMove(2, 0);
    ASSERT_EQUAL(test.first, true);
    ASSERT_EQUAL(test.second, "castle");

    ASSERT_EQUAL(ptr->validMove(3, 0), make_pair(true, "castle"));
    ASSERT_EQUAL(ptr->validMove(5, 4), make_pair(false, "none"));




}





TEST_MAIN()