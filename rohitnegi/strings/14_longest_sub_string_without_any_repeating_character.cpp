#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

void longest_sub_string_1(string str)
{
    string ans = "";
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            unordered_set<char> st;
            bool flag = true;
            for (int k = i; k <= j; k++)
            {
                if (st.find(str[k]) != st.end())
                {
                    flag = false;
                    break;
                }
                st.insert(str[k]);
            }
            if (flag)
            {
                int len = j - i + 1;
                if (len > ans.size())
                {
                    ans = str.substr(i, len);
                }
            }
        }
    }
    cout << ans << endl;
}

void longest_sub_string_2(string str)
{
    string ans = "";
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        unordered_set<char> st;
        for (int j = i; j < n; j++)
        {
            if (st.find(str[j]) != st.end())
            {
                break;
            }
            st.insert(str[j]);
            int len = j - i + 1;
            if (len > ans.size())
            {
                ans = str.substr(i, len);
            }
        }
    }
    cout << ans << endl;
}

void longest_sub_string_3(string str)
{
    string ans = "";
    int n = str.length();
    int i = 0;
    int j = 0;
    unordered_set<char> st;
    while (j < n)
    {
        if (st.find(str[j]) != st.end())
        {
            st.erase(str[i]);
            i++;
        }
        else
        {
            st.insert(str[j]);
            int len = j - i + 1;
            if (len > ans.size())
            {
                ans = str.substr(i, len);
            }
            j++;
        }
    }
    cout << ans << endl;
}

int main()
{
    longest_sub_string_1("abcdecbeadf");
    longest_sub_string_1("ababc");

    longest_sub_string_2("abcdecbeadf");
    longest_sub_string_2("ababc");

    longest_sub_string_3("abcdecbeadf");
    longest_sub_string_3("ababc");
    return 0;
}