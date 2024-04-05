#include <iostream>
using namespace std;

class Deque
{
public:
    int *arr;
    int size;
    int front;
    int rear;
    Deque(int n)
    {
        this->size = n;
        this->arr = new int[n];
        this->front = this->rear = -1;
    }

    void push_front(int x)
    {
        if (full())
        {
            cout << "Deque Is Full, Cannot Push Front" << endl;
            return;
        }
        if (empty())
        {
            this->front = this->rear = 0;
            this->arr[0] = x;
            return;
        }
        this->front = (this->front - 1 + this->size) % this->size;
        this->arr[this->front] = x;
    }

    void push_rear(int x)
    {
        if (full())
        {
            cout << "Deque Is Full, Cannot Push Rear" << endl;
            return;
        }
        if (empty())
        {
            this->front = this->rear = 0;
            this->arr[0] = x;
            return;
        }
        this->rear = (this->rear + 1) % this->size;
        this->arr[this->rear] = x;
    }

    void pop_front()
    {
        if (empty())
        {
            cout << "Deque Is Empty, Cannot Pop Front" << endl;
            return;
        }
        this->front = (this->front + 1) % this->size;
        if ((this->rear + 1) % this->size == this->front)
        {
            this->front = this->rear = -1;
        }
    }

    void pop_rear()
    {
        if (empty())
        {
            cout << "Deque Is Empty, Cannot Pop Rear" << endl;
            return;
        }
        this->rear = (this->rear - 1 + this->size) % this->size;
        if ((this->rear + 1) % this->size == this->front)
        {
            this->front = this->rear = -1;
        }
    }

    int get_front()
    {
        if (empty())
        {
            cout << "Deque Is Empty, Cannot Get Front" << endl;
            return -1;
        }
        return this->arr[this->front];
    }

    int get_rear()
    {
        if (empty())
        {
            cout << "Deque Is Empty, Cannot Get Rear" << endl;
            return -1;
        }
        return this->arr[this->rear];
    }

    bool empty()
    {
        return this->front == -1 && this->rear == -1;
    }

    bool full()
    {
        return (this->rear + 1) % this->size == this->front;
    }

    void print()
    {
        if (empty())
        {
            cout << "Deque Is Empty" << endl;
            return;
        }
        int i = this->front;
        while (i != this->rear)
        {
            cout << this->arr[i] << " ";
            i = i + 1;
            i = i % this->size;
        }
        cout << this->arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    Deque dq(5);
    dq.push_front(10);
    dq.push_front(20);
    dq.push_rear(30);
    dq.print();
    cout << dq.get_front() << endl;
    dq.pop_rear();
    dq.pop_rear();
    dq.print();
    return 0;
}