#include <iostream>
using namespace std;

string lower_to_upper(string str, int i)
{
    if (i == str.size())
    {
        return str;
    }
    str[i] = str[i] - 'a' + 'A';
    return lower_to_upper(str, i + 1);
}

int main()
{
    string str = "mohit";
    cout << lower_to_upper(str, 0) << endl;
    return 0;
}