#include <iostream>
#include <cmath>


int main(void)
{
	int time1, time2, numberToCheck;
	int hour1, hour2;
	int hourDiff, minutesDiff; 
	double minutes1 = 0, minutes2 = 0, hour1_digit1 = 0, hour1_digit2 = 0, hour2_digit1 = 0, hour2_digit2 = 0;
	bool time24_1 = false, time24_2 = false;
	std::cout << "Enter two integers: ";
	std::cin >> time1 >> time2;

	//Time 1 calculation

	numberToCheck = time1 >> 12; 

	if (numberToCheck == 1)
	{
		time24_1 = true;
	}
	else if (numberToCheck >> 12 == 0)
	{
		time24_1 = false; 
	}
	else
	{
		std::cout << "Time format is wrong" << std::endl; return 0;
	}

	
	numberToCheck *= pow(2, 12);
	time1 = time1 ^ numberToCheck;
	numberToCheck = time1 >> 10;
	hour1_digit1 = numberToCheck; 

	numberToCheck *= pow(2, 10);
	time1 = time1 ^ numberToCheck;
	numberToCheck = time1 >> 6;
	hour1_digit2 = numberToCheck; 

	numberToCheck *= pow(2, 6);
	time1 = time1 ^ numberToCheck;
	numberToCheck = time1;
	minutes1 = numberToCheck; 

	hour1 = hour1_digit1 * 10 + hour1_digit2;		//digit to number convertor


	//Time 2 calculation

	numberToCheck = time2 >> 12;			

	if (numberToCheck == 1)
	{
		time24_2 = true;
	}
	else if (numberToCheck >> 12 == 0)
	{
		time24_2 = false;
	}
	else
	{
		std::cout << "Time format is wrong" << std::endl; return 0;
	}


	numberToCheck *= pow(2, 12);
	time2 = time2 ^ numberToCheck;
	numberToCheck = time2 >> 10;
	hour2_digit1 = numberToCheck;

	numberToCheck *= pow(2, 10);
	time2 = time2 ^ numberToCheck;
	numberToCheck = time2 >> 6;
	hour2_digit2 = numberToCheck;

	numberToCheck *= pow(2, 6);
	time2 = time2 ^ numberToCheck;
	numberToCheck = time2;
	minutes2 = numberToCheck;

	hour2 = hour2_digit1 * 10 + hour2_digit2;			//digit to number convertor

	if (hour1 > 23 || minutes1 > 59 || hour2 > 23 || minutes2 > 59)	//wrong input checks
	{
		std::cout << "Wrong time input" << std::endl; return 0;
	}
	if (hour1 > 12 && !time24_1)
	{
		std::cout << "Wrong time input" << std::endl; return 0;
	}
	if (hour2 > 12 && !time24_2)
	{
		std::cout << "Wrong time input" << std::endl; return 0;
	}

	//Print retults first time
	if (minutes1 < 10)		
	{
		std::cout << hour1 << ":" << "0" << minutes1 << std::endl;
	}
	else
	{
		std::cout << hour1 << ":" << minutes1 << std::endl;
	}

	//Print retults second time
	if (minutes1 < 10)
	{
		std::cout << hour2 << ":" << "0" << minutes2 << std::endl;
	}
	else
	{
		std::cout << hour2 << ":" << minutes2 << std::endl;
	}
	
	//Test cin
	 //std::cin >> hour1 >> minutes1 >> hour2 >> minutes2;  

	if (minutes2 > minutes1 && hour1 != hour2)
	{
		--hour1;
		minutes1 += 60;
	}

	minutesDiff = abs(minutes1 - minutes2); //calculate minutes difference
	hourDiff = abs(hour1 - hour2); //calculate hour difference
		
	if (minutesDiff < 10)
	{
		std::cout << "diff: "<< hourDiff << ':' << '0' << minutesDiff << std::endl;
	}
	else
	{
		std::cout << "diff: " << hourDiff << ':' << minutesDiff << std::endl;
	}

}

