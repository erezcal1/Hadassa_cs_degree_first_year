#include <iostream>

using std::cout ;
using std::endl ;
using std::cin ;

int main()
{
	int number1, number2 ;
	
	cin >> number1 >> number2 ;
	
	if (number1 % 2 == 0 && number2 % 2 == 0) 
		cout << "both numbers are even" ;
	
	else if (number1 % 2 == 0 || number2 % 2 == 0)
		cout << "one of the number is even the other is odd" ;
	
	else 
		cout << "Both numbers are odd" ;
		
	return 0 ;
}
