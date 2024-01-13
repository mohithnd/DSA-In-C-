#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int capacity;
    Stack()
    {
        this->capacity = 5;
        this->arr = new int[this->capacity];
        this->top = -1;
    }
    bool empty()
    {
        if (this->top == -1)
        {
            return true;
        }
        return false;
    }
    bool full()
    {
        if (this->top == this->capacity - 1)
        {
            return true;
        }
        return false;
    }
    void push(int data)
    {
        if (full())
        {
            cout << "Stack Is Full" << endl;
            return;
        }
        this->top++;
        this->arr[this->top] = data;
    }
    void pop()
    {
        if (empty())
        {
            cout << "Stack Is Empty" << endl;
            return;
        }
        this->top--;
    }
    int peek()
    {
        if (empty())
        {
            cout << "Stack Is Empty" << endl;
            return -1;
        }
        return this->arr[this->top];
    }
    int size()
    {
        return this->top + 1;
    }
    ~Stack()
    {
        delete[] this->arr;
    }
};

int main()
{
    Stack st;
    cout << st.size() << endl;
    return 0;
}