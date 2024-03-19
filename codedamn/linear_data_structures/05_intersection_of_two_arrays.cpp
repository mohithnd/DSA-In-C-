#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<int> intersection_1(vector<int> arr1, vector<int> arr2)
{
    unordered_set<int> st;
    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr2.size(); j++)
        {
            if (arr1[i] == arr2[j])
            {
                st.insert(arr1[i]);
                break;
            }
        }
    }
    vector<int> ans;
    for (int i : st)
    {
        ans.push_back(i);
    }
    return ans;
}

vector<int> intersection_2(vector<int> arr1, vector<int> arr2)
{
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    int i = 0;
    int j = 0;
    int n = arr1.size();
    int m = arr2.size();
    unordered_set<int> st;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            st.insert(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    vector<int> ans;
    for (int i : st)
    {
        ans.push_back(i);
    }
    return ans;
}

int main()
{
    vector<int> arr1 = {1, 2, 2, 1};
    vector<int> arr2 = {2, 2};
    vector<int> ans = intersection_1(arr1, arr2);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    ans = intersection_2(arr1, arr2);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}