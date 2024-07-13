#include <iostream>
using namespace std;

class TicTacToe {
private:
    int board[3][3];

public:
    TicTacToe() {
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                board[row][col] = 0;
            }
        }
    }

    void displayBoard() {
        cout << "  0 1 2" << endl;
        for (int row = 0; row < 3; ++row) {
            cout << row << " ";
            for (int col = 0; col < 3; ++col) {
                if (board[row][col] == 0) cout << ".";
                else if (board[row][col] == 1) cout << "X";
                else cout << "O";
                cout << " ";
            }
            cout << endl;
        }
    }

    bool isMoveValid(int row, int col) {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == 0);
    }

    void executeMove(int player) {
        int row, col;
        while (true) {
            cout << "Player " << player << ", enter your move (row and column): ";
            cin >> row >> col;
            if (isMoveValid(row, col)) {
                board[row][col] = player;
                break;
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }
    }

    int checkGameStatus() {
        // Check rows and columns for a win
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0)
                return board[i][0];
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0)
                return board[0][i];
        }

        // Check diagonals for a win
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0)
            return board[0][0];
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0)
            return board[0][2];

        // Check for a draw
        bool isDraw = true;
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (board[row][col] == 0) {
                    isDraw = false;
                    break;
                }
            }
        }

        if (isDraw) return 0;

        // Game is still ongoing
        return -1;
    }
};

int main() {
    TicTacToe game;
    int currentPlayer = 1;
    int gameStatus;

    while ((gameStatus = game.checkGameStatus()) == -1) {
        game.displayBoard();
        game.executeMove(currentPlayer);
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    game.displayBoard();
    if (gameStatus == 0) {
        cout << "It's a draw!" << endl;
    } else {
        cout << "Player " << gameStatus << " wins!" << endl;
    }

    return 0;
}
