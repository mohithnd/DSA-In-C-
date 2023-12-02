#include <iostream>
#include <vector>
using namespace std;

void print_one_sub_sequences_sum_k(int *arr, int n, int i, int k, int sum, vector<int> v, bool &flag)
{
    if (i >= n)
    {
        if (sum == k && flag == false)
        {
            for (int i : v)
            {
                cout << i << " ";
            }
            cout << endl;
            flag = true;
        }
        return;
    }
    if (flag == false)
    {
        print_one_sub_sequences_sum_k(arr, n, i + 1, k, sum, v, flag);
    }
    if (flag == false)
    {
        v.push_back(arr[i]);
        print_one_sub_sequences_sum_k(arr, n, i + 1, k, sum + arr[i], v, flag);
    }
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = sizeof(arr) / sizeof(int);
    int k = 2;
    bool flag = false;
    print_one_sub_sequences_sum_k(arr, n, 0, k, 0, vector<int>(), flag);
    return 0;
}