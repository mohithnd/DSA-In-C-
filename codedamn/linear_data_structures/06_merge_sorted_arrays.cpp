#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<int> merge_sorted_1(vector<int> arr1, int m, vector<int> arr2, int n)
{
    int i = arr1.size() - 1;
    for (int j : arr2)
    {
        arr1[i] = j;
        i--;
    }
    sort(arr1.begin(), arr1.end());
    return arr1;
}

vector<int> merge_sorted_2(vector<int> arr1, int m, vector<int> arr2, int n)
{
    vector<int> ans;
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
        }
        else
        {
            ans.push_back(arr2[j]);
            j++;
        }
    }
    while (i < m)
    {
        ans.push_back(arr1[i]);
        i++;
    }
    while (j < n)
    {
        ans.push_back(arr2[j]);
        j++;
    }
    return ans;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 0, 0, 0};
    vector<int> arr2 = {2, 5, 6};
    vector<int> ans = merge_sorted_1(arr1, 3, arr2, 3);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    ans = merge_sorted_2(arr1, 3, arr2, 3);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}