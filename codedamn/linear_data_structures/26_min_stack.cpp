#include <iostream>
#include <stack>
using namespace std;

class MinStack1
{
public:
    stack<int> s;
    stack<int> min;

    void push(int data)
    {
        s.push(data);
        if (min.empty())
        {
            min.push(data);
        }
        else
        {
            if (data < min.top())
            {
                min.push(data);
            }
            else
            {
                min.push(min.top());
            }
        }
    }

    int pop()
    {
        if (s.empty())
        {
            return -1;
        }
        int data = s.top();
        s.pop();
        min.pop();
        return data;
    }

    int get_min()
    {
        if (s.empty())
        {
            return -1;
        }
        return min.top();
    }
};

class MinStack2
{
public:
    stack<int> s;
    int min_ele;

    void push(int data)
    {
        if (s.empty())
        {
            s.push(data);
            min_ele = data;
        }
        else if (data >= min_ele)
        {
            s.push(data);
        }
        else
        {
            s.push(2 * data - min_ele);
            min_ele = data;
        }
    }

    int pop()
    {
        if (s.empty())
        {
            return -1;
        }
        int data = s.top();
        s.pop();
        if (data >= min_ele)
        {
            return data;
        }
        int val = min_ele;
        min_ele = 2 * min_ele - data;
        return val;
    }

    int get_min()
    {
        if (s.empty())
        {
            return -1;
        }
        return min_ele;
    }
};

int main()
{
    MinStack2 ms;
    ms.push(2);
    ms.push(3);
    ms.pop();
    cout << ms.get_min() << endl;
    ms.push(1);
    cout << ms.get_min() << endl;
    return 0;
}