#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<int> move_zeroes_1(vector<int> arr)
{
    int non_zero = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            arr[non_zero] = arr[i];
            non_zero++;
        }
    }
    for (int i = non_zero; i < arr.size(); i++)
    {
        arr[i] = 0;
    }
    return arr;
}

vector<int> move_zeroes_2(vector<int> arr)
{
    int non_zero = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[non_zero], arr[i]);
            non_zero++;
        }
    }
    return arr;
}

int main()
{
    vector<int> arr = {0, 1, 0, 3, 12};
    vector<int> ans = move_zeroes_1(arr);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    ans = move_zeroes_2(arr);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}