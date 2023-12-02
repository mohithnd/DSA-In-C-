#include <iostream>
#include <vector>
using namespace std;

void print_all_sub_sequences(int *arr, int n, int i, vector<int> v)
{
    if (i >= n)
    {
        if (v.size() > 0)
        {
            for (int i : v)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }
    print_all_sub_sequences(arr, n, i + 1, v);
    v.push_back(arr[i]);
    print_all_sub_sequences(arr, n, i + 1, v);
}

int main()
{
    int arr[3] = {3, 1, 2};
    print_all_sub_sequences(arr, 3, 0, vector<int>());
    return 0;
}