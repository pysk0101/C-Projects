// Calculator

#include <stdio.h>
#include <ctype.h>

char operator;

void showTexts();
char signOperation(char choise);
long int calculate(char operator, int num1, int num2);

int main()
{

    char response = ' ';
    char choise = ' ';
    int num1, num2;
    long int result;
    do
    {
        showTexts();
        scanf(" %c", &choise);
        operator = signOperation(choise);

        printf("Enter Number 1:\n");
        scanf("%d", &num1);

        printf("Enter Number 2:\n");
        scanf("%d", &num2);

        result = calculate(operator, num1, num2);

        printf("The answer is %d\n", result);
        printf("Would you like to continue? (Y/N) \n");
        while (getchar() != '\n')
            ;
        scanf("%c", &response);
        response = toupper(response);

    } while (response == 'Y');

    return 0;
};

void showTexts()
{
    printf("Which opeartion would you like to do?\n");
    printf("1- Sum (+)\n");
    printf("2- Subtract (-)\n");
    printf("3- Multiply (*)\n");
    printf("4- Divide (/)\n");
};

char signOperation(char choise)
{
    switch (choise)
    {
    case '1':
        return  '+';
    case '2':
        return  '-';
    case '3':
        return  '*';
    case '4':
        return  '/';
    default:
        printf("Wrong choise!");
        break;
    }
};

long int calculate(char operator, int num1, int num2)
{
    switch (operator)
    {
    case '+':
        return num1 + num2;
    case '*':
        return num1 * num2;
    case '-':
        return num1 - num2;
    case '/':
        if (num2 != 0)
        {
            return num1 / num2;
        }
        else
        {
            printf("Error: Division by zero\n");
            return  0;
        };
    default:
        printf("Invalid operator\n");
        return 0;
    }
}