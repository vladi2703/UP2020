#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>     
#include <time.h>
#include <thread>        

void snow(int, int, int);
void print(char**, int, int);
void wait(int);
void clear();
void moveDown(char**, int); 
int main()
{
    srand(time(NULL));
    snow(10, 20, 10);
} 
void clear()
{
    system("cls");
}
void wait(int seconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 1000));
}
void print(char** matrix, int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            std::cout << matrix[i][j];
        }
        std::cout << '\n';
    }
}
void moveDown(char** matrix, int height)
{
    for (int i = height-1; i > 0 ; i--)
    {
        for (int j = 0; j < 20; j++)
        {
            matrix[i][j] = matrix[i - 1][j];
        }
    }

}
void snow(int seconds, int width, int height)
{
    char** picture = new char* [height];
    for (int i = 0; i < height; i++)
    {
        picture[i] = new char[width+1];
            for (int j = 0; j < width; j++)
            {
                picture[i][j] = ' ';
            }
            picture[i][width] = '\0';
    }

    while(true)
    {
        moveDown(picture, height);
        for (int k = 0; k < width; k++)
        {
            bool snowflake = rand() % 2; //random function - result 0 or 1
            if (snowflake)
            {
                picture[0][k] = '*';
            }
            else
            {
                picture[0][k] = ' ';
            }
        }
       
        wait(1);
        clear();
        print(picture, height, width);
    } 
} 

// TODO: Snow @ the bottom
//Less snowflakes

