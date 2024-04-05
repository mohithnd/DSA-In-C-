#include <iostream>
using namespace std;

bool is_palindrome(string str, int i, int j)
{
    if (i >= j)
    {
        return true;
    }
    if (str[i] != str[j])
    {
        return false;
    }
    return is_palindrome(str, i + 1, j - 1);
}

int main()
{
    string str = "naman";
    cout << is_palindrome(str, 0, str.size() - 1) << endl;
    str = "mohit";
    cout << is_palindrome(str, 0, str.size() - 1) << endl;
    return 0;
}