#include "header.h"

int main() 
{
    int hint_left = 3;
    int row, col;
    char ans;
    bool win;

    cout << "\n\nSUDOKU: Fill all the squares with the correct numbers to win.\n";
    cout << "\n\n";

    bool locations[9][9];
    initialize_display_locations(locations);
    
    char player_board[9][9];
    initialize_board(player_board, locations);
    display_board(player_board);

    do
    {
        player_turn(player_board, locations, row, col, ans);
        display_board(player_board);
        win = check_win(player_board, locations);
        if(!win)
            cout << "\nGame Continues...\n\n";
    } 
    while(win == false);

    cout << "\n\nCongrats!!! You completed this board!!!";
    return 0;
}