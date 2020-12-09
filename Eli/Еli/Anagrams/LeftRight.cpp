#include <iostream>
using namespace std;
int main()
{
	int number, lastDigit, counter = 1; 
	int array[100];
	bool isTrue = true; 
	cout << "Enter number: ";

	cin >> number;
	for (int i = 0; i < 100; i++)
	{
		lastDigit = number % 10;
		number /= 10;
		array[i] = lastDigit;
		if (number != 0)
		{
			counter++;
		}
	}
	
	for (int i = 0; i < counter; i+=2)
	{
		if (array[i] <= array[i + 1])
		{
			isTrue = false;
		}
	}
	if (isTrue)
	{
		cout << "Da";
	}
	else
	{
		cout << "Ne";	
	}
	return 0;
}