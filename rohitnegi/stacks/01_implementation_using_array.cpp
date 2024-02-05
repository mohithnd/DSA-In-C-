#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int top;
    int size;

public:
    Stack(int size)
    {
        arr = new int[size];
        top = -1;
        this->size = size;
    }
    bool empty()
    {
        return top == -1;
    }
    bool full()
    {
        return top == size - 1;
    }
    void push(int x)
    {
        if (full())
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
        cout << x << " pushed into stack" << endl;
    }
    void pop()
    {
        if (empty())
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        int x = arr[top];
        top--;
        cout << x << " popped from stack" << endl;
    }
    int peek()
    {
        if (empty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top];
    };
    int getSize()
    {
        return top + 1;
    }
    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();
    cout << s.getSize() << endl;
    return 0;
}