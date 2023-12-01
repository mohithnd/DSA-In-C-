#include <iostream>
#include <vector>
using namespace std;

int method1(int n, vector<int> &dp)
{
    // TC - O(n)
    // SC - O(n)
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = method1(n - 1, dp) + method1(n - 2, dp);
}

int method2(int n, vector<int> &dp)
{
    // TC - O(n)
    // SC - O(n)
    dp[0] = 1;
    dp[1] = 1;
    if (n == 0 || n == 1)
    {
        return dp[n];
    }
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int method3(int n)
{
    // TC - O(n)
    // SC - O(1)
    if (n == 0 || n == 1)
    {
        return 1;
    }
    int s_last = 1;
    int last = 1;
    int curr = 0;
    for (int i = 2; i <= n; i++)
    {
        curr = s_last + last;
        s_last = last;
        last = curr;
    }
    return curr;
}

int main()
{
    int n;
    cin >> n;
    // vector<int> dp(n + 1, -1);
    // cout << method1(n, dp) << endl;
    // vector<int> dp(n + 1, 0);
    // cout << method2(n, dp) << endl;
    cout << method3(n) << endl;
    return 0;
}