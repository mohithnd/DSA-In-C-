#include <iostream>
using namespace std;

int sum_of_square(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * n + sum_of_square(n - 1);
}

int main()
{
    cout << sum_of_square(5) << endl;
    cout << sum_of_square(10) << endl;
    return 0;
}