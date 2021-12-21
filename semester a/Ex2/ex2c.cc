/* 
 * written by: erez calderon id: 318993847 login: erezca
 * 
 * This program gets a day a month and a year in nnumbers and prints it date first 
 * with the right addition then the month in words and then the year 
 * it will print until the year 3000. With the right dates
 * input: day, month and year
 * output: 
*/

//--------include section-------
#include <iostream>


//------using section------
using std::cout;
using std::cin;


//-------main section-------
int main ()
{
	int day, month, year ;
	cin >> day >> month >> year ; // input
	
	if ((day >= 1 && month >= 1 && month <= 12) && (year > 0 && year <= 3000))//checking months that get to 31 days
	{ 
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 )
		{
			if (day <= 31) 
			{
				if (day % 10 == 1 && day != 11)
					cout << day << "st ";
				else if (day % 10 == 2 && day != 12)
					cout << day << "nd ";
				else if (day % 10 == 3 && day != 13)
					cout << day << "rd ";
				else 
					cout << day << "th ";
			}
		}	
		else if (month == 4 || month == 6 || month == 9 || month == 11 )//checking months that get to 30 days
		{  
			if (day <= 30)
			{
				if (day % 10 == 1 && day != 11)
					cout << day << "st ";
				else if (day % 10 == 2 && day != 12)
					cout << day << "nd ";
				else if (day % 10 == 3 && day != 13)
					cout << day << "rd ";
				else 
					cout << day << "th ";
			} 
		}
		else if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))//checking february month
		{  
			if (day <= 29)
			{
				if (day % 10 == 1 && day != 11)
					cout << day << "st ";
				else if (day % 10 == 2 && day != 12)
					cout << day << "nd ";
				else if (day % 10 == 3 && day != 13)
					cout << day << "rd ";
				else
					cout << day << "th ";
			} 
		}
		else if (day <= 28)
		{
			if (day % 10 == 1 && day != 11)
				cout << day << "st ";
			else if (day % 10 == 2 && day != 12)
				cout << day << "nd ";
			else if (day % 10 == 3 && day != 13)
				cout << day << "rd ";
			else
				cout << day << "th ";
		}
		else 
			return -123;

			
	// switch section
		switch (month) 
		{
			case 1: cout << " January " << year;
				break;
			case 2: cout << " February " << year;
				break;
			case 3: cout << " March " << year;
				break;
			case 4: cout << " April " << year;
				break;
			case 5: cout << " May " << year;
				break;
			case 6: cout << " June " << year;
				break;
			case 7: cout << " July " << year;
				break;
			case 8: cout << " August " << year;
				break;
			case 9: cout << " September " << year;
				break;
			case 10: cout << " October " << year;
				break;
			case 11: cout << " November " << year;
				break;
			case 12: cout << " December " << year;
				break;
	
	
		}
	}
	return 0; //end of program

}
	
