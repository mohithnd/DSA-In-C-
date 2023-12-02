#include <iostream>
using namespace std;

void func1(int n, int sum)
{
    if (n < 1)
    {
        cout << sum << endl;
        return;
    }
    func1(n - 1, sum + n);
}

int func2(int n)
{
    if (n < 1)
    {
        return 0;
    }
    return n + func2(n - 1);
}

int main()
{
    int n;
    cin >> n;
    func1(n, 0);
    cout << func2(n) << endl;
    return 0;
}