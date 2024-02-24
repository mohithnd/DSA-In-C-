#include <iostream>
#include <vector>
using namespace std;

string sort_vowels(string str)
{
    vector<int> upper(26, 0);
    vector<int> lower(26, 0);
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            lower[str[i] - 'a']++;
            str[i] = '#';
        }
        else if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            upper[str[i] - 'A']++;
            str[i] = '#';
        }
    }
    string temp;
    for (int i = 0; i < 26; i++)
    {
        while (upper[i])
        {
            temp += 'A' + i;
            upper[i]--;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        while (lower[i])
        {
            temp += 'a' + i;
            lower[i]--;
        }
    }
    string ans;
    int j = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '#')
        {
            ans += str[i];
        }
        else
        {
            ans += temp[j];
            j++;
        }
    }
    return ans;
}

int main()
{
    cout << sort_vowels("lEetcOde") << endl;
    return 0;
}