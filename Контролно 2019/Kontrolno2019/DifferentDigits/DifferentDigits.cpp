#include <iostream>

int main()
{
    int leftBound, rightBound;
	std::cin >> leftBound >> rightBound;
	int counter = rightBound - leftBound;
	
	for (int i = leftBound; i < rightBound; i++)
	{
		int arr[10] = {};
		int number = i;
		while (number != 0)
		{
			arr[number % 10]++;
			if (arr[number%10] > 1)
			{
				counter--;
				break;
			}
			number /= 10;

		}
	}
	std::cout << counter;
}
