/* 
 * written by: erez calderon id: 318993847 login: erezca
 * 
 * This program read id numebr for the user and tell if the id is 
 * real or fake with a smart algoritem.
 * 
 * input: id numebr
 * output: 1 for real, 0 for fake
 */

//--------include section-------
#include <iostream>

//------using section------
using std::cout;
using std::cin;

//-------main-------
int main()
{
    int id, idNum, idLan = 0, sum = 0;

    cin >> id; // the user input the id to check
    
    idNum = id ;
    while (idNum > 0) // counting how much numbers are in the id
    {
        idLan++;
        idNum /= 10;
    }
    if (idLan >= 6 && idLan <= 9) // checking if the id is in the right length for 6 to 9.
    {
        if (idLan == 6 || idLan == 8) // adding 1 to the length if its even
            idLan++;
        for (int i = idLan ; i >= 0; i--) // for loop for the algoritem
        {

            idNum = id % 10;
            id = id / 10;

            if (i % 2 == 0)
            {
                 idNum = 2 * idNum;
                if (idNum >= 10)
                {
                    sum += (idNum % 10) + (idNum / 10);
                }
                else 
                    sum += idNum;
            }
            else 
            {
                sum += idNum;
            }
        }
        if (sum % 10 == 0)//cheking if the sum of the algoritem devide by 10 if so its real if not its fake 
                cout << 1 ;
        else 
                cout << 0 ;
    }
    else
        cout << 0 ;

    return 0;
}

