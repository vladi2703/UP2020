#include <iostream>

int main()
{
	int leftBound, rightBound;
	int countOfNumbers = 0;
	std::cin >> leftBound >> rightBound; 
	for (int i = leftBound; i <= rightBound; i++)
	{
		int product = 1, sum = 0;
		int number = i;
		while (number!=0)
		{
			product *= number % 10;
			sum += number % 10;
			number /= 10;
		}
		if (product == sum)
		{
			countOfNumbers++;
		}
	}
	std::cout << countOfNumbers;
}
