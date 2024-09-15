// Tic-Tac-Toe Game

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char Player = 'X';
const char Computer = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main()
{
    char winner = ' ';
    char response = ' ';
    resetBoard();
    do
    {
        winner = ' ';
        response = ' ';
        resetBoard();
        while (winner == ' ' && checkFreeSpaces() != 0)
        {
            printBoard();

            playerMove();
            winner = checkWinner();

            if (winner != ' ' || checkFreeSpaces() == 0)
            {
                // Works when player wins
                break;
            }

            computerMove();
            winner = checkWinner();

            if (winner != ' ' || checkFreeSpaces() == 0)
            {
                // Works when Computers wins
                break;
            }
        }

        printBoard();
        printWinner(winner);

        printf("\nWould you like to play again? (Y/N): ");
        while (getchar() != '\n')
            ; // Giriş tamponunu temizle
        scanf(" %c", &response);
        response = toupper(response);

    } while (response == 'Y');

    printf("\nThanks for playing!");

    return 0;
}

void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
};

void printBoard()
{
    printf("\n   1   2   3 ", board[0][0], board[0][1], board[0][2]);
    printf("\n1  %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n  ---|---|---\n");
    printf("2  %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n  ---|---|---\n");
    printf("3  %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
};
int checkFreeSpaces()
{
    int freeSpaces = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
};
void playerMove()
{
    int x;
    int y;
    do
    {
        printf("Enter a row #(1-3): ");
        scanf("%d", &x);
        x--;
        printf("Enter a column #(1-3): ");
        scanf("%d", &y);
        y--;
        if (board[x][y] != ' ')
        {
            printf("Invalid move!\n");
        }
        else
        {
            printf("%d", board[x][y]);
            board[x][y] = Player;
            break;
        }
    } while (board[x][y] != ' ');
};
void computerMove()
{
    if (checkFreeSpaces() > 0)
    {
        srand(time(0));
        int x;
        int y;
        do
        {

            x = (rand() % 3);
            y = (rand() % 3);
        } while (board[x][y] != ' ');
        board[x][y] = Computer;
    }
    else
    {
        printWinner(' ');
    }
};
char checkWinner()
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return board[i][0];
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
        {
            printf("Colums same");
            printf("board[i][0] = %d\n ", board[0][i]);
            printf("board[i][1] = %d\n ", board[1][0]);
            return board[0][i];
        }
    }
    // Check First Diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        printf("Diagonal same");
        return board[0][0];
    }
    // Check Second Diagonal
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ')
    {
        printf("Diagonal same");
        return board[2][0];
    }
    return ' ';
};
void printWinner(char winner)
{
    if (winner == Player)
    {
        printf("YOU WIN!");
    }
    else if (winner == Computer)
    {
        printf("YOU LOSE!");
    }
    else
    {
        printf("IT'S A TIE!");
    }
}