#include <iostream>
#include <vector>
using namespace std;

class MyStack
{
public:
    int top1;
    int top2;
    int *arr;
    int size;
    MyStack(int n)
    {
        arr = new int[n];
        this->size = n;
        this->top1 = -1;
        this->top2 = n;
    }
    bool full()
    {
        return top1 + 1 == top2;
    }
    void push1(int data)
    {
        if (full())
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        this->top1++;
        this->arr[this->top1] = data;
    }
    void push2(int data)
    {
        if (full())
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        this->top2--;
        this->arr[this->top2] = data;
    }
    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Stack1 Underflow" << endl;
            return;
        }
        top1--;
    }
    void pop2()
    {
        if (top2 == size)
        {
            cout << "Stack2 Underflow" << endl;
            return;
        }
        top2++;
    }
    int peek1()
    {
        if (top1 == -1)
        {
            cout << "Stack1 Underflow" << endl;
            return -1;
        }
        return arr[top1];
    }
    int peek2()
    {
        if (top2 == size)
        {
            cout << "Stack2 Underflow" << endl;
            return -1;
        }
        return arr[top2];
    }
    bool empty1()
    {
        return top1 == -1;
    }
    bool empty2()
    {
        return top2 == size;
    }
    ~MyStack()
    {
        delete[] arr;
    }
};

int main()
{
    MyStack st(100);
    st.push1(2);
    st.push1(3);
    st.push2(4);
    cout << st.peek1() << endl;
    st.pop1();
    cout << st.peek2() << endl;
    st.pop2();
    cout << st.peek2() << endl;
    st.pop2();
    return 0;
}