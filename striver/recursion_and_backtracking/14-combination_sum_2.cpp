#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(vector<int> arr, int i, int target, vector<int> v, vector<vector<int>> &res)
{
    if (target == 0)
    {
        bool flag = false;
        for (auto i : res)
        {
            if (i == v)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            res.push_back(v);
        }
        return;
    }
    if (i >= arr.size())
    {
        return;
    }
    if (arr[i] <= target)
    {
        v.push_back(arr[i]);
        solve(arr, i + 1, target - arr[i], v, res);
        v.pop_back();
    }
    solve(arr, i + 1, target, v, res);
}

vector<vector<int>> combinationSum2(vector<int> arr, int target)
{
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    solve(arr, 0, target, vector<int>(), res);
    return res;
}

int main()
{
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> res = combinationSum2(arr, 8);
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}