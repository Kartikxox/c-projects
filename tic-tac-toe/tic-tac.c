#include <stdio.h>

char board[3][3];

// Function to initialize the board
void initializeBoard() {
    char ch = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }
}

// Function to display the board
void displayBoard() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to update the board
int makeMove(int choice, char mark) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice < 1 || choice > 9)
        return 0;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = mark;
        return 1;
    }

    return 0;
}

// Function to check winner
int checkWinner() {

    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return 1;
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return 1;
    }

    // Diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return 1;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return 1;

    return 0;
}

// Function to check draw
int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
        }
    }
    return 1;
}

int main() {
    int choice;
    char currentPlayer = 'X';

    initializeBoard();

    while (1) {
        displayBoard();

        printf("Player %c, enter your choice (1-9): ", currentPlayer);
        scanf("%d", &choice);

        if (!makeMove(choice, currentPlayer)) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        if (checkWinner()) {
            displayBoard();
            printf("🎉 Player %c Wins!\n", currentPlayer);
            break;
        }

        if (checkDraw()) {
            displayBoard();
            printf("Game Draw!\n");
            break;
        }

        // Switch player
        if (currentPlayer == 'X')
            currentPlayer = 'O';
        else
            currentPlayer = 'X';
    }

    return 0;
}