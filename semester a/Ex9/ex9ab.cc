//---------include section---------
#include <iostream>
#include <cstdlib>

//----------using section----------
using std::cout;
using std::endl;

//---------const section----------
const int SIZE_OF_ARR = 9;

int main()
{
    long num = 987654321;

    main2 (num);
    

    return EXIT_SUCCESS;
}
void main2(long num)
{
    int sum_e = 0, sum_o = 0;

    if(divide_by_11(num, sum_e, sum_o))
    {
        cout << num;
        return;
    }

    change_digit();

    if (dif_nums())
    {
        main2(num);
    }
}

bool divide_by_11(long num, int& sum_o, int& sum_e)
{
    if (num % 2 == 0)
    {
        sum_e += num % 10;
    }
    else
    {
        sum_o += num % 10;
    }
    return divide_by_11(num - 1, sum_o, sum_e);
}

void change_digit(long num)
{
    if (num % 10 < 0)
    {
        
    }
    
}