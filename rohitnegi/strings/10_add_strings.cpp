#include <iostream>
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

string sum(string n1, string n2)
{
    int i = n1.length() - 1;
    int j = n2.length() - 1;
    string ans;
    int c = 0;
    while (i >= 0 && j >= 0)
    {
        int sum = c + n1[i] - '0' + n2[j] - '0';
        ans.push_back(sum % 10 + '0');
        c = sum / 10;
        i--;
        j--;
    }
    while (i >= 0)
    {
        int sum = c + n1[i] - '0';
        ans.push_back(sum % 10 + '0');
        c = sum / 10;
        i--;
    }
    while (j >= 0)
    {
        int sum = c + n2[j] - '0';
        ans.push_back(sum % 10 + '0');
        c = sum / 10;
        j--;
    }
    if (c)
    {
        ans.push_back(c + '0');
    }
    return reverse(ans);
}

int main()
{
    string n1 = "26583";
    string n2 = "698";
    cout << sum(n1, n2) << endl;
    return 0;
}