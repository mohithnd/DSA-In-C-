#include <iostream>
#include <vector>
using namespace std;

void print_sub_sequences_sum_k(int *arr, int n, int i, int k, int sum, vector<int> v)
{
    if (i >= n)
    {
        if (sum == k)
        {
            for (int i : v)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }
    print_sub_sequences_sum_k(arr, n, i + 1, k, sum, v);
    v.push_back(arr[i]);
    print_sub_sequences_sum_k(arr, n, i + 1, k, sum + arr[i], v);
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = sizeof(arr) / sizeof(int);
    int k = 2;
    print_sub_sequences_sum_k(arr, n, 0, k, 0, vector<int>());
    return 0;
}