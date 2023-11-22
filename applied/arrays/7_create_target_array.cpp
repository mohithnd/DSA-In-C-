#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> method1(vector<int> nums, vector<int> index)
{
    // O(n) time complexity
    // O(1) space complexity
    vector<int> target;
    for (int i = 0; i < index.size(); i++)
    {
        target.insert(target.begin() + index[i], nums[i]);
    }
    return target;
}

int main()
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    print(nums);
    vector<int> index;
    index.push_back(0);
    index.push_back(1);
    index.push_back(2);
    index.push_back(2);
    index.push_back(1);
    print(index);
    vector<int> target = method1(nums, index);
    print(target);
    return 0;
}