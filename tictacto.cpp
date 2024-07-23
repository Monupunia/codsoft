#include <iostream>
#include <vector>

using namespace std;

vector<vector< char >>board(3, vector<char>(3, ' '));

// Function to display the game board
void displayBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        if (i < 2) {
            cout << "---------" << endl;
        }
    }
}

// Function to check if a player has won
bool checkWin(char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to play the game
void playGame() {
    char currentPlayer = 'X';
    while (true) {
        displayBoard();
        cout << "Player " << currentPlayer << "'s turn. Enter row and column (0-2): ";
        int row, col;
        cin >> row >> col;
        if (board[row][col] != ' ') {
            cout << "Invalid move, try again." << endl;
            continue;
        }
        board[row][col] = currentPlayer;
        if (checkWin(currentPlayer)) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }
        if (checkDraw()) {
            displayBoard();
            cout << "It's a draw!" << endl;
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

// Function to ask if players want to play again
void playAgain() {
    char response;
    cout << "Do you want to play again? (y/n): ";
    cin >> response;
    if (response == 'y') {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
        playGame();
    } else {
        cout << "Thanks for playing!" << endl;
    }
}

int main() {
    playGame();
    playAgain();
    return 0;
}
