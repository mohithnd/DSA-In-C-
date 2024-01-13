#include <iostream>
using namespace std;

class Queue
{
public:
    int *arr;
    int front;
    int rear;
    int capacity;
    Queue()
    {
        this->capacity = 5;
        this->arr = new int[this->capacity];
        this->front = -1;
        this->rear = -1;
    }
};

int main()
{
    return 0;
}