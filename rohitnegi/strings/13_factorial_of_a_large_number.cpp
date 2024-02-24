#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void factorial(int n)
{
    vector<int> arr = {1};
    for (int i = n; i >= 2; i--)
    {
        int c = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            int sum = arr[j] * i + c;
            c = sum / 10;
            arr[j] = sum % 10;
        }
        while (c)
        {
            arr.push_back(c % 10);
            c = c / 10;
        }
    }
    reverse(arr.begin(), arr.end());
    for (int i : arr)
    {
        cout << i;
    }
    cout << endl;
}

int main()
{
    for (int i = 1; i <= 15; i++)
    {
        cout << i << " - ";
        factorial(i);
    }
    return 0;
}