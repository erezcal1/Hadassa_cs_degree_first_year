/* 
 * written by: erez calderon id: 318993847 login: erezca
 * 
 * This program gets 3 numbers by the user and prints the highest result 
 * that can happen.
 * if there is multiplication first it will not show brackets and will 
 * show if there is addition of numbers first
 * input: 3 numbers by the user
 * output:the hights number that can come for multiplain or adding 
 * 	`	  numbers in order with brackets if needed
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
	int num1, num2, num3, res, maxres, sCase =1;
	
	cin >> num1 >> num2 >> num3 ; // the program gets 3 numbers by the user
	
	// the first and second calculations
	res = num1 * num2 + num3; 
	maxres = num1 * num3 + num2;
	
	
	if (res > maxres){ // check if the result is bigger then max result if so prints case 2 (like wise to all if)
		maxres = res;
		sCase = 2;
	}	
	
	res = num2 * num3 + num1;

	if (res > maxres){
		maxres = res;
		sCase = 3;
	}
	
	res = (num1 + num2) * num3;

	if (res > maxres){
		maxres = res;
		sCase = 4;
	}
	
	res = (num1 + num3) * num2;

	if (res > maxres){
		maxres = res;
		sCase = 5;
	}
	
	res = (num2 + num3) * num1;

	
	if (res > maxres){
		maxres = res;
		sCase = 6;
	}


	// switch section
	switch (sCase)
	{ 
		case 1: cout << num1 << "*" << num3 << "+" << num2 << "=" << maxres;
			break ;
		case 2: cout << num1 << "*" << num2 << "+" << num3 << "=" << maxres;
			break ;
		case 3: cout << num2 << "*" << num3 << "+" << num1 << "=" << maxres; 	
			break ;
		case 4: cout << "(" << num1 << "+" << num2 << ")" << "*" << num3 << "=" << maxres;
			break ;
		case 5: cout << "(" << num1 << "+" << num3 << ")" << "*" << num2 << "=" << maxres;
			break ;
		case 6: cout << "(" << num2 << "+" << num3 << ")" << "*" << num1 << "=" << maxres;
			break ;
	
	}
	
	return 0;
}
