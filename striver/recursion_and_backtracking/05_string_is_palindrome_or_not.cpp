#include <iostream>
using namespace std;

bool isPalindrome(string str, int l, int r)
{
    if (l >= r)
    {
        return true;
    }
    if (str[l] != str[r])
    {
        return false;
    }
    return isPalindrome(str, l + 1, r - 1);
}

int main()
{
    string str = "madam";
    cout << isPalindrome(str, 0, str.length() - 1) << endl;
    return 0;
}