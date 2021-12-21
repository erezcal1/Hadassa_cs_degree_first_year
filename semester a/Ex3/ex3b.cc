/* 
 * written by: erez calderon id: 318993847 login: erezca
 * 
 * This program finds pairs of numbers from 1-1000 that that maintan num1 ^ 2 + num2 ^2 = num4 ^ 3 
 * and num1 ^ 3 + num2 ^ 3 = num3 ^ 2
 * 
 * output: 2 2
 * 		   128 128
 */

//--------include section-------
#include <iostream>

//------using section------
using std::cout;
using std::endl;

//-------main-------
int main()
{ 
	int num, num2, triNum, dubNum, calOne, calTwo;


	
	for (num = 1; num < 1000 ; num++)//For loop that check num small the 1000 
	{
		for (num2 = 1; num2 < 1000; num2 ++) //For loop that check num2 small the 1000 
		{
			calOne = num * num + num2 * num2; //calculting to make to ruuning time faster
			calTwo = num * num * num + num2 * num2 * num2;

			for (dubNum = 1; calOne >= dubNum * dubNum * dubNum; dubNum++)
			{
				if ((calOne) == (dubNum * dubNum * dubNum))  //calculation number 1
				{
					for (triNum = 1; triNum <= calOne; triNum++)
					{
						if ((calTwo) == (triNum * triNum)) //calcualting number 2
						{
							cout << num << " " << num2 << endl; //cout the numbers
							break;
						}
					}
				}
			}
		}
	}	
	
	return 0; //end of program
}
