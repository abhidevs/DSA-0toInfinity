#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = NULL;
        }
};

class Queue {
    Node* front;
    Node* back;

    public:
        Queue() {
            front = NULL;
            back = NULL;
        }

        void push(int val) {
            Node* n = new Node(val);

            if(front == NULL) {
                back = n;
                front = n;
                return;
            }
            back->next = n;
            back = n;
        }

        void pop() {
            if(front == NULL) {
                cout<<"Queue underflow"<<endl;
                return;
            }

            Node* toDelete = front;
            front = front->next;

            delete toDelete;
        }

        int peek() {
            if(front == NULL) {
                cout<<"No element in queue"<<endl;
                return -1;
            }

            return front->data;
        }

        bool isEmpty() {
            if(front == NULL) {
                return true;
            }
            return false;
        }
};

int main() {

    Queue q1;

    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);

    cout<<q1.peek()<<endl;
    q1.pop();

    cout<<q1.peek()<<endl;
    q1.pop();

    cout<<q1.peek()<<endl;
    q1.pop();

    cout<<q1.peek()<<endl;
    q1.pop();

    cout<<q1.peek()<<endl;
    q1.pop();

    cout<<q1.isEmpty()<<endl;

    return 0;
}