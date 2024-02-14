#include <iostream>
using namespace std;

class Queue
{
public:
    int *arr;
    int front;
    int rear;
    int size;
    Queue(int n)
    {
        this->size = n;
        this->arr = new int[n];
        this->front = -1;
        this->rear = -1;
    }
    bool empty()
    {
        return front == -1;
    }
    bool full()
    {
        return rear == size - 1;
    }
    void push(int data)
    {
        if (full())
        {
            cout << "Overflow" << endl;
            return;
        }
        if (empty())
        {
            arr[0] = data;
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
        cout << data << " - Pushed in the queue" << endl;
    }
    int pop()
    {
        if (empty())
        {
            cout << "Underflow" << endl;
            return -1;
        }
        int data = arr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
        cout << data << " - Popped from the queue" << endl;
        return data;
    }
    int start()
    {
        if (empty())
        {
            return -1;
        }
        return arr[front];
    }
    int end()
    {
        if (empty())
        {
            return -1;
        }
        return arr[rear];
    }
    int get_size()
    {
        if (empty())
        {
            return 0;
        }
        if (full())
        {
            return size;
        }
        int cnt = 1;
        int f = front;
        while (f != rear)
        {
            cnt++;
            f++;
        }
        return cnt;
    }
    void display()
    {
        if (empty())
        {
            cout << "Queue Is Empty" << endl;
            return;
        }
        int f = front;
        while (f != rear)
        {
            cout << arr[f] << " ";
            f++;
        }
        cout << arr[f] << endl;
    }
    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.pop() << endl;
    q.push(6);
    cout << q.get_size() << endl;
    cout << q.start() << endl;
    cout << q.end() << endl;
    q.display();
    return 0;
}