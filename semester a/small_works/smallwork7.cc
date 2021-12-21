#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;

const int N = 2;
const int M = 3;

void read_data (int arr[N][M]);
void sum (int arr[N][M]);

int main()
{
    int arr[N][M];
    read_data (arr);
    sum (arr);

    
    return EXIT_SUCCESS;
}
void read_data (int arr[N][M])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
}
void sum (int arr[N][M])
{
    int row, col, sum_mat = 0;
    for (int i = 0; i < N; i++)
    {
        row  = 0;
        for (int j = 0; j < M; j++)
        {
            row +=arr[i][j];
        }  
        sum_mat += row;
        cout << row << " ";
    }
    for (int i = 0; i < M; i++)
    {
        col = 0;
        for (int j = 0; j < N; j++)
        {
            col += arr[j][i];
        }
        cout << col << " ";
    }
    cout << sum_mat;
}
