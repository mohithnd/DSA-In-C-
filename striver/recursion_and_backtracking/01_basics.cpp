#include <iostream>
using namespace std;

void f(int cnt)
{
    if (cnt == 100)
    {
        return;
    }
    cout << cnt << endl;
    cnt++;
    f(cnt);
}

int main()
{
    f(0);
    return 0;
}