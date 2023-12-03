#include <iostream>
using namespace std;

double myPow(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return x;
    }

    bool negative = false;
    if (n < 0)
    {
        negative = true;
        n = n * -1;
    }
    double temp = myPow(x, n / 2);
    double ans = 0;
    if (n % 2 == 0)
    {
        ans = temp * temp;
    }
    else
    {
        ans = temp * temp * x;
    }
    if (negative == false)
    {
        return ans;
    }
    return 1 / ans;
}

int main()
{
    cout << myPow(2, 10) << endl;
    cout << myPow(2, -2) << endl;
    cout << myPow(2, 0) << endl;
    cout << myPow(2, 1) << endl;
    return 0;
}