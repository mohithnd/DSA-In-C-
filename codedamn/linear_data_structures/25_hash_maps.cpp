#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    string value;
    Node *next;
    Node(int key, string value)
    {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
};

class HashMap
{
public:
    const static int bucket_size = 5;
    Node *bucket[bucket_size];
    int size;
    HashMap()
    {
        this->size = 0;
        for (int i = 0; i < this->bucket_size; i++)
        {
            bucket[i] = nullptr;
        }
    }

    int hash_key(int key)
    {
        return key % this->bucket_size;
    }

    void insert(int key, string value)
    {
        int ind = hash_key(key);
        if (bucket[ind] == nullptr)
        {
            this->bucket[ind] = new Node(key, value);
            this->size++;
        }
        else
        {
            Node *curr = bucket[ind];
            while (curr)
            {
                if (curr->key == key)
                {
                    curr->value = value;
                    return;
                }
                if (curr->next == nullptr)
                {
                    break;
                }
                curr = curr->next;
            }
            curr->next = new Node(key, value);
            this->size++;
        }
    }

    string retrieve(int key)
    {
        int ind = hash_key(key);
        Node *curr = this->bucket[ind];
        while (curr)
        {
            if (curr->key == key)
            {
                return curr->value;
            }
            curr = curr->next;
        }
        return "";
    }

    void remove(int key)
    {
        int ind = hash_key(key);
        if (this->bucket[ind])
        {
            if (this->bucket[ind]->key == key)
            {
                Node *next = this->bucket[ind]->next;
                delete this->bucket[ind];
                this->bucket[ind] = next;
                this->size--;
            }
            else
            {
                Node *prev = this->bucket[ind];
                Node *curr = prev->next;
                while (curr)
                {
                    if (curr->key == key)
                    {
                        prev->next = curr->next;
                        delete curr;
                        this->size--;
                        return;
                    }
                    prev = curr;
                    curr = curr->next;
                }
            }
        }
    }

    bool has(int key)
    {
        int ind = hash_key(key);
        Node *curr = this->bucket[ind];
        while (curr)
        {
            if (curr->key == key)
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    void print_in_detail()
    {
        for (int i = 0; i < this->bucket_size; i++)
        {
            if (this->bucket[i])
            {
                cout << i << " -> ";
                Node *curr = this->bucket[i];
                while (curr)
                {
                    cout << " { " << curr->key << " : " << curr->value << " } ";
                    curr = curr->next;
                }
                cout << endl;
            }
        }
        cout << endl;
    }

    void print_all()
    {
        for (int i = 0; i < this->bucket_size; i++)
        {
            Node *curr = this->bucket[i];
            while (curr)
            {
                cout << "{ " << curr->key << " : " << curr->value << " }" << endl;
                curr = curr->next;
            }
        }
        cout << endl;
    }

    ~HashMap()
    {
        for (int i = 0; i < this->bucket_size; i++)
        {
            Node *curr = this->bucket[i];
            while (curr)
            {
                Node *next = curr->next;
                delete curr;
                curr = next;
            }
        }
    }
};

int main()
{
    HashMap m;
    m.insert(1, "Piyush");
    m.insert(2, "John");
    m.insert(6, "Jane");
    m.insert(5, "ABC");
    m.insert(7, "XYZ");
    m.insert(7, "Ram");
    m.insert(17, "XYZ");
    m.insert(17, "Kapil");
    cout << "Size - " << m.size << endl;
    m.print_in_detail();
    m.print_all();

    cout << m.retrieve(3) << endl;
    cout << m.retrieve(2) << endl;
    cout << m.retrieve(7) << endl;
    cout << m.retrieve(17) << endl;

    cout << m.has(3) << endl;
    cout << m.has(2) << endl;
    cout << m.has(7) << endl;
    cout << m.has(17) << endl;

    m.remove(17);
    m.remove(5);
    m.remove(3);

    cout << "Size - " << m.size << endl;
    m.print_in_detail();
    m.print_all();
    return 0;
}