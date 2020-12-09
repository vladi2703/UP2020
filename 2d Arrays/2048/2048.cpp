#include <iostream>

const int DIM = 4;
int score = 0; 
//we multiply by 20 in order not to do 2 operations in one turn
void up(int arr[DIM][DIM])
{
    for (int cols = 0; cols < DIM; cols++)
    {
        for (int row = 0; row < DIM; row++)
        {
            int element = arr[row][cols];
            if (element == 0)
            {
                continue;
            }
            else
            {
                if (row == 0)
                {
                    continue;
                }
                else
                {
                    if (element == arr[row - 1][cols])
                    {
                        score += 2 * element;
                        arr[row - 1][cols] *= 20;
                        arr[row][cols] = 0;
                    }
                    else if (arr[row- 1][cols] == 0)
                    {

                        for (int i = 1; (row - i) >= 0; i++)
                        {
                            if (arr[row - i][cols] == 0)
                            {
                                arr[row - i][cols] = element;
                                arr[row - i + 1][cols] = 0;
                            }
                            else if (arr[row - i][cols] == element)
                            {
                                score += 2 * element;
                                arr[row - i][cols] *= 20;
                                arr[row - i + 1][cols] = 0;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                    else if (arr[row - 1][cols] != element)
                    {
                        continue;
                    }
                }
            }
        }
    }
}
void down(int arr[DIM][DIM])
{

    for (int cols = 3; cols >= 0; cols--)
    {
        for (int row = 3; row >= 0; row--)
        {
            int element = arr[row][cols];
            if (element == 0)
            {
                continue;
            }
            else
            {
                if (row == 3)
                {
                    continue;
                }
                else
                {
                    if (element == arr[row + 1][cols])
                    {
                        score += 2 * element;
                        arr[row + 1][cols] *= 20;
                        arr[row][cols] = 0;
                    }
                    else if (arr[row + 1][cols] == 0)
                    {

                        for (int i = 1; (row + i) < 4; i++)
                        {
                            if (arr[row + i][cols] == 0)
                            {
                                arr[row + i][cols] = element;
                                arr[row + i - 1][cols] = 0;
                            }
                            else if (arr[row + i][cols] == element)
                            {
                                score += 2 * element;
                                arr[row + i][cols] *= 20;
                                arr[row + i - 1][cols] = 0;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                    else if (arr[row + 1][cols] != element)
                    {
                        continue;
                    }
                }
            }
        }
    }

}
void left(int arr[DIM][DIM])
{
    {
        for (int row = 0; row < DIM; row++)
        {
            for (int cols = 0; cols < DIM; cols++)
            {
                int element = arr[row][cols];
                if (element == 0)
                {
                    continue;
                }
                else
                {
                    if (cols == 0)
                    {
                        continue;
                    }
                    else
                    {
                        if (element == arr[row][cols - 1])
                        {
                            score += 2 * element;
                            arr[row][cols - 1] *= 20;
                            arr[row][cols] = 0;
                        }
                        else if (arr[row][cols - 1] == 0)
                        {

                            for (int i = 1; (cols - i) >= 0; i++)
                            {
                                if (arr[row][cols - i] == 0)
                                {
                                    arr[row][cols - i] = element;
                                    arr[row][cols - i + 1] = 0;
                                }
                                else if (arr[row][cols - i] == element)
                                {
                                    score += 2 * element;
                                    arr[row][cols - i] *= 20;
                                    arr[row][cols - i + 1] = 0;
                                }
                                else
                                {
                                    break;
                                }
                            }
                        }
                        else if (arr[row][cols - 1] != element)
                        {
                            continue;
                        }
                    }
                }
            }
        }
    }
}
void right(int arr[DIM][DIM])
{

    for (int row = 3; row >= 0; row--)
    {
        for (int cols = 3; cols >= 0; cols--)
        {
            int element = arr[row][cols];
            if (element == 0)
            {
                continue;
            }
            else
            {
                if (cols == 3)
                {
                    continue;
                }
                else
                {
                    if (element == arr[row][cols + 1])
                    {
                        score += 2*element;
                        arr[row][cols + 1] *= 20;
                        arr[row][cols] = 0;
                    }
                    else if (arr[row][cols + 1] == 0)
                    {

                        for (int i = 1; (cols + i) < 4; i++)
                        {
                            if (arr[row][cols + i] == 0)
                            {
                                arr[row][cols + i] = element;
                                arr[row][cols + i - 1] = 0;
                            }
                            else if (arr[row][cols + i] == element)
                            {
                                score += 2 * element;
                                arr[row][cols + i] *= 20;
                                arr[row][cols + i - 1] = 0;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                    else if (arr[row][cols + 1] != element)
                    {
                        continue;
                    }
                }
            }
        }
    }

}
bool differentElement(int arr[DIM][DIM], int check[DIM][DIM] )
{
    bool differentElement = false;
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            if (arr[i][j] != check[i][j])
            {
                differentElement = true;
                return differentElement; 
            }
        }
    }
    return differentElement; 
}
void copyArray(int arrToCopy[DIM][DIM], int newArr[DIM][DIM])
{
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            arrToCopy[i][j] = newArr[i][j];
        }
    }
}
bool moveCheck(int arr[DIM][DIM])
{
    int initialBoard[DIM][DIM] = {};
    copyArray(arr, initialBoard);
    up(arr); 
    if (differentElement(arr, initialBoard))
    {
        return true; 
    }
    copyArray(initialBoard, arr);
    down(arr);
    if (differentElement(arr, initialBoard))
    {
        return true;
    }
    copyArray(initialBoard, arr);
    left(arr);
    if (differentElement(arr, initialBoard))
    {
        return true;
    }
    copyArray(initialBoard, arr);
    right(arr);
    if (differentElement(arr, initialBoard))
    {
        return true;
    }
    copyArray(initialBoard, arr);
    return false;
}
void print(int arr[DIM][DIM], bool* gameOver)
{
    int twoSpawned = false;
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            if (arr[i][j] == 20480)
            {
                *gameOver = true; 
                std::cout << "Good job, you won \n";
                return; 
            }
            if (arr[i][j] % 10 == 0)
            {
                arr[i][j] /= 10;
            }
            if (arr[i][j] == 0 && !twoSpawned)
            {
                arr[i][j] += 2;
                twoSpawned = true;
            }
            std::cout << arr[i][j] << ' '; 
        }
        std::cout << "\n"; 
    }
    if (!twoSpawned)
    {
        if (!moveCheck(arr))
        {
            *gameOver = true; 
            std::cout << "The End \n";
        }
        std::cout << "No possible move \n";
    }
    std::cout << "Your current score is: " << score << std::endl;
}
int main()
{
    bool gameOver = false;
    int pesho[DIM][DIM] = {};
    char move; 
    print(pesho, &gameOver);
    
    while (!gameOver)
    {
       

        std::cin >> move;
        switch (move)
        {
        case 'R':
            right(pesho);
            print(pesho, &gameOver);
            break;
        case 'L':
            left(pesho);
            print(pesho, &gameOver);
            break;
        case 'U':
            up(pesho);
            print(pesho, &gameOver);
            break;
        case 'D':
            down(pesho);
            print(pesho, &gameOver);
            break;
        case 'E':
            std::cout << "The End \n";
            return 0;
            break;


        default: std::cout << "Enter a valid command: ";
            break;
        }

    }
    

}

//TODO: 