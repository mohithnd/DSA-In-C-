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

class LinkedList
{
public:
    Node *head;
    Node *tail;
    LinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    bool empty()
    {
        return this->head == nullptr;
    }

    void insert(int data)
    {
        Node *node = new Node(data);
        if (empty())
        {
            this->head = node;
            this->tail = this->head;
            return;
        }
        this->tail->next = node;
        this->tail = node;
    }

    void insert_at_first(int data)
    {
        Node *temp = new Node(data);
        if (empty())
        {
            this->head = temp;
            this->tail = this->head;
            return;
        }
        temp->next = this->head;
        this->head = temp;
    }

    void insert_at_index(int ind, int data)
    {
        Node *temp = new Node(data);
        if (empty())
        {
            this->head = temp;
            this->tail = this->head;
            return;
        }
        if (ind <= 0)
        {
            insert_at_first(data);
            return;
        }
        int i = 1;
        Node *curr = this->head;
        while (i < ind && curr->next)
        {
            i++;
            curr = curr->next;
        }
        if (curr->next == nullptr)
        {
            insert(data);
            return;
        }
        temp->next = curr->next;
        curr->next = temp;
    }

    void print()
    {
        if (empty())
        {
            cout << "LL Is Empty" << endl;
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

    int sum()
    {
        if (empty())
        {
            return 0;
        }
        int ans = 0;
        Node *curr = this->head;
        while (curr)
        {
            ans += curr->data;
            curr = curr->next;
        }
        return ans;
    }

    int index_of(int data)
    {
        int ans = 0;
        Node *curr = this->head;
        while (curr)
        {
            if (curr->data == data)
            {
                return ans;
            }
            ans++;
            curr = curr->next;
        }
        return -1;
    }

    void reverse()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        Node *prev = nullptr;
        Node *curr = head;
        Node *fwd = nullptr;
        while (curr)
        {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        this->head = prev;
    }

    void delete_node_from_start()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->next == nullptr)
        {
            delete this->head;
            this->head = this->tail = nullptr;
            return;
        }
        Node *temp = this->head;
        this->head = this->head->next;
        delete temp;
    }

    void delete_node_from_end()
    {
        if (empty())
        {
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        Node *curr = head;
        while (curr->next->next)
        {
            curr = curr->next;
        }
        delete curr->next;
        curr->next = nullptr;
        this->tail = curr;
    }

    int length()
    {
        if (this->empty())
        {
            return 0;
        }
        int len = 0;
        Node *curr = this->head;
        while (curr)
        {
            len++;
            curr = curr->next;
        }
        return len;
    }

    void delete_nth_node_from_end(int n)
    {
        Node *prev = nullptr;
        Node *curr = head;
        Node *fast = head;
        int cnt = 0;
        while (cnt < n)
        {
            fast = fast->next;
            cnt++;
        }
        while (fast)
        {
            prev = curr;
            curr = curr->next;
            fast = fast->next;
        }
        if (prev == nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        prev->next = prev->next->next;
        delete curr;
        return;
    }

    void print_recursive(Node *head)
    {
        if (head == nullptr)
        {
            return;
        }
        cout << head->data << " ";
        print_recursive(head->next);
    }

    void print_recursive()
    {
        if (empty())
        {
            cout << "LL Is Empty" << endl;
            return;
        }
        print_recursive(this->head);
        cout << endl;
    }

    Node *reverse_recursive(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        Node *new_head = reverse_recursive(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }

    void reverse_recursive()
    {
        this->head = reverse_recursive(this->head);
    }
};

int main()
{
    LinkedList ll = LinkedList();
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.print_recursive();
    ll.reverse_recursive();
    ll.print_recursive();
    return 0;
}