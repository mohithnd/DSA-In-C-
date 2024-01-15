#include <iostream>
using namespace std;

class Queue
{
public:
    int *arr;
    int count;
    int front;
    int rear;
    int size;
    Queue()
    {
        this->size = 5;
        this->arr = new int[this->size];
        this->count = 0;
        this->front = 0;
        this->rear = 0;
    }
    bool empty()
    {
        if (this->count == 0)
        {
            this->front = 0;
            this->rear = 0;
            return true;
        }
        return false;
    }
    bool full()
    {
        if (this->count == this->size)
        {
            return true;
        }
        return false;
    }
    void push(int data)
    {
        if (this->full())
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (this->empty())
        {

            this->arr[this->rear] = data;
            this->count++;
        }
        else
        {
            this->rear = (this->rear + 1) % this->size;
            this->arr[this->rear] = data;
            this->count++;
        }
    }
    void pop()
    {
        if (this->empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        this->front = (this->front + 1) % this->size;
        this->count--;
    }
    int front_item()
    {
        if (this->empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return this->arr[this->front];
    }
    int size_of_queue()
    {
        return this->count;
    }
    void print_queue()
    {
        if (this->empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = 0; i < this->count; i++)
        {
            cout << this->arr[(this->front + i) % this->size] << " ";
        }
        cout << endl;
    }
    ~Queue()
    {
        delete[] this->arr;
    }
};

int main()
{
    Queue q;
    q.push(3);
    q.push(2);
    q.push(1);
    q.push(8);
    q.push(6);
    q.push(7);
    q.print_queue();
    q.pop();
    q.pop();
    q.pop();
    q.push(9);
    q.push(10);
    q.push(11);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.push(12);
    cout << "Size: " << q.size_of_queue() << endl;
    cout << "Front: " << q.front << endl;
    cout << "Rear: " << q.rear << endl;
    q.print_queue();
    return 0;
}