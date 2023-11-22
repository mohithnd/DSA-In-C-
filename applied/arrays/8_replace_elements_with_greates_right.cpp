#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> method1(vector<int> arr)
{
    // O(n^2) time complexity
    // O(1) space complexity
    int max = -1;
    vector<int> ans(arr.size(), 0);
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int max = -1;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] > max)
            {
                max = arr[j];
            }
        }
        ans[i] = max;
    }
    ans[ans.size() - 1] = -1;
    return ans;
}

vector<int> method2(vector<int> arr)
{
    // O(n) time complexity
    // O(1) space complexity
    vector<int> ans(arr.size(), 0);
    int max = -1;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        ans[i] = max;
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return ans;
}

int main()
{
    vector<int> arr;
    arr.push_back(17);
    arr.push_back(18);
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(1);
    print(arr);
    print(method1(arr));
    print(method2(arr));
    return 0;
}