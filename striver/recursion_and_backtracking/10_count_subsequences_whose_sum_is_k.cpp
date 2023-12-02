#include <iostream>
#include <vector>
using namespace std;

int count_sequences_sum_k(int *arr, int n, int i, int k, int sum, vector<int> v)
{
    if (i >= n)
    {
        if (sum == k)
        {
            return 1;
        }
        return 0;
    }
    int a = count_sequences_sum_k(arr, n, i + 1, k, sum, v);
    v.push_back(arr[i]);
    int b = count_sequences_sum_k(arr, n, i + 1, k, sum + arr[i], v);
    return a + b;
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = sizeof(arr) / sizeof(int);
    int k = 2;
    cout << count_sequences_sum_k(arr, n, 0, k, 0, vector<int>()) << endl;
    return 0;
}