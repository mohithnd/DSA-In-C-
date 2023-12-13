#include <iostream>
using namespace std;

bool is_palindrome(string s, int i, int j)
{
    if (i >= j)
    {
        return true;
    }
    if (s[i] != s[j])
    {
        return false;
    }
    return is_palindrome(s, i + 1, j - 1);
}

int main()
{
    string s;
    cin >> s;
    cout << is_palindrome(s, 0, s.length() - 1) << endl;
    return 0;
}