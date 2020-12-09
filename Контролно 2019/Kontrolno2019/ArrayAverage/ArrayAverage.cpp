#include <iostream>
const short MAX_SIZE = 1000;
int main()
{
	int N; 
	double arr[MAX_SIZE]; 
	double average = 0;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> arr[i];
		average += arr[i];
	}
	for (int i = 0; i < N; i++)
	{
		std::cout << arr[i] << ' ';
	}
	average /= N;
	double newArray[MAX_SIZE]; 
	int counter = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] >= average)
		{
			newArray[counter] = arr[i];
			counter++;
		}
	}
	std::cout << "\n"; 
	for (int i = 0; i < counter; i++)
	{
		std::cout << newArray[i] << ' ';
	}

	

}
