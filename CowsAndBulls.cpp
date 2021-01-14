#include <iostream>
const int allNumbers = 9 * 8 * 7 * 6;

void intToChar(int number, char* numberChar)
{
	for (int i = 3; i >= 0; i--)
	{
		numberChar[i] = '0' + number % 10;
		number /= 10;
	}
}
int countBulls(char* secret, char* guess)
{
	int bulls = 0;
	for (int i = 0; i < 4; i++)
	{
		if (secret[i] == guess[i])
		{
			bulls++; 
		}
	}
	return bulls; 
}
int countCows(char* secret, char* guess)
{
	int cows = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (secret[i] == guess[j] && i != j) //if i == j -> bull
			{
				cows++;
			}
		}
		
	}
	return cows;
}
void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' '; 
	}
}
void initializePossibleGuesses(int* arr)
{
	int counter = 0; 
	for (int i = 1234; i < 9876; i++)
	{
		bool validNumber = true;

		int copy = i;
		bool histogram[10] = { true };
		for(int j = 0; j < 4; j++)
		{
			
			
			if (histogram[copy % 10])
			{
				validNumber = false; 
				break;
			}
			histogram[copy % 10]= true;
			copy /= 10;
		}
		if (validNumber)
		{
			arr[counter++] = i;
		}
	}
	
}
void eliminatePossibleGuess(int* arr, char* secret, int secretCows, int secretBulls)
{
	char guess[4];

	for (int i = 0; i < allNumbers; i++)
	{
		if (arr[i] == 0)
		{
			continue;
		}
		intToChar(arr[i], guess);
		int guessCows = countCows(secret, guess);
		int guessBulls = countBulls(secret, guess);
		if (guessCows != secretCows || guessBulls != guessCows)
		{
			arr[i] = 0;
		}
	}
}

void getResult(int* cows, int* bulls, int* result)
{
	*cows = result[0];
	*bulls = result[1];
}
int main()
{
	int possibleGuess[allNumbers];
	initializePossibleGuesses(possibleGuess);
	
	char secret[4];
	char guess[4];

	int result[2];
	int cows, bulls;

	intToChar(2471, secret);
	intToChar(2741, guess);

	std::cout << countBulls(secret, guess) << ' ';
	std::cout << countCows(secret, guess);
}

//validation?