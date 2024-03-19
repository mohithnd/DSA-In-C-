#include <iostream>
using namespace std;

class Array
{
public:
    int *arr;
    int size;
    int curr_index;
    Array()
    {
        this->size = 0;
        this->curr_index = 0;
        this->arr = nullptr;
    }

    bool full()
    {
        if (this->curr_index >= this->size)
        {
            return true;
        }
        return false;
    }

    bool empty()
    {
        if (this->curr_index == 0)
        {
            return true;
        }
        return false;
    }

    void extend()
    {
        cout << "Extend Called" << endl;
        if (this->size == 0)
        {
            this->size = 1;
        }
        else
        {
            this->size = 2 * this->size;
        }
        int *temp = new int[this->size];
        for (int i = 0; i < this->curr_index; i++)
        {
            temp[i] = this->arr[i];
        }
        swap(this->arr, temp);
        delete[] temp;
    }

    void shrink_to_fit()
    {
        cout << "Shrink To Fit Called" << endl;
        if (empty())
        {
            return;
        }
        int *temp = new int[this->curr_index];
        for (int i = 0; i < this->curr_index; i++)
        {
            temp[i] = this->arr[i];
        }
        swap(this->arr, temp);
        this->size = this->curr_index;
        delete[] temp;
    }

    void insert(int data)
    {
        if (full())
        {
            extend();
        }
        this->arr[this->curr_index] = data;
        this->curr_index++;
    }

    void print()
    {
        if (empty())
        {
            cout << "Array Is Empty" << endl;
            return;
        }
        for (int i = 0; i < this->curr_index; i++)
        {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }

    int index_of(int data)
    {
        for (int i = 0; i < this->curr_index; i++)
        {
            if (this->arr[i] == data)
            {
                return i;
            }
        }
        return -1;
    }

    void delete_at(int ind)
    {
        if (empty())
        {
            cout << "Array Is Empty" << endl;
            return;
        }
        if (ind < 0 || ind >= this->curr_index)
        {
            cout << "Invalid Index" << endl;
            return;
        }
        for (int i = ind; i < this->curr_index - 1; i++)
        {
            this->arr[i] = this->arr[i + 1];
        }
        this->curr_index--;
    }

    int min()
    {
        if (empty())
        {
            cout << "Array Is Empty" << endl;
            return -1;
        }
        int ans = INT_MAX;
        for (int i = 0; i < this->curr_index; i++)
        {
            if (this->arr[i] < ans)
            {
                ans = this->arr[i];
            }
        }
        return ans;
    }

    int max()
    {
        if (empty())
        {
            cout << "Array Is Empty" << endl;
            return -1;
        }
        int ans = INT_MIN;
        for (int i = 0; i < this->curr_index; i++)
        {
            if (this->arr[i] > ans)
            {
                ans = this->arr[i];
            }
        }
        return ans;
    }

    void reverse()
    {
        int i = 0;
        int j = this->curr_index - 1;
        while (i < j)
        {
            swap(this->arr[i], this->arr[j]);
            i++;
            j--;
        }
    }

    ~Array()
    {
        delete[] this->arr;
    }
};

int main()
{
    Array arr = Array();
    arr.insert(3);
    arr.insert(1);
    arr.insert(4);
    arr.print();
    cout << arr.index_of(10) << endl;
    cout << arr.index_of(4) << endl;
    arr.delete_at(0);
    arr.print();
    arr.insert(6);
    arr.insert(23);
    arr.print();
    cout << arr.min() << endl;
    cout << arr.max() << endl;
    arr.reverse();
    arr.print();
    arr.insert(20);
    arr.print();
    cout << arr.size << endl;
    cout << arr.curr_index << endl;
    arr.shrink_to_fit();
    cout << arr.size << endl;
    cout << arr.curr_index << endl;
    arr.print();
    return 0;
}