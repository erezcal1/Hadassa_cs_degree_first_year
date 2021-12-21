#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

void min_max (int, int, int&, int&);

int main()
{
    int num, num2, min, max;
    for (int i = 0; i < 3; i++)
    {
        cin >> num >> num2;

        min_max (num, num2, min, max);

        cout << min << " " << max << endl;
    }
    

    return EXIT_SUCCESS;
}

void min_max(int num, int num2, int& min, int& max)
{
    if (num < num2)
    {
        min = num;
        max = num2;
    }
    else
    {
        min = num2;
        max = num;
    }
    
}