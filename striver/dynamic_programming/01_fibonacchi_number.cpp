#include <iostream>
#include <vector>
using namespace std;

int fib1(int n, vector<int> &dp)
{
    // TC - O(n)
    // SC - O(n)
    // Recursion
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = fib1(n - 1, dp) + fib1(n - 2, dp);
}

void method1(int n)
{

    vector<int> dp(n + 1, -1);
    for (int i = 0; i <= n; i++)
    {
        cout << fib1(i, dp) << endl;
    }
}

void method2(int n)
{
    // TC - O(n)
    // SC - O(n)
    // Tabulization
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    for (int i = 0; i <= n; i++)
    {
        cout << dp[i] << endl;
    }
}

void method3(int n)
{
    // TC - O(n)
    // SC - O(1)
    int second_last = 0;
    int last = 1;
    cout << second_last << endl;
    cout << last << endl;
    for (int i = 2; i <= n; i++)
    {
        int curr = second_last + last;
        second_last = last;
        last = curr;
        cout << curr << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    // method1(n);
    // method2(n);
    method3(n);
    return 0;
}