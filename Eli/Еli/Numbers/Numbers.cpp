#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double number, diff = 1, diff_1 = 0, answer, answer1, i = 0;
	int initialNumber, intNumber;
	bool isPowerOf3 = false, isPowerOf2 = false, isPowerOf7 = false;
	cin >> number;
	initialNumber = number; 
	
	
		while (number > 3)		
		{
			number /= 3;		
		}
		intNumber = int(number);		
	if (intNumber % 3 == 0)
	{
		isPowerOf3 = true;
	}

	if (isPowerOf3)
	{
		while (diff > diff_1)
		{
			int pow2 = pow(2, i);
			int pow2_1 = pow(2, i + 1);
			diff = abs(pow2 - initialNumber);
			diff_1 = abs(pow2_1 - initialNumber);
			i++;
			answer = i-1;
			answer1 = i;
			
		}
		if (diff == diff_1)
		{
			cout << answer << " " << answer1 << endl;
		}
		else
		{
			cout << answer << endl;
		}
	}
	else
	{
		while (diff > diff_1)
		{
			int pow7 = pow(7, i);
			int pow7_1 = pow(7, i + 1);
			diff = abs(pow7 - initialNumber);
			diff_1 = abs(pow7_1 - initialNumber);
			i++;
			answer = i-1;
			answer1 = i;
//			cout << pow7 << " " << pow7_1 << endl;
		}
		
		if (diff == diff_1)
		{
			cout << answer << " " << answer1 << endl;
		}
		else
		{
			cout << answer << endl;
		}
	}


}