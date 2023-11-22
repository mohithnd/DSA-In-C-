#include <iostream>
using namespace std;

bool search1(int arr[4][5], int r, int c, int key)
{
    for (int i = 0; i < r; i++)
    {
        if (key >= arr[i][0] && key <= arr[i][c - 1])
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
            return false;
        }
    }
    return false;
}

bool search2(int arr[4][5], int r, int c, int key)
{
    int s = 0;
    int e = r - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        int lowest = arr[mid][0];
        int highest = arr[mid][c - 1];
        if (key >= lowest && key <= highest)
        {
            int s2 = 0;
            int e2 = c - 1;
            while (s2 <= e2)
            {
                int mid2 = s2 + (e2 - s2) / 2;
                if (arr[mid][mid2] == key)
                {
                    return true;
                }
                else if (key < arr[mid][mid2])
                {
                    e2 = mid2 - 1;
                }
                else
                {
                    s2 = mid2 + 1;
                }
            }
            return false;
        }
        else if (key < lowest)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return false;
}

bool search3(int arr[4][5], int r, int c, int key)
{
    int s = 0;
    int e = r * c - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid / c][mid % c] == key)
        {
            return true;
        }
        else if (key < arr[mid / c][mid % c])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return false;
}

int main()
{
    int arr[4][5] = {2, 6, 10, 14, 18, 20, 24, 27, 29, 38, 47, 52, 78, 93, 102, 108, 111, 200, 218, 320};
    int r = 4;
    int c = 5;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int key = 52;
    cout << search1(arr, r, c, key) << endl;
    cout << search2(arr, r, c, key) << endl;
    cout << search3(arr, r, c, key) << endl;
    return 0;
}