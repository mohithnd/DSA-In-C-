#include <iostream>
using namespace std;
int main()
{
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int j = 0; j < 4; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < 3; i++)
            {
                cout << arr[i][j] << " ";
            }
        }
        else
        {
            for (int i = 2; i >= 0; i--)
            {
                cout << arr[i][j] << " ";
            }
        }
    }
    return 0;
}