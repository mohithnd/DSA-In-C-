#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int> arr, int i, int sum, vector<int> &ans)
{
    if (i == arr.size())
    {
        ans.push_back(sum);
        return;
    }
    solve(arr, i + 1, sum, ans);
    solve(arr, i + 1, sum + arr[i], ans);
}

vector<int> subsetSum(vector<int> arr)
{
    vector<int> ans;
    solve(arr, 0, 0, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    for (int i : subsetSum(arr))
    {
        cout << i << " ";
    }
    return 0;
}