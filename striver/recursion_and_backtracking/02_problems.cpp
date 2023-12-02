#include <iostream>
using namespace std;

void func(int i, int n)
{
    // TC - O(n)
    // SC - O(n)
    if (i > n)
    {
        return;
    }
    cout << i << " - "
         << "Mohit Agrawal" << endl;
    func(i + 1, n);
}

void func2(int i, int n)
{
    // TC - O(n)
    // SC - O(n)
    if (i > n)
    {
        return;
    }
    cout << i << endl;
    func2(i + 1, n);
}

void func3(int i, int n)
{
    // TC - O(n)
    // SC - O(n)
    if (i < 1)
    {
        return;
    }
    cout << i << endl;
    func3(i - 1, n);
}

void func4(int i, int n)
{
    // TC - O(n)
    // SC - O(n)
    if (i > n)
    {
        return;
    }
    func4(i + 1, n);
    cout << i << endl;
}

void func5(int i, int n)
{
    if (i < 1)
    {
        return;
    }
    func5(i - 1, n);
    cout << i << endl;
}

int main()
{
    int n;
    cin >> n;
    func(1, n);
    cout << endl;
    func2(1, n);
    cout << endl;
    func3(n, n);
    cout << endl;
    func4(1, n);
    cout << endl;
    func5(n, n);
    cout << endl;
    return 0;
}