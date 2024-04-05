#include <iostream>
using namespace std;

class PriorityQueue
{
public:
    int *arr;
    int size;
    int f;
    int r;
    PriorityQueue(int size)
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
            cout << "Priority Queue Is Full, Cannot Insert" << endl;
            return;
        }
        if (empty())
        {
            this->f = this->r = 0;
            this->arr[0] = data;
            return;
        }
        this->r = (this->r + 1) % this->size;
        int i = this->r;
        while (i != this->f && this->arr[(i - 1 + this->size) % this->size] > data)
        {
            this->arr[i] = this->arr[(i - 1 + this->size) % this->size];
            i = (i - 1 + this->size) % this->size;
        }
        this->arr[i] = data;
    }

    void print()
    {
        if (empty())
        {
            cout << "Priority Queue Is Empty" << endl;
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
            cout << "Priority Queue Is Empty, Cannot Pop" << endl;
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
            cout << "Priority Queue Is Empty, Cannot Front" << endl;
            return -1;
        }
        return this->arr[this->f];
    }

    ~PriorityQueue()
    {
        delete[] this->arr;
    }
};

int main()
{
    PriorityQueue pq = PriorityQueue(5);
    pq.print();
    pq.push(6);
    pq.push(4);
    pq.push(5);
    pq.print();
    pq.push(3);
    pq.push(1);
    pq.push(2);
    pq.print();
    pq.pop();
    pq.pop();
    pq.pop();
    pq.print();
    pq.push(12);
    pq.push(2);
    cout << pq.front() << endl;
    pq.print();
    return 0;
}