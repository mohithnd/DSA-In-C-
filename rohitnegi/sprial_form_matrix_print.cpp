#include <iostream>
using namespace std;
int main()
{
    int arr[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int r = 4;
    int c = 4;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int n = r * c;
    int cnt = 0;
    int rs = 0;
    int re = r - 1;
    int cs = 0;
    int ce = c - 1;
    while (cnt < n)
    {
        for (int i = cs; i <= ce; i++)
        {
            cout << arr[rs][i] << " ";
            cnt++;
        }
        rs++;
        for (int i = rs; i <= re; i++)
        {
            cout << arr[i][ce] << " ";
            cnt++;
        }
        ce--;
        for (int i = ce; i >= cs; i--)
        {
            cout << arr[re][i] << " ";
            cnt++;
        }
        re--;
        for (int i = re; i >= rs; i--)
        {
            cout << arr[i][cs] << " ";
            cnt++;
        }
        cs++;
    }
    return 0;
}