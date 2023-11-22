#include <iostream>
using namespace std;

int sqrt(int n)
{
    int s = 1;
    int e = n;
    int ans;
    while (s <= e)
    {
        long long int mid = s + (e - s) / 2;
        if (mid * mid == n)
        {
            ans = mid;
            break;
        }
        else if (mid * mid < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n = 99;
    cout << sqrt(n) << endl;
    return 0;
}