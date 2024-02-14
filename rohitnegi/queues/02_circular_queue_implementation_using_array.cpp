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
        return (rear + 1) % size == front;
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
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = data;
        }
        cout << data << " - Pushed In The Queue" << endl;
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
            front = (front + 1) % size;
        }
        cout << data << " - Popped From The Queue" << endl;
        return data;
    }
    int start()
    {
        if (empty())
        {
            cout << "Underflow" << endl;
            return -1;
        }
        return arr[front];
    }
    int end()
    {
        if (empty())
        {
            cout << "Underflow" << endl;
            return -1;
        }
        return arr[rear];
    }
    int get_size()
    {
        if (full())
        {
            return size;
        }
        if (empty())
        {
            return 0;
        }
        int f = front;
        int cnt = 1;
        while (f != rear)
        {
            cnt++;
            f = f + 1;
            f = f % size;
        }
        return cnt;
    }
    void display()
    {
        if (empty())
        {
            cout << "Empty Queue" << endl;
            return;
        }
        int f = front;
        while (f != rear)
        {
            cout << arr[f] << " ";
            f = f + 1;
            f = f % size;
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
    q.push(5);
    q.push(15);
    q.push(51);
    q.push(125);
    q.push(6);
    q.pop();
    q.push(511);
    q.push(38);
    q.pop();
    cout << q.get_size() << endl;
    cout << q.start() << endl;
    cout << q.end() << endl;
    q.display();
    return 0;
}