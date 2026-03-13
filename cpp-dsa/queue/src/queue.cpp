#include <iostream>
#include <fmt/core.h>

using namespace std;
class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* first;
    Node* last;
    int length;
public:
    Queue(int value)
    {
        Node* newNode = new Node(value);
        first = newNode;
        last = newNode;
        length = 1;
    }
    ~Queue()
    {
        Node* temp = first;
        while (first != nullptr)
        {
            first = first->next;
            delete temp;
            temp = first;
        }
    }
    void printQueue()
    {
        if (length == 0)
        {
            fmt::print("Queue: empty \n");
        }
        Node* temp = first;
        while (temp != nullptr)
        {
            fmt::print("{} ", temp->value);
            temp = temp->next;
            if (temp != nullptr)
                fmt::print(" -> ");
        }
    }
    Node* getFirst()
    {
        return first;
    }
    Node* getLast()
    {
        return last;
    }
    int getLength()
    {
        return length;
    }
    void makeEmpty()
    {
        Node* temp;
        while (first != nullptr)
        {
            temp = first;
            first = first->next;
            delete temp;
        }
        first = nullptr;
        last = nullptr;
        length = 0;
    }
    bool isEmpty()
    {
        if (length == 0) return true;
        return false;
    }
    void enqueue(int value)
    {
        Node* newNode = new Node(value);
        if (length == 0)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
        length++;
    }
    int dequeue()
    {
        if (length == 0) return INT_MIN;
        Node* temp = first;
        int deque_value = first->value;
        if (length == 1)
        {
            first = nullptr;
            last = nullptr;
        }
        else
        {
            first = first->next;
        }
        delete temp;
        length--;
        return deque_value;
    }
};

int main()
{
    fmt::print("Creating queue with initial value 10\n");

    Queue myQueue(10);

    fmt::print("Initial queue:\n");
    myQueue.printQueue();
    fmt::print("\n\n");

    fmt::print("Enqueue 20\n");
    myQueue.enqueue(20);
    myQueue.printQueue();
    fmt::print("\n\n");

    fmt::print("Enqueue 30\n");
    myQueue.enqueue(30);
    myQueue.printQueue();
    fmt::print("\n\n");

    fmt::print("First element: {}\n", myQueue.getFirst()->value);
    fmt::print("Last element: {}\n\n", myQueue.getLast()->value);

    fmt::print("Dequeued value: {}\n", myQueue.dequeue());
    myQueue.printQueue();
    fmt::print("\n\n");

    fmt::print("Dequeued value: {}\n", myQueue.dequeue());
    myQueue.printQueue();
    fmt::print("\n\n");

    fmt::print("Queue length: {}\n\n", myQueue.getLength());

    fmt::print("Emptying queue...\n");
    myQueue.makeEmpty();

    fmt::print("Queue is empty? {}\n", myQueue.isEmpty());

    return 0;
}
