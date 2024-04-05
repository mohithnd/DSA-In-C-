#include <iostream>
using namespace std;

class TwoStack
{
public:
    int *arr;
    int top1;
    int top2;
    int size;
    TwoStack(int s)
    {
        this->arr = new int[s];
        this->size = s;
        this->top1 = -1;
        this->top2 = s;
    }

    bool full()
    {
        if (this->top1 + 1 == this->top2)
        {
            return true;
        }
        return false;
    }

    void push1(int num)
    {
        if (full())
        {
            return;
        }
        this->top1++;
        this->arr[this->top1] = num;
    }

    void push2(int num)
    {
        if (full())
        {
            return;
        }
        this->top2--;
        this->arr[this->top2] = num;
    }

    int pop1()
    {
        if (this->top1 == -1)
        {
            return -1;
        }
        return this->arr[this->top1--];
    }

    int pop2()
    {
        if (this->top2 == this->size)
        {
            return -1;
        }
        return this->arr[this->top2++];
    }

    void print1()
    {
        if (this->top1 == -1)
        {
            cout << "Stack 1 Is Empty" << endl;
            return;
        }
        cout << "Satck 1 - ";
        for (int i = 0; i <= this->top1; i++)
        {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }
    void print2()
    {
        if (this->top2 == this->size)
        {
            cout << "Stack 2 Is Empty" << endl;
            return;
        }
        cout << "Satck 2 - ";
        for (int i = this->size - 1; i >= this->top2; i--)
        {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }

    ~TwoStack()
    {
        delete[] this->arr;
    }
};

int main()
{
    TwoStack st = TwoStack(3);
    st.push1(3);
    st.push2(4);
    st.push1(5);
    st.print1();
    st.print2();
    st.pop1();
    st.pop2();
    st.print1();
    st.print2();
    return 0;
}