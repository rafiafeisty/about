#include<iostream>
using namespace std;


void printboard(char board[][3])
{
    for(int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            cout << board[i][j];
            if(j<2)
            {
                cout << " | ";
            }
        }
        cout << endl;
        if(i<2)
        {
            cout << "___________" << endl;
        }
    }
}
bool winner(char board[][3], char player)
{
    for(int i=0; i<3; i++)
    {
        if((board[i][0]==player&&board[i][1]==player&&board[i][2]==player)||
           (board[0][i]==player&&board[1][i]==player&&board[2][i]==player))
           {
               return true;
           }
    }
    if((board[0][0]==player&&board[1][1]==player&&board[2][2]==player)||
       (board[0][2]==player&&board[1][1]==player&&board[2][0]==player))
    {
        return true;
    }
    return false;
}
bool isboardfull(char board[][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[i][j]==' ')
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    char board[3][3];
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            board[i][j]=' ';
        }
    }
    bool playerturn=true;
    while(true)
    {
         printboard(board);
         char player= (playerturn) ? 'X' : 'O';
        int row, col;
        cout << "player" << player << "'s turn, enter row(0, 1, 2)";
        cin >> row;
        cout << "player" << player << "'s turn, enter column(0, 1, 2)";
        cin >> col;
        if(row>=0 && row<3 && col>=0 && col<3 && board[row][col]== ' ')
        {
            board[row][col]=player;
            if(winner(board, player))
            {
                printboard(board);
                cout << "player" << player << "is the winner" << endl;
                break;
            }
            else if(isboardfull(board))
            {
                printboard(board);
                cout << "it is a tie" << endl;
                break;
            }
            else
            {
                playerturn=!playerturn;
            }
        }
        else
        {
            cout << "invalid move. Try again" << endl;
        }
    }
    return 0;
}

