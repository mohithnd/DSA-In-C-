#include <iostream>
#include <vector>
using namespace std;

string sort_1(string sentence)
{
    vector<string> arr(10, "");
    string temp = "";
    for (char ch : sentence)
    {
        if (ch >= '1' && ch <= '9')
        {
            arr[ch - '0'] = temp;
            temp = "";
        }
        else if (ch != ' ')
        {
            temp += ch;
        }
    }
    string ans = "";
    for (string s : arr)
    {
        if (s != "")
        {
            ans += s;
            ans += " ";
        }
    }
    ans.pop_back();
    return ans;
}

int main()
{
    string sentence = "is2 sentence4 This1 a3";
    sentence = sort_1(sentence);
    cout << sentence << endl;

    sentence = "Myself2 Me1 I4 and3";
    sentence = sort_1(sentence);
    cout << sentence << endl;
    return 0;
}