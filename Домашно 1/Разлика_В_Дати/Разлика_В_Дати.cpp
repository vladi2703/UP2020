#include <iostream>

int main()
{
	unsigned int day1, month1, year1;
	int hour1, minutes1, seconds1;
	unsigned int day2, month2, year2;
	int hour2, minutes2, seconds2;
	int dayDiff, hourDiff, minutesDiff, secondsDiff;
	unsigned int maxDay1, maxDay2;
	unsigned int allYears, allLeapYears;
	int daySum1, daySum2, secondsPast1, secondsPast2;
	char dummy;
	bool isLeapYear1 = false, isLeapYear2 = false;

	std::cin >> day1 >> dummy >> month1 >> dummy >> year1 >> hour1 >> dummy >> minutes1 >> dummy >> seconds1;
	std::cin >> day2 >> dummy >> month2 >> dummy >> year2 >> hour2 >> dummy >> minutes2 >> dummy >> seconds2;

	switch (month1)
	{
	case 1: maxDay1 = 31;
		break;
	case 2: maxDay1 = 29;
		break;
	case 3: maxDay1 = 31;
		break;
	case 4: maxDay1 = 30;
		break;
	case 5: maxDay1 = 31;
		break;
	case 6: maxDay1 = 30;
		break;
	case 7: maxDay1 = 31;
		break;
	case 8: maxDay1 = 31;
		break;
	case 9: maxDay1 = 30;
		break;
	case 10: maxDay1 = 31;
		break;
	case 11: maxDay1 = 30;
		break;
	case 12: maxDay1 = 31;
		break;
	default: std::cout << "Invalid date/time";
		return 0;
		break;
	}
	switch (month2)
	{
	case 1: maxDay2 = 31;
		break;
	case 2: maxDay2 = 29;
		break;
	case 3: maxDay2 = 31;
		break;
	case 4: maxDay2 = 30;
		break;
	case 5: maxDay2 = 31;
		break;
	case 6: maxDay2 = 30;
		break;
	case 7: maxDay2 = 31;
		break;
	case 8: maxDay2 = 31;
		break;
	case 9: maxDay2 = 30;
		break;
	case 10: maxDay2 = 31;
		break;
	case 11: maxDay2 = 30;
		break;
	case 12: maxDay2 = 31;
		break;
	default: std::cout << "Invalid date/time";
		return 0;
		break;
	}

	// Leap year check date1
	if (year1 % 400 == 0)
	{
		isLeapYear1 = true;
	}
	else if (year1 % 4 == 0 && year1 % 100 != 0)
	{
		isLeapYear1 = true;
	}
	// Leap year check date2
	if (year2 % 400 == 0)
	{
		isLeapYear2 = true;
	}
	else if (year2 % 4 == 0 && year2 % 100 != 0)
	{
		isLeapYear2 = true;
	}

	if (!isLeapYear1 && month1 == 2)
	{
		maxDay1--;
	}
	if (!isLeapYear2 && month2 == 2)
	{
		maxDay2--;
	}

	if (day1 > maxDay1 || day2 > maxDay2  || year1 < 0 || year2 < 0 || year1 > 9999 
		|| year2 > 9999 || hour1 < 0 || hour1 > 23 || hour2 < 0 || hour2 > 23 
		|| minutes1 < 0 || minutes1 > 59 || minutes2 < 0 || minutes2 > 59
		|| seconds1 < 0 || seconds1 > 59 || seconds2 < 0 || seconds2 > 59)
	{
		std::cout << "Invalid date/time";
		return 0;
	}

	


	//leap years until date1
	allLeapYears = year1;	//all the years we should check if leap
	allYears = year1;
	if (month1 < 2)
	{
		allLeapYears--; 
	}
	//every 4th is leap 
	allLeapYears /= 4;
	//every 100th isn't
	allLeapYears -= allYears/ 100;
	//every 400th is leap
	allLeapYears += allYears/400; 

	//days until date1

	switch (month1)
	{
	case 1: daySum1 = year1 * 365 + allLeapYears + day1;
		break;
	case 2: daySum1 = year1 * 365 + allLeapYears + day1 + 31;	//Whole January is over
		break;
	case 3: daySum1 = year1 * 365 + allLeapYears + day1 + 31 + 28;	//Whole January & February is over and so on...
		if (isLeapYear1)
		{
			daySum1++;
		}
		break;
	case 4: daySum1 = year1 * 365 + allLeapYears + day1 + 31 + 28 + 31;
		break;
	case 5: daySum1 = year1 * 365 + allLeapYears + day1 + 31 + 28 + 31 + 30;
		break;
	case 6: daySum1 = year1 * 365 + allLeapYears + day1 + 31 + 28 + 31 + 30 + 31;
		break;
	case 7:daySum1 = year1 * 365 + allLeapYears + day1 + 31 + 28 + 31 + 30 + 31 + 30;
		break;
	case 8: daySum1 = year1 * 365 + allLeapYears + day1 + 31 + 28 + 31 + 30 + 31 + 30 + 31;
		break;
	case 9: daySum1 = year1 * 365 + allLeapYears + day1 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
		break;
	case 10: daySum1 = year1 * 365 + allLeapYears + day1 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
		break;
	case 11: daySum1 = year1 * 365 + allLeapYears + day1 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
		break;
	case 12: daySum1 = year1 * 365 + allLeapYears + day1 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30; 
		break;
	default: std::cout << "Invalid date/time";
		return 0;
		break;
	}

	//leap years until date1
	allLeapYears = year2;	//all the years we should check if leap
	allYears = year2;

	if (month2 < 2)
	{
		allLeapYears--;
	}
	//every 4th is leap 
	allLeapYears /= 4;
	//every 100th isn't
	allLeapYears -= allYears / 100;
	//every 400th is leap
	allLeapYears += allYears/400;

	//days until date2

	switch (month2)
	{
	case 1: daySum2 = year2 * 365 + allLeapYears + day2;
		break;
	case 2: daySum2 = year2 * 365 + allLeapYears + day2 + 31;	//Whole January is over
		break;
	case 3: daySum2 = year2 * 365 + allLeapYears + day2 + 31 + 28;	//Whole January & February is over and so on...
		if (isLeapYear2)
		{
			daySum2++;
		}
		break;
	case 4: daySum2 = year2 * 365 + allLeapYears + day2 + 31 + 28 + 31;
		break;
	case 5: daySum2 = year2 * 365 + allLeapYears + day2 + 31 + 28 + 31 + 30;
		break;
	case 6: daySum2 = year2 * 365 + allLeapYears + day2 + 31 + 28 + 31 + 30 + 31;
		break;
	case 7:daySum2 = year2 * 365 + allLeapYears + day2 + 31 + 28 + 31 + 30 + 31 + 30;
		break;
	case 8: daySum2 = year2 * 365 + allLeapYears + day2 + 31 + 28 + 31 + 30 + 31 + 30 + 31;
		break;
	case 9: daySum2 = year2 * 365 + allLeapYears + day2 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
		break;
	case 10: daySum2 = year2 * 365 + allLeapYears + day2 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
		break;
	case 11: daySum2 = year2 * 365 + allLeapYears + day2 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
		break;
	case 12: daySum2 = year2 * 365 + allLeapYears + day2 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30; 
		break;
	default: "Invalid date/time";
		return 0;
		break;
	}

	if (daySum1 > daySum2)
	{
		if (seconds1 < seconds2 && minutes1 != minutes2)
		{
			--minutes1;
			seconds1 += 60;
		}
		if (minutes1 < minutes2 && hour1 != hour2)
		{
			--hour1;
			minutes1 += 60;
		}
		if (hour1 < hour2 && day1 != day2)
		{
			--daySum1;
			hour1 += 24;
		}
	}
	else
	{
		if (seconds1 > seconds2 && minutes1 != minutes2)
		{
			--minutes2;
			seconds2 += 60;
		}
		if (minutes1 > minutes2 && hour1 != hour2)
		{
			--hour2;
			minutes2 += 60;
		}
		if (hour1 > hour2 && day1 != day2)
		{
			--daySum2;
			hour2 += 24;
		}
	}
	
	if (month1 == 2 && day1 != 29)
	{
		daySum1--;
	}
	if (month2 == 2 && day2 != 29)
	{
		daySum2--;
	}
	secondsDiff = abs(seconds2 - seconds1);
	minutesDiff = abs(minutes2 - minutes1);
	hourDiff = abs(hour2 - hour1);
	dayDiff = abs(daySum2 - daySum1);
	
	if (dayDiff != 0)
	{
		std::cout << dayDiff << " - ";
	}
	//leading zeros
	if (hourDiff < 10)
		std::cout << '0' << hourDiff << ':';
	else
		std::cout << hourDiff << ':';
	
	if (minutesDiff < 10)
		std::cout << '0' << minutesDiff << ':';
	else
		std::cout << minutesDiff << ':';
	
	if (secondsDiff < 10)
		std::cout << '0' << secondsDiff;
	else
		std::cout << secondsDiff;
	
	
	


	
	
	
	
	return 0;
}