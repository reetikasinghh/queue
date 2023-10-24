// Define ERROR and MAXSIZE constants
#define ERROR -9999
#define MAXSIZE 10

#include<iostream>
using namespace std;

// Define a class for a queue
class Queue {
    int front, rear;
    int array[MAXSIZE];
    int size;

public:
    // Constructor to initialize the queue
    Queue() {
        front = rear = -1;
    }

    // Function to enqueue (add) an element to the queue
    void EnQueue(int item);

    // Function to dequeue (remove) an element from the queue
    int DeQueue();

    // Function to display the elements in the queue
    void Display();
};

// Function to enqueue (add) an element to the queue
void Queue::EnQueue(int element) {
    if (rear == MAXSIZE - 1) {
        cout << "Queue overflow" << endl;
        return;
    } else {
        if (front == -1)
            front = 0;

        rear++;
        array[rear] = element;
    }
}

// Function to dequeue (remove) an element from the queue
int Queue::DeQueue() {
    if (front == -1 || front == rear + 1) {
        cout << "Queue is empty" << endl;
        return ERROR; // Return ERROR when the queue is empty
    }
    int ele = array[front];
    front++;
    return ele;
}

// Function to display the elements in the queue
void Queue::Display() {
    int i = front;
    if (front == -1 || front == rear + 1) {
        cout << "Queue is empty" << endl;
    }
    while (i <= rear) {
        cout << array[i] << endl;
        i++;
    }
}

int main() {
    Queue q1;
    q1.EnQueue(10);
    q1.EnQueue(20);
    int v = q1.DeQueue();
    q1.Display(); // Display the remaining element(s) in the queue
}

/*Output
20
*/

