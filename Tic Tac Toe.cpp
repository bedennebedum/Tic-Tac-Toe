#include <iostream>
using namespace std;

char board[3][3] = 
{
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'} 
};
int row, column, choice;
char turn = 'X';
bool draw = false;

void displayboard()
{
  cout << "\n\n";
  cout << "              |" << "           |\n";
  cout << "         " << board[0][0] << "    |" << "     " << board[0][1] << "     |" << "     " << board[0][2] << "\n";
  cout << "--------------|-----------|--------------\n";
  cout << "         " << board[1][0] << "    |" << "     " << board[1][1] << "     |" << "     " << board[1][2] << "\n";
  cout << "--------------|-----------|--------------\n";
  cout << "         " << board[2][0] << "    |" << "     " << board[2][1] << "     |" << "     " << board[2][2] << "\n";
  cout << "              |" << "           |";
  cout << "\n\n";
}

void playerturn()
{
    if (turn == 'X')
    cout << "Player X's Turn: \n";
    else if (turn == 'O')
    cout << "Player O's Turn: \n";

    cin >> choice;

    switch(choice)
    {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default: cout << "\nPlease enter a number that is shown on the board.\n\n";
    }

    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
    {
      board[row][column] = 'X';
      turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
    {
      board[row][column] = 'O';
      turn = 'X';
    }
    else 
    {
      cout << "\nPlease select an available spot on the board.\n";
      playerturn();
    }
    displayboard();
}

bool gameover()
{
  for (int i = 0; i < 3; i++)
  if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
  return false;

  if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[2][0] == board[1][1] && board[2][0] == board[0][2])
  return false;

  for(int i=0; i<3; i++)
  for(int j=0; j<3; j++)
  if(board[i][j] != 'X' && board[i][j] != 'O')
  return true;

  draw = true;
  return false;
}

int main()
{
  cout << "\n               TIC TAC TOE\n";
  cout << "                2 PLAYERS\n";

  while (gameover())
  {
    displayboard();
    playerturn();
    gameover();
  }

  if (turn == 'O' && draw == false)
  cout << "\n\nPLAYER X WINS!\n\n";
  else if (turn == 'X' && draw == false)
  cout << "\n\nPLAYER O WINS!\n\n";
  else cout << "\n\nDRAW GAME\n\n";

  return 0;
}