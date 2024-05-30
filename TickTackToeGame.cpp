#include <iostream>
#include <Windows.h>

using namespace std;

void drawBoard(char board[3][3]) {
    cout << "-------------\n";
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

void resetBoard(char board[3][3]) {
    char initialBoard[3][3] = { {'1', '2', '3'},
                                {'4', '5', '6'},
                                {'7', '8', '9'} };
    memcpy(board, initialBoard, 9 * sizeof(char));
}

void playTicTacToe() {
    char board[3][3];
    resetBoard(board);

    bool gameActive = true;
    int currentPlayer = 1;
    int moves = 0;

    cout << "Player 1 (X) - Player 2 (O)\n";
    while (gameActive) {
        drawBoard(board);

        int choice;
        cout << "Player " << currentPlayer << ", enter your choice (or 0 to reset): ";
        cin >> choice;

        if (choice == 0) {
            resetBoard(board);
            cout << "Game reset.\n";
            currentPlayer = 1;
            moves = 0;
            continue;
        }

        if (choice < 1 || choice > 9) {
            cout << "Invalid choice. Choose a number between 1 and 9.\n";
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "That position is already taken. Choose another one.\n";
            continue;
        }

        board[row][col] = (currentPlayer == 1) ? 'X' : 'O';
        moves++;

        if (checkWin(board, (currentPlayer == 1) ? 'X' : 'O')) {
            drawBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            gameActive = false;
        }
        else if (moves == 9) {
            drawBoard(board);
            cout << "It's a draw!\n";
            gameActive = false;
        }
        else {
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }
    }
}

int main() {
    system("COLOR 4f");

    bool playGame = true;
    while (playGame) {
        cout << "Tic Tac Toe Game\n";
        cout << "1. Play Game\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";

        int menuChoice;
        cin >> menuChoice;

        switch (menuChoice) {
        case 1:
            playTicTacToe();
            break;
        case 2:
            playGame = false;
            cout << "Thanks for playing!\n";
            break;
        default:
            cout << "Invalid choice. Please enter 1 or 2.\n";
            break;
        }
    }

    return 0;
}
