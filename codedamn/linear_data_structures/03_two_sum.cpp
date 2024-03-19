#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> two_sum_1(vector<int> arr, int target)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

vector<int> two_sum_2(vector<int> arr, int target)
{
    int n = arr.size();
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int target_sum = target - arr[i];
        if (m.find(target_sum) == m.end())
        {
            m[arr[i]] = i;
        }
        else
        {
            return {m[target_sum], i};
        }
    }
    return {-1, -1};
}

int main()
{
    vector<int> arr = {3, 2, 4};
    vector<int> ans = two_sum_1(arr, 6);
    cout << ans[0] << " : " << ans[1] << endl;
    ans = two_sum_2(arr, 6);
    cout << ans[0] << " : " << ans[1] << endl;
    return 0;
}