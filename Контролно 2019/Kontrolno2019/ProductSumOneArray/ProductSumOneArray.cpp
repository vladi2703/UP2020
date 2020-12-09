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
	for (int i = 0; i < N; i++)
	{
		if (arr[i] < average)
		{
			for (int j = i; j < N-1; j++)
			{
				arr[j] = arr[j + 1];
			}
			N--;
			i--;
		}
	}
	std::cout << "\n";
	for (int i = 0; i < N; i++)
	{
		std::cout << arr[i] << ' ';
	}



}
