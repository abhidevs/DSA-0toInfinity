#include<bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1;

    public:
        void push(int val) {
            s1.push(val);
        }

        int pop() {
            if(s1.empty()) {
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            
            int x = s1.top();
            s1.pop();

            if(s1.empty()) {
                return x;
            }

            int item = pop();
            s1.push(x);
            return item;
        }

        bool isEmpty() {
            if(s1.empty()) {
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

    cout<<q1.pop()<<endl;
    q1.push(5);

    cout<<q1.pop()<<endl;
    cout<<q1.pop()<<endl;
    cout<<q1.pop()<<endl;
    cout<<q1.pop()<<endl;
    cout<<q1.pop()<<endl;

    return 0;
}