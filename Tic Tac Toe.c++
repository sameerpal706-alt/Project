#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

// Initialize Board
void initializeBoard() {
    char ch = '1';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }

    currentPlayer = 'X';
}

// Display Board
void displayBoard() {
    cout << "\n";
    cout << "-------------\n";

    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Make Move
bool makeMove(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    }

    return false;
}

// Check Winner
bool checkWinner() {

    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return true;
    }

    // Diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return true;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return true;

    return false;
}

// Check Draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

// Switch Player
void switchPlayer() {
    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

int main() {

    char playAgain;

    do {
        initializeBoard();
        bool gameOver = false;

        while (!gameOver) {
            displayBoard();

            int choice;
            cout << "\nPlayer " << currentPlayer
                 << ", enter position (1-9): ";
            cin >> choice;

            if (choice < 1 || choice > 9) {
                cout << "Invalid position! Try again.\n";
                continue;
            }

            if (!makeMove(choice)) {
                cout << "Position already occupied! Try again.\n";
                continue;
            }

            if (checkWinner()) {
                displayBoard();
                cout << "\nPlayer " << currentPlayer
                     << " wins the game!\n";
                gameOver = true;
            }
            else if (checkDraw()) {
                displayBoard();
                cout << "\nGame Draw!\n";
                gameOver = true;
            }
            else {
                switchPlayer();
            }
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThank you for playing Tic Tac Toe!\n";

    return 0;
}