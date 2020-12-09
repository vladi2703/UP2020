#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double number, diff = 1, diff_1 = 0, answer, answer1, i = 0;
	int initialNumber, intNumber;
	bool isPowerOf2 = false, isPowerOf3 = false, isPowerOf5= false;
	cin >> number;
	initialNumber = number;


	while (number > 2)
	{
		number /= 2;
	}
	intNumber = int(number);
	if (intNumber % 2 == 0)
	{
		isPowerOf2 = true;
	}

	if (isPowerOf2)
	{
		while (diff > diff_1)
		{
			int pow3 = pow(3, i);
			int pow3_1 = pow(3, i + 1);
			diff = abs(pow3 - initialNumber);
			diff_1 = abs(pow3_1 - initialNumber);
			i++;
			answer = i - 1;
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
			int pow5 = pow(5, i);
			int pow5_1 = pow(5, i + 1);
			diff = abs(pow5 - initialNumber);
			diff_1 = abs(pow5_1 - initialNumber);
			i++;
			answer = i - 1;
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