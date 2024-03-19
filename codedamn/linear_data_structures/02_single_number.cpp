#include <iostream>
#include <vector>
using namespace std;

int single_number_1(vector<int> arr)
{
    int ans = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                cnt++;
            }
        }
        if (cnt == 1)
        {
            ans = arr[i];
            break;
        }
    }
    return ans;
}

int single_number_2(vector<int> arr)
{
    int ans = 0;
    for (int i : arr)
    {
        ans = ans ^ i;
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
    cout << single_number_1(arr) << endl;
    cout << single_number_2(arr) << endl;
    return 0;
}