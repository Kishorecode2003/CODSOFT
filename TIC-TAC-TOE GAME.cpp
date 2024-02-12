#include <iostream>
#include <vector>

void displayBoard(const std::vector<std::vector<char> >& board);
bool checkWin(const std::vector<std::vector<char> >& board, char player);
bool checkDraw(const std::vector<std::vector<char> >& board);
bool isValidMove(const std::vector<std::vector<char> >& board, int row, int col);
void switchPlayer(char& currentPlayer);

int main() {
    std::vector<std::vector<char> > board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';

    bool gameOver = false;
    while (!gameOver) {
        displayBoard(board);

        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        if (isValidMove(board, row, col)) {
            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                gameOver = true;
            } else if (checkDraw(board)) {
                displayBoard(board);
                std::cout << "It's a draw!" << std::endl;
                gameOver = true;
            } else {
                switchPlayer(currentPlayer);
            }
        } else {
            std::cout << "Invalid move! Please try again." << std::endl;
        }
    }

    return 0;
}

void displayBoard(const std::vector<std::vector<char> >& board) {
    for (std::vector<std::vector<char> >::size_type i = 0; i < board.size(); ++i) {
        for (std::vector<char>::size_type j = 0; j < board[i].size(); ++j) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

bool checkWin(const std::vector<std::vector<char> >& board, char player) {
    for (std::vector<std::vector<char> >::size_type i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool checkDraw(const std::vector<std::vector<char> >& board) {
    for (std::vector<std::vector<char> >::size_type i = 0; i < board.size(); ++i) {
        for (std::vector<char>::size_type j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool isValidMove(const std::vector<std::vector<char> >& board, int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}

void switchPlayer(char& currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
