#include <iostream>

#include <ctime>



using namespace std;



struct Node {

    int data;

    Node* prev;

    Node* next;

};



class Stack {

private:

    Node* top;

public:

    Stack() {

        top = nullptr;

    }



    void push(int data) {

        Node* newNode = new Node;

        newNode->data = data;

        newNode->prev = nullptr;

        newNode->next = top;



        if (top != nullptr) {

            top->prev = newNode;

        }

        top = newNode;

    }



    void pop() {

        if (top == nullptr) {

            cout << "Stack is empty" << endl;

            return;

        }



        Node* temp = top;

        top = top->next;



        if (top != nullptr) {

            top->prev = nullptr;

        }



        delete temp;

    }



    void print() {

        Node* temp = top;

        while (temp != nullptr) {

            cout << temp->data << " ";

            temp = temp->next;

        }

        cout << endl;

    }

};



class Queue {

private:

    Node* front;

    Node* rear;

public:

    Queue() {

        front = rear = nullptr;

    }



    void enqueue(int data) {

        Node* newNode = new Node;

        newNode->data = data;

        newNode->prev = rear;

        newNode->next = nullptr;



        if (rear != nullptr) {

            rear->next = newNode;

        }

        else {

            front = newNode;

        }

        rear = newNode;

    }



    void dequeue() {

        if (front == nullptr) {

            cout << "Queue is empty" << endl;

            return;

        }



        Node* temp = front;

        front = front->next;



        if (front == nullptr) {

            rear = nullptr;

        }

        else {

            front->prev = nullptr;

        }



        delete temp;

    }



    void print() {

        Node* temp = front;

        while (temp != nullptr) {

            cout << temp->data << " ";

            temp = temp->next;

        }

        cout << endl;

    }

};



int main() {

    Stack s;

    Queue q;

    // Measure time for insertion

    clock_t start, end;

    double cpu_time_used;


    // Insert 10000 random integers into stack and queue

    start = clock();

    for (int i = 0; i < 10000; ++i) {

        int random_num = rand() % 10000;

        s.push(random_num);

    }

    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    cout << "Time taken for stack insertion: " << cpu_time_used << " seconds" << endl;

    //Measure time for insertion into queue
    start = clock();
    for (int i = 0; i < 10000; ++i)
    {
        int random_num = rand() % 10000;

        q.enqueue(random_num);
    }
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    cout << "Time taken for queue insertion: " << cpu_time_used << " seconds" << endl;


    // Remove and measure time for deletion from stack

    start = clock();

    for (int i = 0; i < 10000; ++i) {

        s.pop();

    }

    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    cout << "Time taken for stack deletion: " << cpu_time_used << " seconds" << endl;

    //Measure time for deletion from que

    start = clock();
    for (int i = 0; i < 10000; ++i) {

        q.dequeue();

    }
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    cout << "Time taken for que deletion: " << cpu_time_used << " seconds" << endl;

    return 0;

}