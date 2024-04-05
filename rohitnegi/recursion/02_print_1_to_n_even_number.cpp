#include <iostream>
using namespace std;

void print_1(int n, int curr)
{
    if (curr > n)
    {
        return;
    }
    cout << curr << " ";
    print_1(n, curr + 2);
}

void print_2(int n)
{
    if (n < 2)
    {
        return;
    }
    print_2(n - 2);
    cout << n << " ";
}

int main()
{
    int n = 11;
    print_1(n, 2);
    cout << endl;
    if (n % 2 == 1)
    {
        n--;
    }
    print_2(n);
    return 0;
}