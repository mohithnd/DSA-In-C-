#include <iostream>
using namespace std;

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int ans = fib(n - 1) + fib(n - 2);
    return ans;
}

int main()
{
    cout << fib(5) << endl;
    cout << fib(10) << endl;
    return 0;
}