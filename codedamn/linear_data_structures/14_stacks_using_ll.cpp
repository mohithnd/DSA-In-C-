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
        this->next = nullptr;
    }
};

class Stack
{
public:
    int size;
    int current;
    Node *head;
    Stack(int size)
    {
        this->size = size;
        this->current = 0;
        this->head = nullptr;
    }

    bool empty()
    {
        if (this->head == nullptr)
        {
            return true;
        }
        return false;
    }

    bool full()
    {
        if (this->current == this->size)
        {
            return true;
        }
        return false;
    }

    void push(int data)
    {
        if (full())
        {
            cout << "Stack Overflow, Cannot Push" << endl;
            return;
        }
        Node *temp = new Node(data);
        temp->next = this->head;
        this->head = temp;
        this->current++;
    }

    void pop()
    {
        if (empty())
        {
            cout << "Stack Underflow, Cannot Pop" << endl;
            return;
        }
        Node *temp = this->head;
        this->head = this->head->next;
        delete temp;
        this->current--;
    }

    int peek()
    {
        if (empty())
        {
            cout << "Stack Underflow, Cannot Peek" << endl;
            return -1;
        }
        return this->head->data;
    }

    void print()
    {
        if (empty())
        {
            cout << "Stack Is Empty" << endl;
            return;
        }
        Node *temp = this->head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int get_size()
    {
        return this->current;
    }

    ~Stack()
    {
        while (this->head)
        {
            Node *temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
    }
};

int main()
{
    Stack st(5);
    st.print();
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.print();
    cout << st.peek() << endl;
    st.pop();
    st.pop();
    st.print();
    cout << st.get_size() << endl;
    return 0;
}