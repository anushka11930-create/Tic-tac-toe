#include <stdio.h>

char board[3][3];


void initBoard() {
    int i, j;
    char ch = '1';
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }
}


void printBoard() {
    int i, j;
    printf("\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if(j < 2) printf("|");
        }
        printf("\n");
        if(i < 2) printf("---|---|---\n");
    }
    printf("\n");
}


int checkWin() {
    int i;

   
    for(i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }

    
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

int main() {
    int move, player = 1, row, col, count = 0;
    char mark;

    initBoard();

    while(1) {
        printBoard();

        if(player == 1)
            mark = 'X';
        else
            mark = 'O';

        printf("Player %d (%c), enter position (1-9): ", player, mark);
        scanf("%d", &move);

        row = (move - 1) / 3;
        col = (move - 1) % 3;

        if(board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[row][col] = mark;
        count++;

        if(checkWin()) {
            printBoard();
            printf(" Player %d (%c) wins!\n", player, mark);
            break;
        }

        if(count == 9) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        player = (player == 1) ? 2 : 1;
    }

    return 0;
}