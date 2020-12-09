#include <iostream>

int main()
{
    int leftBound, rightBound;
	int countOfElements = 0;
	bool isPrime = true; 
	std::cin >> leftBound >> rightBound;
	for (int i = leftBound; i <= rightBound; i++)
	{
		isPrime = true;
		int countOfDivisors = 0;
		for (int j = 2; j <= i/2; j++)
		{
			if (i % j == 0)
				countOfDivisors++;
		}
		for (int g = 2; g <= countOfDivisors/2; g++)
		{
			if (countOfDivisors % g == 0 && countOfDivisors != 2)
			{ 
				isPrime = false; 
				break;
			}
		}
		if (countOfDivisors == 1 || countOfDivisors == 0)
		{
			isPrime = false;
		}
		if (isPrime)
			countOfElements++;

	}
	std::cout << countOfElements << std::endl;
}
