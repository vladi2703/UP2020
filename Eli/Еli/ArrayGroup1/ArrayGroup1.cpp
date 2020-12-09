


#include <iostream>
using namespace std;
int main()
{
    int countOfEven;
    double average;
    double array1[100], array2[100];
    cout << "Enter count of elements of first array: ";
    while (true)
    {

    }
    int array[100];
    cout << "Enter elements: ";
    for (int i = 0; i < countOfElements; i++)
    {

        cin >> array[i];
    }

    for (int i = 0; i < countOfElements; i++)
    {
        if (array[i] % 2 == 1) //1 2 3 
        {
            average += array[i];  // average = 1 + 3
            countOfEven++;      // count = 1 + 1
        }

        initialNumber = array[i];
        array[i] /= 100;

        if (array[i] % 10 == 6)
        {
            sum += initialNumber;
        }
    }
    average /= countOfEven;


    if (average > sum)
    {
        newArray[0] = sum;
        newArray[1] = average;
    }
    else
    {
        newArray[0] = average;
        newArray[1] = sum;
    }
    cout << newArray[0] << " " << newArray[1];
}