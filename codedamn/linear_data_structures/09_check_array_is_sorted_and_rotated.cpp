#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool check_for_rotated_and_sorted_1(vector<int> arr)
{
    int greater = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            greater++;
        }
    }
    if (arr[arr.size() - 1] > arr[0])
    {
        greater++;
    }
    return greater <= 1;
}

int main()
{
    vector<int> arr = {3, 4, 5, 1, 2};
    cout << check_for_rotated_and_sorted_1(arr) << endl;
    return 0;
}