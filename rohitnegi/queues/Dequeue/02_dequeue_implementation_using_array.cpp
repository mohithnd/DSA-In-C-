#include <iostream>
using namespace std;

class Dequeue
{
public:
    int *arr;
    int front;
    int rear;
    int size;
    Dequeue(int size)
    {
        this->size = size;
        this->arr = new int[size];
        this->front = -1;
        this->rear = -1;
    }
    bool empty()
    {
        return front == -1;
    }
    bool full()
    {
        return (this->rear + 1) % this->size == this->front;
    }
    void push_front(int data)
    {
        if (full())
        {
            cout << "Dequeue Is Full" << endl;
            return;
        }
        if (empty())
        {
            this->arr[0] = data;
            this->front = this->rear = 0;
        }
        else
        {
            this->front = (this->front - 1 + this->size) % this->size;
            this->arr[this->front] = data;
        }
    }
    void push_back(int data)
    {
        if (full())
        {
            cout << "Dequeue Is Full" << endl;
            return;
        }
        if (empty())
        {
            this->arr[0] = data;
            this->front = this->rear = 0;
        }
        else
        {
            this->rear = (this->rear + 1) % this->size;
            this->arr[this->rear] = data;
        }
    }
    int start()
    {
        if (empty())
        {
            return -1;
        }
        return this->arr[this->front];
    }
    int end()
    {
        if (empty())
        {
            return -1;
        }
        return this->arr[this->rear];
    }
    void pop_front()
    {
        if (empty())
        {
            cout << "Dequeue Is Empty" << endl;
            return;
        }
        this->front = (this->front + 1) % this->size;
        if ((this->rear + 1) % this->size == this->front)
        {
            this->front = -1;
            this->rear = -1;
        }
    }
    void pop_back()
    {
        if (empty())
        {
            cout << "Dequeue Is Empty" << endl;
            return;
        }
        this->rear = (this->rear - 1 + this->size) % this->size;
        if ((this->rear + 1) % this->size == this->front)
        {
            this->front = -1;
            this->rear = -1;
        }
    }
    void display()
    {
        if (empty())
        {
            cout << "Dequeue Is Empty" << endl;
            return;
        }
        int f = front;
        while (f != this->rear)
        {
            cout << arr[f] << " ";
            f++;
            f = f % size;
        }
        cout << arr[rear] << endl;
    }
};

int main()
{
    Dequeue d(5);
    cout << d.empty() << endl;
    d.push_front(10);
    d.push_front(20);
    d.push_back(30);
    d.push_back(40);
    cout << d.start() << endl;
    d.pop_back();
    d.pop_back();
    d.display();
    return 0;
}