#include <iostream>
using namespace std;

void lower_to_upper(string &s, int i)
{
    if (i >= s.length())
    {
        return;
    }
    if (s[i] >= 'a' && s[i] <= 'z')
    {
        s[i] = s[i] - 'a' + 'A';
    }
    lower_to_upper(s, i + 1);
}

int main()
{
    string s;
    // cin >> s;
    getline(cin, s);
    lower_to_upper(s, 0);
    cout << s << endl;
    return 0;
}