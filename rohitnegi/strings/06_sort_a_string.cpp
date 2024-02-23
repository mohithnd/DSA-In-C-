#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

string sort_1(string s)
{
    string ans;
    vector<int> arr(26, 0);
    for (char ch : s)
    {
        arr[ch - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            ans += 'a' + i;
        }
    }
    return ans;
}

string sort_2(string s)
{
    string ans;
    unordered_map<char, int> m;
    for (char ch : s)
    {
        m[ch]++;
    }
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        for (int i = 0; i < m[ch]; i++)
        {
            ans += ch;
        }
    }
    return ans;
}

int main()
{
    string s = "edcab";
    cout << sort_1(s) << endl;
    cout << sort_2(s) << endl;
    return 0;
}