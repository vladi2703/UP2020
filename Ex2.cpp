// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;  
int main()
{
    //task 1 
/*
    int x = 0, y = 0; 
    cin >> x; 
    cin >> y;
    if (x-y < 0)
    {
        cout << y - x;
    }
    else
    {
        cout << x - y; 
    }
    
*/

    /*

    // Task 2
    int x = 0, y = 0, z = 0;
    cin >> x;
    cin >> y;
    cin >> z;
    
    if (x>y)
    {
        if (x>z)
        {
            cout << "x is the biggest";
        }
         
        else if (x < z) 
        {
            cout << "z is the biggest";
        }
    }

    else if (x < y)
    {
        if (y > z)
        {
            cout << "y is the biggest";
        }

        else if (y < z)
        {
            cout << "z is the biggest";
        }
    }
    */

    //Task 3

    /*
    double x = 0, y = 0;
    cin >> x;
    cin >> y;
   
     if (x == 0 || y == 0)
     {
     cout << "Point on the axis";
     }
    if (x > 0 && y > 0)
    {
        cout << "I";
    }
    if (x < 0 && y > 0)
    {
        cout << "II";
    }
    if (x < 0 && y < 0)
    {
        cout << "III";
    }
    if (x > 0 && y < 0)
    {
        cout << "VI";
    }
*/
 
    /*
    
    // Task 4 
    
    int y;
    cin >> y;
    if (y % 4 == 0 && y % 100 != 0)
    {
        cout << "It's a leap year";
    }
    else
    {
        cout << "It's not a leap year"; 
    }
    */

    //Task 5
 /*
    int day = 0;
    cin >> day;
    switch (day)
    {
    case 1: cout << "Monday"; break;
    case 2: cout << "Tuesday"; break;
    case 3: cout << "Wednesday"; break;
    case 4: cout << "Thursday"; break;
    case 5: cout << "Friday"; break;
    case 6: cout << "Saturday"; break;
    case 7: cout << "Sunday"; break;
    default: cout << "Enter num in interval [1;7]";
    }
*/ 

/*
*       // Task 6
        int d1 = 0, m1 = 0, d2 = 0, m2 = 0;
        cin >> d1;
        cin >> m1;
        cin >> d2;
        cin >> m2;
        
        if (d1 > 0 && d1 < 32 && d2 > 0 && d2 < 32 && m1 > 0 && m1 < 13 && m2 > 0 && m2< 13)
        {
            if (m1 < m2)
            {
                cout << 1; 
            }
            else if (m1 > m2)
            {
                cout << 2;
            }
            else if (m1 == m2) 
            {
                if (d1 < d2)
                {
                    cout << 1;
                }
                 else if (d1 > d2)
                {
                    cout << 2;
                }
                 else if (d1 = d2)
                {
                    cout << "Same date";
                }

            }

        }
        else
        {
            cout << "Enter valid date";
        }
    */

/*
            //Task 7

        int grade = 0;
        cin >> grade; 
        if (grade >= 0 && grade <= 100)
        {
            if (grade >= 0 && grade <= 59)
            {
                cout << 2;
            }
            if (grade >= 60 && grade <= 69)
            {
                cout << 3;
            }
            if (grade >= 70 && grade <= 79)
            {
                cout << 4;
            }
            if (grade >= 80 && grade <= 89)
            {
                cout << 5;
            }
            if (grade >= 90 && grade <= 99)
            {
                cout << 6;
            }

        }
        else if (grade < 0)
        {
            cout << "Impossible";
        }
        else
        {
            cout << "Incredible";
        }

        */


/*
    int s1 = 0,s2 = 0, s3 = 0;
    cin >> s1;
    cin >> s2;
    cin >> s3;
     
    if (s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1)
    {
        if (s1 == s2 && s2 == s3)
        {
            cout << "Triangle is equatorial";
        }
        else if (s1 == s2 || s2 == s3 || s1 == s3)
        {
            cout << "Triangle is isosceles";
        }
        else
        {
            cout << "Triangle is scalene";
        }
    }
    else {
        cout << "Not a triangle";
    }

    */



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
