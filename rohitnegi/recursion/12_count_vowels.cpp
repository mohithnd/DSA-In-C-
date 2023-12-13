#include <iostream>
using namespace std;

int count_vowels(string s, int i)
{
    if (i >= s.length())
    {
        return 0;
    }
    int after = count_vowels(s, i + 1);
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
    {
        return after + 1;
    }
    else
    {
        return after;
    }
}

int main()
{
    string s;
    cin >> s;
    cout << count_vowels(s, 0) << endl;
    return 0;
}