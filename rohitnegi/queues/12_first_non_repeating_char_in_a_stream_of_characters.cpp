#include <iostream>
#include <queue>
#include <map>
using namespace std;

string first_non_repeating_char(string a)
{
    string b = "";
    vector<int> repeated(26, 0);
    queue<char> q;
    for (int i = 0; i < a.length(); i++)
    {
        repeated[a[i] - 'a']++;
        if (repeated[a[i] - 'a'] == 1)
        {
            q.push(a[i]);
        }
        while (!q.empty() && repeated[q.front() - 'a'] > 1)
        {
            q.pop();
        }
        if (q.empty())
        {
            b += '#';
        }
        else
        {
            b += q.front();
        }
    }
    return b;
}

int main()
{
    string a = "ababdc";
    cout << first_non_repeating_char(a) << endl;
    a = "yewaahkpuo";
    cout << first_non_repeating_char(a) << endl;
    return 0;
}