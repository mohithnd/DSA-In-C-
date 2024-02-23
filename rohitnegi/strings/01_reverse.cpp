#include <iostream>
using namespace std;

string reverse(string str)
{
    int i = 0;
    int j = str.length() - 1;
    while (i < j)
    {
        swap(str[i], str[j]);
        i++;
        j--;
    }
    return str;
}

int main()
{
    string name = "Mohit";
    cout << name << endl;
    name = reverse(name);
    cout << name << endl;
    return 0;
}