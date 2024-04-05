#include <iostream>
#include <unordered_map>
using namespace std;

char first_non_repeating_character(string str)
{
    unordered_map<char, int> m;
    for (char ch : str)
    {
        if (ch == ' ')
        {
            continue;
        }
        m[ch]++;
    }
    char ans;
    for (char ch : str)
    {
        if (ch == ' ')
        {
            continue;
        }
        if (m[ch] == 1)
        {
            ans = ch;
            break;
        }
    }
    return ans;
}

char first_repeating_character(string str)
{
    unordered_map<char, int> m;
    char ans;
    for (char ch : str)
    {
        if (ch == ' ')
        {
            continue;
        }
        m[ch]++;
    }
    for (char ch : str)
    {
        if (ch == ' ')
        {
            continue;
        }
        if (m[ch] > 1)
        {
            ans = ch;
            break;
        }
    }
    return ans;
}

int main()
{
    cout << first_non_repeating_character("a green apple") << endl;
    cout << first_repeating_character("a green apple") << endl;
    return 0;
}