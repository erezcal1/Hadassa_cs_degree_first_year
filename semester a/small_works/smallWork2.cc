#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	
	int num1, sum = 0;
	
	cin >> num1;
	
	while (num1 != 0){
		sum += num1;
		cin >> num1;
		
	}
	cout << sum;
	return 0;
}
