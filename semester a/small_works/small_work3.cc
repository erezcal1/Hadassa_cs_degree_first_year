#include <iostream>

using std::cout;
using std::endl;


int main()
{
	for (int i = 1 ; i < 6 ; i++)
	{
		for (int line = 1; line <= i; line++)
			cout << "*" ;
		cout << endl;
	}
	return 0;
}
