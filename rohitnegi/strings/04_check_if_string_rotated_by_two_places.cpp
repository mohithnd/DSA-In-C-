#include <iostream>
using namespace std;

string rotate_right_two_places(string s)
{
    string ans = s;
    for (int i = 0; i < s.length(); i++)
    {
        ans[(i + 2) % s.length()] = s[i];
    }
    return ans;
}

string rotate_left_two_places(string s)
{
    string ans = s;
    for (int i = 0; i < s.length(); i++)
    {
        ans[(i - 2 + s.length()) % s.length()] = s[i];
    }
    return ans;
}

bool check(string s1, string s2)
{
    string rotated = rotate_right_two_places(s1);
    if (rotated == s2)
    {
        return true;
    }
    rotated = rotate_left_two_places(s1);
    return rotated == s2;
}

int main()
{
    cout << check("amazon", "azonam") << endl;
    cout << check("leetcode", "deleetco") << endl;
    return 0;
}