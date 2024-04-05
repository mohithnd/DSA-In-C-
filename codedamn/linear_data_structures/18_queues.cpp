#include <iostream>
using namespace std;

class Queue
{
public:
    int *arr;
    int size;
    int f;
    int r;
    Queue(int size)
    {
        this->size = size;
        this->arr = new int[size];
        this->f = -1;
        this->r = -1;
    }

    bool empty()
    {
        if (this->f == -1 && this->r == -1)
        {
            return true;
        }
        return false;
    }

    bool full()
    {
        if ((this->r + 1) % this->size == this->f)
        {
            return true;
        }
        return false;
    }

    void push(int data)
    {
        if (full())
        {
            cout << "Queue Is Full, Cannot Insert" << endl;
            return;
        }
        if (empty())
        {
            this->f = this->r = 0;
            this->arr[0] = data;
            return;
        }
        this->r++;
        this->r = this->r % this->size;
        this->arr[this->r] = data;
    }

    void print()
    {
        if (empty())
        {
            cout << "Queue Is Empty" << endl;
            return;
        }
        int i = this->f;
        while (i != this->r)
        {
            cout << this->arr[i] << " ";
            i++;
            i = i % this->size;
        }
        cout << this->arr[i];
        cout << endl;
    }

    void pop()
    {
        if (empty())
        {
            cout << "Queue Is Empty, Cannot Pop" << endl;
            return;
        }
        this->f++;
        this->f = this->f % this->size;
        if ((this->r + 1) % this->size == this->f)
        {
            this->f = this->r = -1;
        }
    }

    int front()
    {
        if (empty())
        {
            cout << "Queue Is Empty, Cannot Front" << endl;
            return -1;
        }
        return this->arr[this->f];
    }

    ~Queue()
    {
        delete[] this->arr;
    }
};

int main()
{
    Queue q = Queue(5);
    q.print();
    q.push(1);
    q.push(2);
    q.push(3);
    q.print();
    q.push(4);
    q.push(5);
    q.push(6);
    q.print();
    q.pop();
    q.pop();
    q.pop();
    q.print();
    q.push(12);
    cout << q.front() << endl;
    q.print();
    return 0;
}