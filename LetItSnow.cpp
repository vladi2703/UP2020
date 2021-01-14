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
void moveDown(char**, int, int); 
int main()
{
    srand(time(NULL));
    snow(30, 20, 10);
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
void moveDown(char** matrix, int height, int width)
{
    for (int i = height - 1; i > 0 ; i--)
    {
        if (i == (height - 1))
        {
            for (int j = 0; j < width; j++)
            {
                if (matrix[i - 1][j] == '*')
                {
                    matrix[i][j] = matrix[i - 1][j];
                }

            }
        }
        else
        {
            for (int j = 0; j < width; j++)
            {
                matrix[i][j] = matrix[i - 1][j];
            }
        }
      
    }
    
    for (int i = 0; i < width; i++) //clear first row
    {
        matrix[0][i] = ' ';
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

    for (int i = 0; i < seconds; i++)
    {
        moveDown(picture, height, width);
        int counter = 0;
  const int maxSnowflakes = width / 4;

        for (int k = 0; k < width; k++)
        {
            bool snowflake = rand() % 2; //random function - result 0 or 1
            if (snowflake)
            {
                picture[0][k] = '*';
                counter++;
            }
            else
            {
                picture[0][k] = ' ';
            }
            if (counter == maxSnowflakes)
            {
                break;
            }
        }
       
        wait(1);
        clear();
        print(picture, height, width);
    }
    for (int i = 0; i < height; i++)
    {
        delete[] picture[i];
    }
    delete[] picture; 
} 

//TODO: po ravnomerni snejinki

