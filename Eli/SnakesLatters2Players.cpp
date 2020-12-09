#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main ()
{
    srand(time(NULL)); // Това го сложете в началото на мейна


    int snake[50];
    int random, pointsForward = 0, position1 = 0,position2 = 0, countSteps = 0;
    for (int i = 0; i < 50; i++)
    {
        switch (i)
        {
            case 5:
                snake[i] = 8;
                break;
            case 15:
                snake[i] = -12;
                break;
            case 16:
                snake[i] = 6;
                break;
            case 26:
                snake[i] = 6;
                break;
            case 28:
                snake[i] = -19;
                break;
            case 37:
                snake[i] = 5;
                break;
            case 39:
                snake[i] = -19;
                break;
            case 44:
                snake[i] = -11;
                break;

            default: snake[i] = 0;
                break;
        }
    }

    while (position1 + 1 != 50 && position2 + 1 != 50)
    {

        int random = rand() % 5 + 1; //Фунцията rand() ни дава някакво случайно. След това взимаме остатък при деление с 6 (което ни дава опциите от 0 до 5)
      //и прибавяме 1 (за да станат от 1 до 6)
        cout << random << endl;


        if (random == 1)
        {
            pointsForward = 1;
        }
        else if (random == 2 || random == 4)
        {
            pointsForward = random + 1;
        }
        else if (random == 3 || random == 5)
        {
            pointsForward = random + 2;
        }
        else
        {
            cout << "Random must be between 1-5" << endl;
        }

        if (position1 + pointsForward >= 50 || position2 + pointsForward >= 50)
        {
            pointsForward = 0;
        }
        if(countSteps % 2 == 1)
        {
            position1 += pointsForward;
            position1 += snake[position1];
            countSteps++;
            cout << "Player one is on " << position1 + 1 << " position" << endl;
        }
        else
        {
            position2 += pointsForward;
            position2 += snake[position2];
            countSteps++;
            cout << "Player two is on " << position2 + 1 << " position" << endl;
        }
        random = 0;
        pointsForward = 0;
    }
    if(position1 + 1 == 50)
    {
        cout << "Congratulations Player1 won in " << countSteps << " turns";
    }
    else
    {
        cout << "Congratulations Player2 won in " << countSteps << " turns";
    }
    return 0;

}
