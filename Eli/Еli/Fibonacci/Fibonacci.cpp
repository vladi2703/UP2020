#include <iostream>
using namespace std; 
int main()
{
	bool isFibonacci = true; 
	int array[100];
	int n, counter = 0;
	cout << "Enter number n: ";
	cin >> n;

	for (int i = 0; i < 100; i++)
	{
		array[i] = n % 10;
		n /= 10;
		if (n != 0)
		{
			counter++;
		}

	}
	for (int i = 0; i < counter-1; i++)
	{
		if (array[i] + array[i + 1] != array[i + 2])
		{
			isFibonacci = false; 
		}
	}
	isFibonacci ? cout << "Da" : cout << "Ne";
}