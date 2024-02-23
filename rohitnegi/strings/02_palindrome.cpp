#include <iostream>
using namespace std;

string reverse(string str)
{
    int i = 0;
    int j = str.length() - 1;
    while (i < j)
    {
        swap(str[i], str[j]);
        i++;
        j--;
    }
    return str;
}

bool palindrome(string str)
{
    string rev = reverse(str);
    return rev == str;
}

int main()
{
    cout << palindrome("mohit") << endl;
    cout << palindrome("naman") << endl;
    return 0;
}