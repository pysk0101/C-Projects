#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
ROCK > SCISSORS
SCISSORS > PAPER
PAPER > ROCK
*/

char winner = ' ';
int PlayerWin = 0;
int ComputerWin = 0;
char moves[3] = {'R', 'P', 'S'};

void printOptions();
void print_rock();
void print_paper();
void print_scissors();
char playerMoves();
char computerMoves();
void showComputerMoves(char ComputerMove);
void compareMoves(char PlayerMove, char ComputerMove);
void currentState();
void checkWinner();
void printWinner();

int main()
{
    printf("\nWelcome to the Rock-Paper-Scissors Game!\n\n");
    do
    {
        printOptions();
        char playerMove = playerMoves();
        char computerMove = computerMoves();
        showComputerMoves(computerMove);
        compareMoves(playerMove, computerMove);
        currentState();
        checkWinner();
    } while (winner == ' ');
    printWinner();
    return 0;
}

void printOptions()
{
    print_rock();
    print_paper();
    print_scissors();
    printf("\nPlease choose a move\n");
}

void print_rock()
{
    printf("1-\n");
    printf("   _______\n");
    printf("---'   ____)\n");
    printf("      (_____)\n");
    printf("      (_____)\n");
    printf("      (____)\n");
    printf("---.__(___)\n");
}

void print_paper()
{
    printf("2-\n");
    printf("    _______\n");
    printf("---'   ____)____\n");
    printf("          ______)\n");
    printf("          _______)\n");
    printf("         _______)\n");
    printf("---.__________)\n");
}

void print_scissors()
{
    printf("3-\n");
    printf("    _______\n");
    printf("---'   ____)____\n");
    printf("          ______)\n");
    printf("       __________)\n");
    printf("      (____)\n");
    printf("---.__(___)\n");
}

char playerMoves()
{
    int choice;
    scanf("%d", &choice);
    choice--;
    return moves[choice];
}

char computerMoves()
{
    srand(time(0));
    int choice = rand() % 3;
    return moves[choice];
}

void showComputerMoves(char ComputerMove)
{
    if (ComputerMove == 'R')
    {
        printf("\nComputer made Rock");
    }
    else if (ComputerMove == 'P')
    {
        printf("\nComputer made Paper");
    }
    else if (ComputerMove == 'S')
    {
        printf("\nComputer made Scissors");
    }
};
void compareMoves(char PlayerMove, char ComputerMove)
{
    if ((PlayerMove == 'R' && ComputerMove == 'S') ||
        (PlayerMove == 'S' && ComputerMove == 'P') ||
        (PlayerMove == 'P' && ComputerMove == 'R'))
    {
        PlayerWin++;
    }
    else if (
        (ComputerMove == 'R' && PlayerMove == 'S') ||
        (ComputerMove == 'S' && PlayerMove == 'P') ||
        (ComputerMove == 'P' && PlayerMove == 'R'))
    {
        ComputerWin++;
    }
}

void checkWinner()
{
    if (PlayerWin == 3)
    {
        winner = 'P';
    }
    else if (ComputerWin == 3)
    {
        winner = 'C';
    }
}

void printWinner()
{
    if (winner == 'P')
    {
        printf("Congratulations! YOU WON!");
    }
    else if (winner == 'C')
    {
        printf("Unfortunately, YOU LOST :( ");
    }
}

void currentState()
{
    if (PlayerWin == 3 || ComputerWin == 3)
    {
        printf("\nYOU : %d \nCOMPUTER: %d", PlayerWin, ComputerWin);
        printf("\nGAME OVER! \n");
        return;
    }
    printf("\nYOU : %d \nCOMPUTER: %d\n", PlayerWin, ComputerWin);
}