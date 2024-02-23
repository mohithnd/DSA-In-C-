#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool pangram_1(string s)
{
    if (s.length() < 26)
    {
        return false;
    }
    vector<bool> arr(26, 0);
    for (char ch : s)
    {
        arr[ch - 'a'] = true;
    }
    for (int i : arr)
    {
        if (i == false)
        {
            return false;
        }
    }
    return true;
}

bool pangram_2(string s)
{
    if (s.length() < 26)
    {
        return false;
    }
    unordered_set<char> st;
    for (char ch : s)
    {
        st.insert(ch);
    }
    return st.size() == 26;
}

int main()
{
    string s = "thequickbrownfoxjumpsoverthelazydog";
    cout << pangram_1(s) << endl;
    cout << pangram_2(s) << endl;
    s = "leetcode";
    cout << pangram_1(s) << endl;
    cout << pangram_2(s) << endl;
    return 0;
}