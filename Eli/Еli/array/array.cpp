
#include <iostream>
using namespace std; 
int main()
{
    int countOfElements = 0, countOfOdds = 0, initialNumber = 0, sum = 0;
    double average =0; 
    double newArray[2]; 
    cout << "Enter count of elements: "; 
    cin >> countOfElements;
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
            countOfOdds++;      // count = 1 + 1
        }
       
        initialNumber = array[i];
        array[i] /= 100;
       
        if (array[i] % 10 == 6)   
        {
            sum += initialNumber;
        }
    }
    average /= countOfOdds; 

    
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