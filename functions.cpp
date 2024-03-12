#include "header.h"

const string col_num = "      1     2     3      4     5     6      7     8     9    ";
const string PARTITION_1 = "  ||=====|=====|=====||=====|=====|=====||=====|=====|=====||";
const string PARTITION_2 = "  ||-----|-----|-----||-----|-----|-----||-----|-----|-----||";
const string PARTITION_3 = "  ||     |     |     ||     |     |     ||     |     |     ||";

char board_a[9][9] = {
                        {'1', '2', '6', '4', '3', '7', '9', '5', '8'},
                        {'8', '9', '5', '6', '2', '1', '4', '7', '3'},
                        {'3', '7', '4', '9', '8', '5', '1', '2', '6'},
                        {'4', '5', '7', '1', '9', '3', '8', '6', '2'},
                        {'9', '8', '3', '2', '4', '6', '5', '1', '7'},
                        {'6', '1', '2', '5', '7', '8', '3', '9', '4'},
                        {'2', '6', '9', '3', '1', '4', '7', '8', '5'},
                        {'5', '4', '8', '7', '6', '9', '2', '3', '1'},
                        {'7', '3', '1', '8', '2', '5', '6', '4', '9'},
                     };

void display_board(char board[][9])
{
    int let = 'A';
    cout << col_num << endl;
    cout << PARTITION_1 << endl;
    for(int i = 0; i < 9; i += 1)
    {
        cout << PARTITION_3 << endl;
        cout << (char) let << " ";
        for(int j = 0; j < 9; j += 3)
        {
            cout << "||  " << board[i][j] << "  |";
            cout << "  " << board[i][j + 1] << "  |";
            cout << "  " << board[i][j + 2] << "  ";
        }
        cout << "||" << endl;
        switch(i) 
        {
            case 2:
                cout << PARTITION_1 << endl;
                break;
            case 5:
                cout << PARTITION_1 << endl;
                break;
            case 8:
                cout << PARTITION_1 << endl;
                break;
            default:
                cout << PARTITION_2 << endl;
        }
        let++;
    }   
    cout << endl;
}

void initialize_display_locations(bool board[][9])
{
    for(int i = 0; i < 9; i++)
    {
        int num1 = rand() % 9, 
            num2 = rand() % 9, 
            num3 = rand() % 9;

        while(num1 == num2 && num1 == num3 && num2 == num3)
        {
            num2 = rand() % 9;
            num3 = rand() % 9;
        }
        for(int j = 0; j < 9; j++)
        {
            if(j == num1 || j == num2 || j == num3)
                board[i][j] = true;
            else
                board[i][j] = false;
        }
    }
}

void initialize_board(char player_board[][9], bool locations[][9])
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(locations[i][j])
                player_board[i][j] = board_a[i][j];
            else
                player_board[i][j] = ' ';
        }
    }
}

void player_turn(char player_board[][9], bool correct_location[][9], int& row, int& col, char& ans)
{
    char let_location;
    bool valid = false;
    cout << "Please input a location (ex. A5): \n";
    cin >> let_location >> col;
    col--;
    tolower(let_location);
    row = let_location - 65;
    while(row < 0 || row > 8)
    {
        cout << "Please input a valid row from A-I in uppercase: \n";
        cin >> let_location;
        row = let_location - 65;
    }
    while(col < 0 || col > 8)
    {
        cout << "Please input a valid column from 1-: \n";
        cin >> col;
        col--;
    }

    cout << "What number (1-9) would you like to input in the box? \n";
    int val;
    cin >> val;
    while(val < 1 || val > 9)
    {
        cout << "Please select a valid number from 1-9: \n";
        cin >> val;
    }
    ans = (char) (val + 48);
    if(correct_location[row][col] == true)
    {
        cout << "The number cannot be placed in this location. \n";
    }
    else
        player_board[row][col] = ans;
}

bool check_win(char player_board[][9], bool correct_location[][9])
{
    char check;
    cout << "Would you like to check for win? (y/n): \n";
    cin >> check;
    while(check != 'y' && check != 'n')
    {
        cout << "Please input either 'y' or 'n': \n";
        cin >> check;
    }
    if(check == 'y')
    {
        for(int i = 0; i < 9; i += 1)
        {
            for(int j = 0; j < 9; j += 1)
            {
                if(!correct_location[i][j])
                {
                    if(player_board[i][j] != board_a[i][j])
                        return false;
                }
                
            }
        } 
    }
    else if(check == 'n')
        return false;
    return true;
}