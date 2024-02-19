#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Dequeue
{
public:
    Node *rear;
    Node *front;
    Dequeue()
    {
        this->rear = nullptr;
        this->front = nullptr;
    }
    bool empty()
    {
        return this->rear == nullptr;
    }
    void push_front(int data)
    {
        Node *temp = new Node(data);
        if (empty())
        {
            rear = front = temp;
        }
        else
        {
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
    }
    void push_back(int data)
    {
        Node *temp = new Node(data);
        if (empty())
        {
            rear = front = temp;
        }
        else
        {
            this->rear->next = temp;
            temp->prev = this->rear;
            this->rear = temp;
        }
    }
    void pop_front()
    {
        if (empty())
        {
            cout << "Dequeue Is Empty" << endl;
            return;
        }
        if (front->next == nullptr)
        {
            Node *temp = front;
            front = rear = nullptr;
            delete temp;
            return;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            front->prev = nullptr;
            delete temp;
            return;
        }
    }
    void pop_back()
    {
        if (empty())
        {
            cout << "Dequeue Is Empty" << endl;
            return;
        }
        if (front->next == nullptr)
        {
            Node *temp = front;
            front = rear = nullptr;
            delete temp;
            return;
        }
        else
        {
            Node *temp = rear;
            this->rear = this->rear->prev;
            this->rear->next = nullptr;
            delete temp;
            return;
        }
    }
    int start()
    {
        if (empty())
        {
            return -1;
        }
        return this->front->data;
    }
    int end()
    {
        if (empty())
        {
            return -1;
        }
        return this->rear->data;
    }
    void display()
    {
        if (empty())
        {
            cout << "Dequeue Is Empty" << endl;
            return;
        }
        Node *temp = front;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Dequeue d;
    cout << d.empty() << endl;
    d.push_front(10);
    d.push_front(20);
    d.push_back(30);
    cout << d.start() << endl;
    d.pop_back();
    d.pop_back();
    d.display();
    return 0;
}