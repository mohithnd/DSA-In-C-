#include <iostream>
using namespace std;

class MaxHeap
{
public:
    int *arr;
    int size;
    int total_size;
    MaxHeap(int total_size)
    {
        this->total_size = total_size;
        this->size = 0;
        this->arr = new int[total_size];
    }

    bool full()
    {
        if (this->size == this->total_size)
        {
            return true;
        }
        return false;
    }

    bool empty()
    {
        if (this->size == 0)
        {
            return true;
        }
        return false;
    }

    void insert(int data)
    {
        if (full())
        {
            cout << "Heap Is Full, Cannot Insert" << endl;
            return;
        }
        this->arr[this->size] = data;
        this->size++;
        int i = this->size - 1;
        while (i > 0 && this->arr[i] > this->arr[(i - 1) / 2])
        {
            swap(this->arr[i], this->arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void print()
    {
        if (empty())
        {
            cout << "Heap Is Empty" << endl;
            return;
        }
        for (int i = 0; i < this->size; i++)
        {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }

    void heapify(int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        if (left < this->size)
        {
            if (arr[left] > arr[largest])
            {
                largest = left;
            }
        }
        if (right < this->size)
        {
            if (arr[right] > arr[largest])
            {
                largest = right;
            }
        }
        if (largest != index)
        {
            swap(arr[largest], arr[index]);
            heapify(largest);
        }
    }

    int pop()
    {
        if (empty())
        {
            cout << "Heap Is Empty, Cannot Pop" << endl;
            return -1;
        }
        int data = this->arr[0];
        this->arr[0] = this->arr[this->size - 1];
        this->size--;
        if (this->size == 0)
        {
            return data;
        }
        heapify(0);
        return data;
    }

    ~MaxHeap()
    {
        delete[] this->arr;
    }
};

int main()
{
    MaxHeap heap(6);
    heap.insert(4);
    heap.insert(14);
    heap.insert(11);
    heap.print();
    heap.insert(114);
    heap.insert(24);
    heap.insert(1);
    heap.insert(10);
    heap.print();
    cout << heap.pop() << endl;
    heap.print();
    cout << heap.pop() << endl;
    heap.print();
    cout << heap.pop() << endl;
    heap.print();
    cout << heap.pop() << endl;
    heap.print();
    cout << heap.pop() << endl;
    heap.print();
    cout << heap.pop() << endl;
    heap.print();
    cout << heap.pop() << endl;
    heap.print();
    return 0;
}