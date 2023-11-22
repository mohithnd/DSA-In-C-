#include <iostream>
using namespace std;

class TwoStack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;
    TwoStack(int s)
    {
        this->size = s;
        this->arr = new int[this->size];
        this->top1 = -1;
        this->top2 = this->size;
    }
    void push1(int num)
    {
        if (this->top2 - this->top1 > 1)
        {
            this->top1++;
            this->arr[this->top1] = num;
        }
    }
    void push2(int num)
    {
        if (this->top2 - this->top1 > 1)
        {
            this->top2--;
            this->arr[this->top2] = num;
        }
    }
    int pop1()
    {
        if (this->top1 >= 0)
        {
            int temp = this->arr[this->top1];
            this->top1--;
            return temp;
        }
        return -1;
    }
    int pop2()
    {
        if (this->top2 <= this->size - 1)
        {
            int temp = this->arr[this->top2];
            this->top2++;
            return temp;
        }
        return -1;
    }
};

int main()
{
    TwoStack s(10);
    s.push1(1);
    s.push1(2);
    s.push1(3);
    s.push2(4);
    s.push2(5);
    s.push2(6);
    s.pop1();
    s.pop2();
    for (int i = 0; i < s.size; i++)
    {
        cout << s.arr[i] << " ";
    }
    return 0;
}