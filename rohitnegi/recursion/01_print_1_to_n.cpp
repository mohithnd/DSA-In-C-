#include <iostream>
using namespace std;

void print_1(int n, int curr)
{
    if (curr > n)
    {
        return;
    }
    cout << curr << " ";
    print_1(n, curr + 1);
}

void print_2(int n)
{
    if (n < 1)
    {
        return;
    }
    print_2(n - 1);
    cout << n << " ";
}

int main()
{
    print_1(5, 1);
    cout << endl;
    print_2(5);
    return 0;
}