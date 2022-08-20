#include <iostream>



using namespace std;

int main() {

    cout << "hello";

}
/*


Need to make a plan for this chess game. 
To be honest, I would really like to utilize subtype polymorphism, since it's a very useful technique. 
I wonder though, should my bored be created in a specific way? Tbh I just wanted it to be a 2d array. 
But ther's probaby a lot more I could do 
LIke have a board struct and stuf, but it seems it would be messy
However, if I did do that
Then I could make it so that in this board class I could ignore the 2d array part, and tha I could access
Any part of the board that I wanted, which would proably be incredibly useful (oeprator overload)

SO ig it wouldn't be that bad, and it would make the code a lot cleaner
I think I just need to plan this out very smartly 


We also have the pieces. Again, we can use subtype polymorphism. But I think the most important
Thing is to think about how exactly we can enforce rules on the chess board. In fact it would s
seem most of the rules would have to be enforced by the board itself. So in that point, why would 
we even need subtype polymorphism. 
we could just use it to be helpful in checking if a certain move works

Like for our cards, we did things like checking ifi it was a right bower or stuff. 
I'm just thinking htat if e did do the whole derive dclass thing, that's only because we need to deal with 
Stuff like deltta move.. 
THe pieces would also include information on color, name, maybe number of points. etc. 
I think anohter important thing would be to see if they have or have not moved yetj. That would be very important for arule like en passant 



*/