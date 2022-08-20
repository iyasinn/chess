#include "chess.h"
#include "Piece.h"
using namespace std;

int main(){

    system("clear");

    cout << "\n\n\nWelcome to my chess game!\n";

    Chess board;
    cout << board;

    while (true){
        board.movePiece(cout);
        system("clear");
        cout << "\n\n\nGame in progress!\n";
        cout << board;
    }
    cout << board;

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


