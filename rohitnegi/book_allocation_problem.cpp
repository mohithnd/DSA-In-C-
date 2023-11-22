#include <iostream>
#include <vector>
using namespace std;

bool possible(vector<int> books, int n, int mid, int m)
{
    int studentCount = 1;
    int pageSum = 0;
    for (int i = 0; i < n; i++)
    {
        if ((pageSum + books[i]) <= mid)
        {
            pageSum += books[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m)
            {
                return false;
            }
            if (books[i] > mid)
            {
                return false;
            }
            pageSum = books[i];
        }
    }
    return true;
}

int main()
{
    vector<int> books;
    books.push_back(12);
    books.push_back(34);
    books.push_back(67);
    books.push_back(90);
    int n = books.size();
    int m = 2;
    if (m > n)
    {
        cout << -1;
        return 0;
    }
    int sum = 0;
    for (int i : books)
    {
        sum += i;
    }
    int s = 0;
    int e = sum;
    int ans = 0;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (possible(books, n, mid, m))
        {
            e = mid - 1;
            ans = mid;
        }
        else
        {
            s = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}