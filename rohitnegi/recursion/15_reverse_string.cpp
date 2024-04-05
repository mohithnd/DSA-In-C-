#include <iostream>
using namespace std;

string reverse(string str, int i, int j)
{
    if (i >= j)
    {
        return str;
    }
    swap(str[i], str[j]);
    return reverse(str, i + 1, j - 1);
}

int main()
{
    string str = "mohit";
    cout << reverse(str, 0, str.length() - 1) << endl;
    return 0;
}