#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data = -1)
    {
        this->data = data, this->next = nullptr;
    }
};

class Queue
{
public:
    Node *front;
    Node *rear;
    bool empty()
    {
        return front == nullptr;
    }
    void push(int data)
    {
        Node *temp = new Node(data);
        if (empty())
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
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
        int data = front->data;
        if (front == rear)
        {
            Node *temp = front;
            front = rear = nullptr;
            delete temp;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
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
        return front->data;
    }
    int end()
    {
        if (empty())
        {
            cout << "Underflow" << endl;
            return -1;
        }
        return rear->data;
    }
    int get_size()
    {
        if (empty())
        {
            return 0;
        }
        Node *ptr = front;
        int cnt = 0;
        while (ptr)
        {
            cnt++;
            ptr = ptr->next;
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
        Node *ptr = front;
        int cnt = 0;
        while (ptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
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