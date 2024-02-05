#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Stack
{
    Node *top;
    int size;

public:
    Stack()
    {
        top = NULL;
        size = 0;
    }
    bool empty()
    {
        return top == NULL;
    }
    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
        cout << x << " pushed into stack" << endl;
    }
    void pop()
    {
        if (empty())
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        int x = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        size--;
        cout << x << " popped from stack" << endl;
    }
    int peek()
    {
        if (empty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return top->data;
    }
    int getSize()
    {
        return size;
    }
    void display()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();
    cout << s.getSize() << endl;
    cout << s.peek() << endl;
    return 0;
}