#include <iostream>
using namespace std;

int count_vowels(string str, int i)
{
    if (i >= str.length())
    {
        return 0;
    }
    int curr = 0;
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
    {
        curr = 1;
    }
    return curr + count_vowels(str, i + 1);
}

int main()
{
    string str = "rohit";
    cout << count_vowels(str, 0) << endl;
    return 0;
}