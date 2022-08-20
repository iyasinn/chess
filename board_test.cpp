#include "unit_test_framework.h"
#include "Board.h"

using namespace std;

TEST(make_board){

    Board<int, 8> b;

    for (int r = 1; r <= 8; r++){
        for (int c = 1; c <= 8; c++){
            int x = (r + c) % 8 + 1;
            b.placePiece(new int(x), r, c);
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


TEST(play){

    Board<int, 8> b;

    for (int r = 1; r <= 8; r++){
        for (int c = 1; c <= 8; c++){
            b.placePiece(new int(((r + c) % 8) + 1), r, c);
        }
    }

    cout << b << endl;

    int option;

    cout << "0: end \n1: removePiece \n2: movePiece\n";

    while (cin >> option){


        if (option == 0){
            break;
        }
        else if (option == 1){
            int start;
            int end;
            cout << "Enter coordinates\n";
            cin >> start >> end;
            b.removePiece(start, end);
        }
        else if(option == 2){
            int row, col, endRow, endCol;
            cout << "Enter start and end coordinates\n";
            cin >> row >> col >> endRow >> endCol;
            b.movePiece(row, col, endRow, endCol);
        }

        cout << endl << b << endl;
        
        cout << "0: end \n1: removePiece \n2: movePiece\n";
    } 




}



TEST(find){

    Board<int, 8> b;

    for (int r = 1; r <= 8; r++){
        for (int c = 1; c <= 8; c++){
            int x = (r + c) % 8 + 1;
            b.placePiece(new int(x), r, c);
        }
    }
    
    cout << "cool test" << endl;
    cout << b(1, 5).value() << endl;






}









TEST_MAIN()