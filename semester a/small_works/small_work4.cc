#include <iostream>

using std::cin;
using std::cout;


int main()
{
    int arr [5], num, counter = 0, i ;

    for (i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    cin >> num;

    for (i = 0; i < 5; i++)
    {
        if (arr [i] == num)
            counter++;
    }
    cout << counter;
    
    return 0;
}