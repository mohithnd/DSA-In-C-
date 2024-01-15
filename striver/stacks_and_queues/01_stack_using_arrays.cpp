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
    void print_stack()
    {
        for (int i = 0; i <= this->top; i++)
        {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }
    ~Stack()
    {
        delete[] this->arr;
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.pop();
    st.pop();
    st.print_stack();
    cout << st.size() << endl;
    return 0;
}