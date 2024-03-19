#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> ll;
    ll.push_back(1);
    ll.push_back(3);
    ll.push_back(2);
    ll.push_front(4);
    for (int i : ll)
    {
        cout << i << " ";
    }
    cout << endl;
    ll.sort();
    for (int i : ll)
    {
        cout << i << " ";
    }
    return 0;
}