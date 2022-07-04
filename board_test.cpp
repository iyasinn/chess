#include "unit_test_framework.h"
#include "Board.h"

using namespace std;

TEST(make_board){

    Board<int, 8> b;

    for (int r = 0; r < 8; r++){
        for (int c = 0; c < 8; c++){
            b.placePiece(new int(r + c), r, c);
        }
    }

    cout << b << endl << endl << endl;

    b.removePiece(3, 4);
    b.removePiece(0, 0);
    b.removePiece(7, 7);

    cout << b;

    b.movePiece(0, 1, 0, 0);
    b.movePiece(1, 2, 1, 3);

    cout << endl << endl << endl << b;
}
















TEST_MAIN()