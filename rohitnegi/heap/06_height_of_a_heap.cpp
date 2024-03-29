#include <iostream>
#include <vector>
using namespace std;

int height_of_heap(vector<int> arr)
{
    int n = arr.size();
    if (n == 1)
    {
        return 1;
    }
    int height = 0;
    while (n > 1)
    {
        height++;
        n = n / 2;
    }
    return height;
}

int main()
{
    vector<int> heap = {1, 3, 6, 5, 9, 8};
    cout << height_of_heap(heap) << endl;
    return 0;
}