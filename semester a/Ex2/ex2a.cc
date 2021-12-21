/* 
 * written by: erez calderon id: 318993847 login: erezca
 * 
 * This program prints in one line even and odd numbers in this order
 * And in the second line it prints how much positive numbers, 
 * zero numbers and nagative numbers there is. 
 * input: 4 numbers by the user
 * output: 5 numbers 2 in row 1, 3 in row 2.
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
	int num1, num2, num3, num4, counter1, counter2; 
	cin >> num1 >> num2 >> num3 >> num4; // the user gives muber to the program
	
	counter1 = 0 ;
	counter2 = 0 ;	
	
	if (num1 % 2 == 0) // seeing if the number is even if so it adds to counter1
		counter1 += 1 ;
	else 			  // if not adds to counter2
		counter2 += 1;
		
	if (num2 % 2 == 0)
		counter1 += 1 ;
	else 
		counter2 += 1;
		
	if (num3 % 2 == 0)
		counter1 += 1 ;
	else 
		counter2 += 1;
			
	if (num4 % 2 == 0)
		counter1 += 1 ;
	else 
		counter2 += 1 ;	
	cout << counter1 << " " << counter2 << endl; // the program prints howe much odd and even number there is
	
	counter1 = 0 ;
	counter2 = 0 ;
	
	if (num1 > 0) 		// seing if the number is positive if so it adds to counter 1
		counter1 += 1;
		
	else if (num1 < 0) // if the number is nagative it adds to counter2
		counter2 += 1;
		
	if (num2 > 0)
		counter1 += 1;
		
	else if (num2 < 0)
		counter2 += 1;
		
	if (num3 > 0)
		counter1 += 1;
		
	else if (num3 < 0)
		counter2 += 1;

	if (num4 > 0)
		counter1 += 1;
		
	else if (num4 < 0)
		counter2 += 1;
		

	cout << counter1 << " " << (4 - counter1 - counter2) << " " << counter2 << endl; // the program prints how much positive, 
	                                                                                //zero and negative numbers there is
	return 0;
}
