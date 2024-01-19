#include <iostream>
using namespace std;

int insert_position(int arr[], int n, int target)
{
}

int main()
{
    int arr[] = {1, 2, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 6;
    cout << insert_position(arr, n, target) << endl;
    return 0;
}