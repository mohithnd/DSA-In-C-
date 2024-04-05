#include <iostream>
using namespace std;

int nth_stair(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    return nth_stair(n - 1) + nth_stair(n - 2);
}

int main()
{
    cout << nth_stair(5) << endl;
    cout << nth_stair(10) << endl;
    return 0;
}