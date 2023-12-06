#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(vector<int> arr, int i, int target, vector<int> v, vector<vector<int>> &res)
{
    if (target == 0)
    {
        res.push_back(v);
        return;
    }
    if (i >= arr.size())
    {
        return;
    }
    if (arr[i] <= target)
    {
        v.push_back(arr[i]);
        solve(arr, i, target - arr[i], v, res);
        v.pop_back();
    }
    solve(arr, i + 1, target, v, res);
}

vector<vector<int>> combinationSum(vector<int> arr, int target)
{
    vector<vector<int>> res;
    solve(arr, 0, target, vector<int>(), res);
    for (int i = 0; i < res.size(); i++)
    {
        sort(res[i].begin(), res[i].end());
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> arr = {13, 3, 2, 17};
    vector<vector<int>> res = combinationSum(arr, 14);
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