#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'},
                     {'4', '5', '6'},
                     {'7', '8', '9'} };

char currentPlayer = 'X';


void displayBoard() {
    cout << "Tic-Tac-Toe Board: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


bool checkWin() {
  
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}


void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}


 
bool makeMove(int move) {
    int row = (move - 1) / 3;
     int col = (move - 1) % 3;

      if (board[row][col] != 'X' && board[row][col] != 'O') {
          board[row][col] = currentPlayer;
        return true;
    } else  {
        cout << "Invalid move! Try again." << endl;
        return false;
    }
}

int main() {
    int move;
    bool gameOngoing = true;

     while (gameOngoing) {
        displayBoard();

      
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
         cin >> move;

      
        if (move >= 1 && move <= 9 && makeMove(move)) {
        
             if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOngoing = false;
             }
         
            else if (checkDraw()) {
                 displayBoard();
                cout << "The game is a draw!" << endl;
                gameOngoing = false;
             } else {
               
                switchPlayer();
            }
        }
    }
 
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;

    if   (playAgain == 'y' || playAgain == 'Y') {
        char initialBoard[3][3] = { {'1', '2', '3'},
                                     {'4', '5', '6'},
                                    {'7', '8', '9'} };
        copy(&initialBoard[0][0], &initialBoard[0][0] + 9, &board[0][0]);
        currentPlayer = 'X';
         main(); 
    } else {
        cout << "Thanks for playing!" << endl;
    }
 
      return 0;
}
