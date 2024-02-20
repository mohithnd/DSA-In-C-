#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minimum_number_of_k_consecutive_bit_flips_1(vector<int> arr, int k)
{
    int ans = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            if ((i + k) > n)
            {
                return -1;
            }
            for (int j = i; j < i + k; j++)
            {
                arr[j] = !arr[j];
            }
            ans++;
        }
    }
    return ans;
}

int minimum_number_of_k_consecutive_bit_flips_2(vector<int> arr, int k)
{
    int ans = 0;
    int n = arr.size();
    vector<int> flip_counts(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (flip_counts[i] % 2 == 1)
        {
            arr[i] = !arr[i];
        }
        if (arr[i] == 0)
        {
            if ((i + k) > n)
            {
                return -1;
            }
            arr[i] = !arr[i];
            for (int j = i + 1; j < i + k; j++)
            {
                flip_counts[j]++;
            }
            ans++;
        }
    }
    return ans;
}

int minimum_number_of_k_consecutive_bit_flips_3(vector<int> arr, int k)
{
    int ans = 0;
    int n = arr.size();
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (!q.empty() && q.front() < i)
        {
            q.pop();
        }
        int cnt = q.size();
        if (cnt % 2 == 1)
        {
            arr[i] = !arr[i];
        }
        if (arr[i] == 0)
        {
            if ((i + k) > n)
            {
                return -1;
            }
            arr[i] = !arr[i];
            q.push(i + k - 1);
            ans++;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 1, 0, 1};
    cout << minimum_number_of_k_consecutive_bit_flips_1(arr, 2) << endl;
    cout << minimum_number_of_k_consecutive_bit_flips_2(arr, 2) << endl;
    cout << minimum_number_of_k_consecutive_bit_flips_3(arr, 2) << endl;
    arr = {0, 0, 0, 1, 0, 1, 1, 0};
    cout << minimum_number_of_k_consecutive_bit_flips_1(arr, 3) << endl;
    cout << minimum_number_of_k_consecutive_bit_flips_2(arr, 3) << endl;
    cout << minimum_number_of_k_consecutive_bit_flips_3(arr, 3) << endl;
    return 0;
}