#include <iostream>
#include <set>
using namespace std;

bool method1(string sentence)
{
    if (sentence.size() < 26)
    {
        return false;
    }
    int arr[26] = {0};
    for (char ch : sentence)
    {
        arr[ch - 'a'] = 1;
    }
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] == 0)
        {
            return false;
        }
    }
    return true;
}

bool method2(string sentence)
{
    if (sentence.size() < 26)
    {
        return false;
    }
    set<char> s;
    for (char ch : sentence)
    {
        s.insert(ch);
    }
    return s.size() >= 26;
}

int main()
{
    string sentence = "thequickbrownfoxjumpsoverthelazydog";
    cout << method1(sentence) << endl;
    cout << method2(sentence) << endl;
    sentence = "leetcode";
    cout << method1(sentence) << endl;
    cout << method2(sentence) << endl;
    return 0;
}