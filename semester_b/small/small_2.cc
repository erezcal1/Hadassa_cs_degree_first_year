#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip> 

using std::ifstream;
using std::ofstream;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::cerr;

const int FILE_LEN = 50;

bool open_files(char nums[], char print[], ofstream &ostr, ifstream &istr);
int sum(ifstream &istr);
void close_files(ifstream& istr, ofstream& ostr);

int main()
{
	unsigned summing;
	ifstream istr;
	ofstream ostr;
	char nums[FILE_LEN], print[FILE_LEN];

	cin >> setw(FILE_LEN) >> nums;
	cin >> setw(FILE_LEN) >> print;
	
	if (!open_files(nums, print, ostr, istr))
	{
		cerr << "Cannot open one of the files" << endl;
		exit (EXIT_FAILURE);
	}
	summing = sum (istr);

	ostr << summing << endl;
    cout << summing << endl;

	close_files(istr, ostr);

	return EXIT_SUCCESS;
}

bool open_files(char nums[], char print[], ofstream &ostr, ifstream &istr)
{
	istr.open(nums);
	if (!istr.is_open())
	{
		return false;
	}
	
	ostr.open(print);
	if (!ostr.is_open())
	{
		return false;
	}
	return true;
}

int sum(ifstream &istr)
{
	int sum = 0, num;
	

	while(!istr.eof())
	{
		istr >> num;
		sum += num;
	}
	return sum;
}

void close_files(ifstream& istr, ofstream& ostr)
{
	istr.close();
	ostr.close();
}
