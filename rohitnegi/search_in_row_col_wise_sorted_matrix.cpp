#include <iostream>
using namespace std;

bool search1(int arr[5][5], int r, int c, int key)
{
    for (int i = 0; i < r; i++)
    {
        int first = arr[i][0];
        int last = arr[i][c - 1];
        if (key >= first && key <= last)
        {
            int s = 0;
            int e = c - 1;
            while (s <= e)
            {
                int mid = s + (e - s) / 2;
                if (arr[i][mid] == key)
                {
                    return true;
                }
                else if (key < arr[i][mid])
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
        }
    }
    return false;
}

bool search2(int arr[5][5], int r, int c, int key)
{
    int i = 0;
    int j = c - 1;
    while (i <= r - 1 && c >= 0)
    {
        if (arr[i][j] == key)
        {
            return true;
        }
        else if (key < arr[i][j])
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}

int main()
{
    int arr[5][5] = {4, 8, 15, 25, 60, 18, 22, 26, 42, 80, 36, 40, 45, 68, 104, 48, 50, 72, 83, 130, 70, 99, 114, 128, 170};
    int r = 5;
    int c = 5;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int key = 50;
    cout << search1(arr, r, c, key) << endl;
    cout << search2(arr, r, c, key) << endl;
    return 0;
}