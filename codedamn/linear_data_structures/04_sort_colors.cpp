#include <iostream>
#include <vector>
using namespace std;

vector<int> sort_colors_1(vector<int> arr)
{
    int zero = 0;
    int one = 0;
    int two = 0;
    for (int i : arr)
    {
        if (i == 0)
        {
            zero++;
        }
        else if (i == 1)
        {
            one++;
        }
        else
        {
            two++;
        }
    }
    arr.clear();
    for (int i = 0; i < zero; i++)
    {
        arr.push_back(0);
    }
    for (int i = 0; i < one; i++)
    {
        arr.push_back(1);
    }
    for (int i = 0; i < two; i++)
    {
        arr.push_back(2);
    }
    return arr;
}

vector<int> sort_colors_2(vector<int> arr)
{
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;
    while (mid <= high)
    {
        if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    return arr;
}

int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    // arr = sort_colors_1(arr);
    arr = sort_colors_2(arr);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}