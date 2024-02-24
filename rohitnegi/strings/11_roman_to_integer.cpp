#include <iostream>
using namespace std;

int value(char ch)
{
    if (ch == 'I')
    {
        return 1;
    }
    if (ch == 'V')
    {
        return 5;
    }
    if (ch == 'X')
    {
        return 10;
    }
    if (ch == 'L')
    {
        return 50;
    }
    if (ch == 'C')
    {
        return 100;
    }
    if (ch == 'D')
    {
        return 500;
    }
    if (ch == 'M')
    {
        return 1000;
    }
    return 0;
}

int roman_to_integer(string s)
{
    int ans = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        int curr_val = value(s[i]);
        int next_val = value(s[i + 1]);
        if (next_val > curr_val)
        {
            ans -= curr_val;
        }
        else
        {
            ans += curr_val;
        }
    }
    ans += value(s[s.length() - 1]);
    return ans;
}

int main()
{
    cout << roman_to_integer("III") << endl;
    cout << roman_to_integer("LXX") << endl;
    cout << roman_to_integer("CD") << endl;
    cout << roman_to_integer("CCCXXXV") << endl;
    cout << roman_to_integer("XLIII") << endl;
    cout << roman_to_integer("MCCXLVIII") << endl;
    return 0;
}