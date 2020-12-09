#include <iostream>
const int ROWS = 20, COLS = 40;
bool gameOver = false; 

void init(int height, int length, char arr[ROWS][COLS])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < length; j++)
        {
            arr[i][j] = ' ';
        }
    }
}
void print(int height, int length, char arr[ROWS][COLS])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < length; j++)
        {
            std::cout << '|' << arr[i][j] ;
        }
        std::cout << '|' << "\n";
    }
}
bool checkHorVer(int a, int b, char arr[ROWS][COLS], int length, int height)
{
    int vertical = 1;
    int horizontal = 1;
    char element = arr[a][b];
    //vertical
    for (int i = a + 1; arr[i][b] == element && i < height; i++, vertical++)
    if (vertical == 4) return true;
    //horizontal
    for (int i = b + 1; arr[a][i] == element && i < length; i++, horizontal++);
    if (horizontal == 4) return true;
    for (int i = b - 1; arr[a][i] == element && i >= 0; i--, horizontal++);
    if (horizontal == 4) return true;
    return false;
}
bool checkDiagonal(int a, int b, char arr[ROWS][COLS], int length, int height)
{
    int i, j;
    int diagonal1 = 0; // (/)
    int diagonal2 = 0;// (\)
    char element = arr[a][b];
    for (i = a, j = b; i >= 0 && j < length - 1; i--, j++); //going to the beginning of diagonal (/)
    for (i, j; i < height - 1 && j >= 0; i++, j--) //counting elements
    {
        if (arr[i][j] == element)
        {
            diagonal1++;
            if (diagonal1 == 4) return true;
        }
    }
   
    for (i = a, j = b; i >= 0 && j > 0; i--, j--); //going to the beginning of diagonal (/)
    for (i, j; i < height - 1 && j < length - 1; i++, j++) //counting elements
    {
        if (arr[i][j] == element)
        {
            diagonal2++;
            if (diagonal2 == 4) return true;
        }
    }
   
    
    
    return false;
}
void insertToken(int height, int length, int column, char player, char arr[ROWS][COLS])
{
    while (arr[0][column - 1] != ' ')
    {
        std::cout << "This column is full, enter a new one: ";
        std::cin >> column;
    }
    for (int i = height; i >= 0; i--)
    {
        if (arr[i][column - 1] == ' ')
        {
            arr[i][column - 1] = player;
            gameOver = (checkHorVer(i, column - 1, arr, length, height) || checkDiagonal(i, column - 1, arr, length, height));
            break;
        }
    }
}
int main()
{
    int height, length;
    do
    {
        std::cout << "Enter desired height and length: ";
        std::cin >> height >> length;
    } while (height > 20 || length > 40 || height < 4 || length < 4);

    char board[ROWS][COLS];
    init(height, length, board);
    print(height, length, board);
    int turns = 0, maxTurns = height * length,  column;
    char player;
    while (!gameOver)
    {
        if (turns == maxTurns)
        {
            std::cout << "Game draw! \n";
            return 0;
        }
        if (turns % 2 == 0)
        {
            player = 'X';
        }
        else
        {
            player = 'O';
        }
        std::cout << "It's player " << player << " turn. Enter a desired column: ";
        do
        {
            std::cin >> column;
        } while (column <= 0 && column > length);
        
        insertToken(height, length, column, player, board);
        print(height, length, board);
        turns++;
    }
    if (turns % 2 == 0)
    {
        std::cout << "Player O won! Game over \n";
    }
    else
    {
        std::cout << "Player X won! Game over \n";

    }
}

//TODO: WIN function + inputHeightLength function