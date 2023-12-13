#include <iostream>
using namespace std;

void reverse_string(string &s, int i, int j)
{
    if (i >= j)
    {
        return;
    }
    swap(s[i], s[j]);
    reverse_string(s, i + 1, j - 1);
}

int main()
{
    string s;
    // cin >> s;
    getline(cin, s);
    reverse_string(s, 0, s.length() - 1);
    cout << s << endl;
    return 0;
}