#include <iostream>
using namespace std;

int sum_of_square_of_n_numbers(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n * n + sum_of_square_of_n_numbers(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << "Sum of square of " << n << " numbers is: " << sum_of_square_of_n_numbers(n) << endl;
    return 0;
}