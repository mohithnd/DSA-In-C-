#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longest_palindrome_length_1(string s)
{
    vector<int> upper(26, 0);
    vector<int> lower(26, 0);
    for (char ch : s)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            lower[ch - 'a']++;
        }
        else
        {
            upper[ch - 'A']++;
        }
    }
    int even = 0;
    int odd = 0;
    for (int i : lower)
    {
        if (i % 2 == 0)
        {
            even += i;
        }
        else
        {
            even += i - 1;
            odd = 1;
        }
    }
    for (int i : upper)
    {
        if (i % 2 == 0)
        {
            even += i;
        }
        else
        {
            even += i - 1;
            odd = 1;
        }
    }
    return even + odd;
}

int longest_palindrome_length_2(string s)
{
    unordered_map<char, int> m;
    for (char ch : s)
    {
        m[ch]++;
    }
    int even = 0;
    int odd = 0;
    for (auto i : m)
    {
        if (i.second % 2 == 0)
        {
            even += i.second;
        }
        else
        {
            even += i.second - 1;
            odd = 1;
        }
    }
    return odd + even;
}

int main()
{
    string s = "abccccdd";
    cout << longest_palindrome_length_1(s) << endl;
    cout << longest_palindrome_length_2(s) << endl;
    return 0;
}