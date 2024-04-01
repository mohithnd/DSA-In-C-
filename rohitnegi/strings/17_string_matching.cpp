#include <iostream>
#include <vector>
using namespace std;

int string_matching_1(string s, string pat)
{
    for (int i = 0; i <= s.length() - pat.length(); i++)
    {
        bool flag = true;
        int j = i;
        for (char ch : pat)
        {
            if (ch != s[j])
            {
                flag = false;
                break;
            }
            j++;
        }
        if (flag)
        {
            return i;
        }
    }
    return -1;
}

vector<int> create_lps_array(string s)
{
    vector<int> lps(s.length(), 0);
    int pref = 0;
    int suff = 1;
    while (suff < s.length())
    {
        if (s[pref] == s[suff])
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
    return lps;
}

int string_matching_2(string txt, string pat)
{
    vector<int> lps = create_lps_array(pat);
    int first = 0;
    int second = 0;
    while (first < txt.size() && second < pat.size())
    {
        if (txt[first] == pat[second])
        {
            first++;
            second++;
        }
        else
        {
            if (second == 0)
            {
                first++;
            }
            else
            {
                second = lps[second - 1];
            }
        }
    }
    if (second == pat.size())
    {
        return first - second;
    }
    return -1;
}

int main()
{
    string txt = "hello";
    string pat = "ll";
    cout << string_matching_1(txt, pat) << endl;
    cout << string_matching_2(txt, pat) << endl;
    return 0;
}