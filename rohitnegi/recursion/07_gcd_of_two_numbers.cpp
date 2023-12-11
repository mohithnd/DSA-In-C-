#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b); // Euclid's algorithm
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << "gcd of " << a << " and " << b << " is: " << gcd(a, b) << endl;
    return 0;
}