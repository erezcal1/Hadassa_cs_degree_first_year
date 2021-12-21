#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip> 

using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::cerr;

const int FILE_LEN = 50;

bool open_files(char file_name[], ifstream &istr);
void sum(ifstream &istr);

int main()
{
	ifstream istr;
	char nums[FILE_LEN];

	cin >> setw(FILE_LEN) >> nums;
	if (!open_files(nums, istr))
	{
		cerr << "Cannot open file" << endl;
		exit (EXIT_FAILURE);
	}
	sum (istr);


	return EXIT_SUCCESS;
}

bool open_files(char nums[], ifstream &istr)
{
	istr.open(nums);
	if (!istr.is_open())
	{
		return false;
	}
	return true;
}

void sum(ifstream &istr)
{
	int sum = 0, num;
	

	while(!istr.eof())
	{
		istr >> num;
		sum += num;
	}
	cout << sum << endl;
}
