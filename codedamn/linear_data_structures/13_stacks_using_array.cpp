#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int size;
    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        this->arr = new int[size];
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
        if (this->top == this->size - 1)
        {
            return true;
        }
        return false;
    }

    void push(int data)
    {
        if (full())
        {
            cout << "Stack Overflow, Cannot Push" << endl;
            return;
        }
        this->top++;
        this->arr[this->top] = data;
    }

    void pop()
    {
        if (empty())
        {
            cout << "Stack Underflow, Cannot Pop" << endl;
            return;
        }
        this->top--;
    }

    int peek()
    {
        if (empty())
        {
            cout << "Stack Underflow, Cannot Peek" << endl;
            return -1;
        }
        return this->arr[this->top];
    }

    void print()
    {
        if (empty())
        {
            cout << "Stack Is Empty" << endl;
            return;
        }
        for (int i = 0; i <= this->top; i++)
        {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }

    int get_size()
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
    Stack st(5);
    st.print();
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.print();
    cout << st.peek() << endl;
    st.pop();
    st.pop();
    st.print();
    cout << st.get_size() << endl;
    return 0;
}