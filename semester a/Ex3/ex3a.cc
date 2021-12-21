/* 
 * written by: erez calderon id: 318993847 login: erezca
 * 
 * This program read numbers from the user until it gets 0.
 * It print in the first row how mcuh values it got and the average of all of them.
 * And in the second row it print how mcuh positive and negative numbers there is in that order.
 * 
 * input: number until zero
 * output: how much numebr it got , the average
 * 		   positive numbers , nagative numbers
*/


//--------include section-------
#include <iostream>


//------using section------
using std::cout;
using std::endl;
using std::cin;

//-------main-------
int main()
{
	int posNum = 0, negNum = 0, value = 0 ;
	double num, avg ;
	
	cin >> num; // the user gives numebrs until zero
	
	while (num != 0)
	{
		avg += num; 
		value++;// adding numebrs to the value
		
		if (num > 0)
			posNum++;// adding numebrs to the positive
		else 
			negNum++;// same but with negative
		cin >> num;
	}
	
	
	if (value > 0)
	{ // cout section
	cout << value << " " << avg / value << endl;
	cout << posNum << " " << negNum;
	}
	
	return 0;//end of the program
}
