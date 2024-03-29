#include <iostream>
#include <vector>
using namespace std;

string reverse(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }
    return s;
}

string longest_prefix_suffix_1(string s)
{
    vector<string> prefs;
    vector<string> suffs;
    int n = s.length();
    for (int i = 1; i < n; i++)
    {
        prefs.push_back(s.substr(0, i));
    }
    for (int i = n - 1; i > 0; i--)
    {
        suffs.insert(suffs.begin(), s.substr(n - i, i));
    }
    string ans;
    for (int i = prefs.size() - 1; i >= 0; i--)
    {
        if (prefs[i] == suffs[i])
        {
            ans = prefs[i];
            break;
        }
    }
    return ans;
}

string longest_prefix_suffix_2(string s)
{
    string ans;
    vector<int> indexes;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[0])
        {
            indexes.push_back(i);
        }
    }
    for (int ind : indexes)
    {
        int i = 0;
        int j = ind;
        bool flag = true;
        while (j < s.length())
        {
            if (s[i] == s[j])
            {
                i++;
                j++;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ans = s.substr(0, s.length() - 1 - ind + 1);
            break;
        }
    }
    return ans;
}

string longest_prefix_suffix_3_kmp_algo(string s)
{
    vector<int> lps(s.size(), 0);
    int pref = 0;
    int suff = 1;
    while (suff < s.size())
    {
        if (s[suff] == s[pref])
        {
            lps[suff] = pref + 1;
            pref++;
            suff++;
        }
        else
        {
            if (pref == 0)
            {
                lps[suff] = 0;
                suff++;
            }
            else
            {
                pref = lps[pref - 1];
            }
        }
    }
    return s.substr(0, lps[s.size() - 1]);
}

int main()
{
    string s = "ABCDEABCD";
    cout << longest_prefix_suffix_1(s) << endl;
    cout << longest_prefix_suffix_2(s) << endl;
    cout << longest_prefix_suffix_3_kmp_algo(s) << endl;
    return 0;
}