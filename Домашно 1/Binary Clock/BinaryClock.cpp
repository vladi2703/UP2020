#include <iostream>
#include <cmath>

int main(void)
{
	int time1, time2;
	int hour1, hour2; 
	double minutes1 = 0, minutes2 = 0, hour1_digit1 = 0, hour1_digit2 = 0, hour2_digit1 = 0, hour2_digit2 = 0;
	bool time24_1 = false, time24_2 = false;
	int diff_h, diff_m; 
	std::cin >> time1 >> time2;
	

	for (int i = 0; i < 12; i++)
	{
		if ((time1 & 1) == 1) 
		{
			
			
			if (i < 5)
			{
				minutes1 += pow(2, i);
			}
			else if (i < 9)
			{
				hour1_digit2 += pow(2,i-6);
			}
			else if (i < 11)
			{
				hour1_digit1 += pow(2, i-10);
			}
			else if (i == 11)
			{
				time24_1 = true;
			}


		}
	

		if ((time2 & 1) == 1)
		{
			if (i <= 5)
			{
				minutes2 += pow(2, i);
			}
			else if (i <= 9)
			{
				hour2_digit2 += pow(2, i - 6);
			}
			else if (i <= 11)
			{
				hour2_digit1 += pow(2, i - 10);
			}
			else if (i == 12)
			{
				time24_2 = true;
			}
		}
		

		time1 = time1 >> 1;
		time2 = time2 >> 1;
	}
	
	 hour1 = 10 * hour1_digit1 + hour1_digit2;
	 hour2 = 10 * hour2_digit1 + hour2_digit2;

	 if (hour1 > 12 && !time24_1)
	 {
		 std::cout << "Wrong input for first hour  ";
		 std::cout << time24_1;

	 }
	 else if (hour1 > 23)
	 {
		 std::cout << "Wrong input for first hour"; 
	 }

	 std::cout << std::endl << hour1 << ':' << minutes1;
	std::cout << std::endl << hour2<< ':' << minutes2;

	diff_h = abs(hour2 - hour1);
	diff_m = abs(minutes1- minutes2);
	std::cout << std::endl << "diff " << diff_h << ':' << diff_m;

}