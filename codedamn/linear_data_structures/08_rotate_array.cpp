#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<int> rotate_array_1(vector<int> arr, int k)
{
    k = k % arr.size();
    vector<int> ans(arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        ans[(i + k) % arr.size()] = arr[i];
    }
    return ans;
}

vector<int> rotate_array_2(vector<int> arr, int k)
{
    k = k % arr.size();
    while (k--)
    {
        int last = arr[arr.size() - 1];
        for (int i = arr.size() - 1; i >= 1; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = last;
    }
    return arr;
}

void reverse(vector<int> &arr, int s, int e)
{
    while (s < e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

vector<int> rotate_array_3(vector<int> arr, int k)
{
    k = k % arr.size();
    reverse(arr, 0, arr.size() - k - 1);
    reverse(arr, arr.size() - k, arr.size() - 1);
    reverse(arr, 0, arr.size() - 1);
    return arr;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    vector<int> ans = rotate_array_1(arr, 3);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    ans = rotate_array_2(arr, 3);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    ans = rotate_array_3(arr, 3);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}