#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int n, unordered_map<int, int> &m)
    {
        if (n < 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return 1;
        }
        if (m.find(n) != m.end())
        {
            return m[n];
        }
        m[n] = solve(n - 1, m) + solve(n - 2, m);
        return m[n];
    }
    int climbStairs(int n)
    {
        unordered_map<int, int> m;
        return solve(n, m);
    }
};
int main()
{
    return 0;
}