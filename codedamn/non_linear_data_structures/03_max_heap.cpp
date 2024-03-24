#include <iostream>
using namespace std;

class MaxHeap
{
public:
    int *items;
    int size;
    int ind;
    MaxHeap(int size)
    {
        this->size = size;
        this->items = new int[this->size];
        this->ind = 0;
    }

    bool empty()
    {
        return this->ind == 0;
    }

    bool full()
    {
        return this->ind >= this->size;
    }

    int get_parent_index(int ind)
    {
        return (ind - 1) / 2;
    }

    void insert(int data)
    {
        if (full())
        {
            cout << "Heap Is Full, Cannot Insert" << endl;
            return;
        }
        this->items[this->ind] = data;
        this->ind++;
        int i = this->ind - 1;
        while (i > 0 && this->items[i] > this->items[get_parent_index(i)])
        {
            swap(this->items[i], this->items[get_parent_index(i)]);
            i = get_parent_index(i);
        }
    }

    int get_left_child_index(int ind)
    {
        return 2 * ind + 1;
    }

    int get_right_child_index(int ind)
    {
        return 2 * ind + 2;
    }

    int left_child(int ind)
    {
        return items[get_left_child_index(ind)];
    }

    int right_child(int ind)
    {
        return items[get_right_child_index(ind)];
    }

    bool has_left_child(int ind)
    {
        return get_left_child_index(ind) < this->ind;
    }

    bool has_right_child(int ind)
    {
        return get_right_child_index(ind) < this->ind;
    }

    bool valid_parent(int ind)
    {
        if (has_left_child(ind) && has_right_child(ind))
        {
            return items[ind] > left_child(ind) && items[ind] > right_child(ind);
        }
        else if (has_left_child(ind) == false && has_right_child(ind) == false)
        {
            return true;
        }
        else if (has_left_child(ind))
        {
            return items[ind] > left_child(ind);
        }
        else
        {
            return false;
        }
    }

    int get_largest_child_index(int ind)
    {
        if (has_left_child(ind) && has_right_child(ind))
        {
            if (left_child(ind) > right_child(ind))
            {
                return get_left_child_index(ind);
            }
            else
            {
                return get_right_child_index(ind);
            }
        }
        else
        {
            return get_left_child_index(ind);
        }
    }

    int remove()
    {
        if (empty())
        {
            cout << "Heap Is Empty, Cannot Remove" << endl;
            return -1;
        }
        int ele = items[0];
        items[0] = items[ind - 1];
        ind--;
        int i = 0;
        while (i < ind && valid_parent(i) == false)
        {
            int largest_child_ind = get_largest_child_index(i);
            swap(items[i], items[largest_child_ind]);
            i = largest_child_ind;
        }
        return ele;
    }

    void print()
    {
        if (empty())
        {
            cout << "Heap Is Empty" << endl;
            return;
        }
        for (int i = 0; i < this->ind; i++)
        {
            cout << this->items[i] << " ";
        }
        cout << endl;
    }

    ~MaxHeap()
    {
        delete[] items;
    }
};

void heapify(int *arr, int n, int i)
{
    int biggest_index = i;
    int lci = 2 * i + 1;
    int rci = 2 * i + 2;
    if (lci < n && arr[lci] > arr[biggest_index])
    {
        biggest_index = lci;
    }
    if (rci < n && arr[rci] > arr[biggest_index])
    {
        biggest_index = rci;
    }
    if (biggest_index == i)
    {
        return;
    }
    swap(arr[biggest_index], arr[i]);
    heapify(arr, n, biggest_index);
}

void heapify_algorithm(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heap_sort(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {-1, 3, 10, 2, 4, 100, 120, 16, 8, 90};
    int n = sizeof(arr) / sizeof(int);
    MaxHeap heap(n);
    for (int i : arr)
    {
        heap.insert(i);
    }
    heap.print();

    while (!heap.empty())
    {
        cout << heap.remove() << " ";
    }
    cout << endl;
    heap.print();

    // heapify_algorithm(arr, n);

    heap_sort(arr, n);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}