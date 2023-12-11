#include <iostream>
using namespace std;

void print(int *arr, int n)
{
    if (n < 0)
    {
        return;
    }
    print(arr, n - 1);
    cout << arr[n] << " ";
}
void print_reverse(int *arr, int n)
{
    if (n < 0)
    {
        return;
    }
    cout << arr[n] << " ";
    print_reverse(arr, n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    print(arr, n - 1);
    cout << endl;
    print_reverse(arr, n - 1);
    return 0;
}