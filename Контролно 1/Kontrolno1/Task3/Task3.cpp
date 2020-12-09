#include <iostream>
const int MAX_SIZE = 1000;
int main()
{
	int n, maxK = -1; 
	int arr[MAX_SIZE];
	bool check = true;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin>>arr[i];
	}
	for (int k = 0; k < n; k++)
	{
		check = true;
		for (int i = 0; i < n; i++)
		{
			if ((i+k)<n)
			{
				if (abs(arr[i] - arr[i+k]) != k)
				{
					check = false;
					break;
				}
			}
			
		}
		if (check)
		{
			maxK = k;
		}
	}
	if (maxK == -1)
	{
		std::cout << "No solution" << std::endl;
	}
	else
	{
		std::cout << maxK << std::endl;
	}
}

