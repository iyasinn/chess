#include "unit_test_framework.h"
#include "Board.h"

using namespace std;

TEST(make_board){

    Board<int, 8> b;

    for (int r = 1; r <= 8; r++){
        for (int c = 1; c <= 8; c++){
            b.placePiece(new int(((r + c) % 8) + 1), r, c);
        }
    }
    cout << "Testing if the board is actually printing" << endl;
    cout << b << endl << endl << endl;

    b.removePiece(3, 4);
    b.removePiece(1, 1);
    b.removePiece(7, 7);

    cout << "Removed (3, 4), (1, 1), and (7, 7)" << endl;
    cout << b << endl;

    cout << "Moving (3, 5) to (1, 1) and (1, 3) to (1, 5)" << endl;
    b.movePiece(3, 5, 1, 1);
    b.movePiece(1, 3, 1, 5);

    cout << b << endl << endl << endl;
}
















TEST_MAIN()