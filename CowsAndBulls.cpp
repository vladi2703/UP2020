#include <iostream>
#include <stdio.h>
#include <stdlib.h>     
#include <time.h>
#include <thread>        

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
void printArr(int* arr, int size, int* nonZeroEl)
{
	for (int i = 0; i < size; i++)
	{
		if(arr[i] != 0)
		{ 
			std::cout << arr[i] << ' ';
			*nonZeroEl += 1;
		}
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
void eliminateImpossibleGuess(int* arr, char* secret, int secretCows, int secretBulls)
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
		if (guessCows != secretCows || guessBulls != secretBulls)
		{
			arr[i] = 0;
		}
	}
}
int randomGuess(int* arr)
{
	int guess;
	do
	{
		guess = rand() % allNumbers;
	} while (arr[guess] == 0);
	
	return arr[guess]; 
}
void getResult(int* cows, int* bulls, const int* result)
{
	*bulls = result[0];
	*cows = result[1];
}
void programataNaAsistentite(int* result, char* realSecret, char* guess)
{
	result[0] = countBulls(realSecret, guess);
	result[1] = countBulls(realSecret, guess);
}
const int* tryGuess(int number)
{

	int result[2];
	int realSecretNum = 1234;
	char realSecret[4];
	char numberChar[4];
	intToChar(realSecretNum, realSecret);
	intToChar(number, numberChar);
	result[0] = countBulls(realSecret, numberChar);
	result[1] = countCows(realSecret, numberChar);
	return result; 

}
int main()
{
	srand(time(NULL));

	int possibleGuess[allNumbers];
	initializePossibleGuesses(possibleGuess);
	int countOfGuesses = 0; 
	int turns = 0;

	char secret[4];
	char guess[4];
	char realSecret[4];

	const int* result;
	int cows, bulls;
	int secretNum;
	int guessNum;
	
	secretNum = randomGuess(possibleGuess);
	intToChar(secretNum, guess);
	
	
	do
	{
		secretNum = randomGuess(possibleGuess);
		result = tryGuess(secretNum);
		bulls = result[0];
		cows = result[1];
		// getResult(&cows, &bulls, result);
		intToChar(secretNum, secret);
		eliminateImpossibleGuess(possibleGuess, secret, cows, bulls);
		turns++;
	} while (bulls != 4);
	printArr(possibleGuess, allNumbers, &countOfGuesses); 
	std::cout << "Count of turns: "<< turns;
}

//validation?
/*
1. first guess -> randomGuess(possibleGuess) 
2. int* result = tryGuess(fistGuess) 
3. getResult(result, cows, bulls);
4. intToChar(firstGuess);
5. eliminateImpossibleGuess(possibleGuess, secret, cows, bulls);



*/