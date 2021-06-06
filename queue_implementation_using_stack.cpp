#include<bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1;
    stack<int> s2;

    public:
        void push(int val) {
            s1.push(val);
        }

        int pop() {
            if(s1.empty() && s2.empty()) {
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            if(s2.empty()) {
                while(!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }

            int topVal = s2.top();
            s2.pop();
            return topVal;
        }

        bool isEmpty() {
            if(s1.empty() && s2.empty()) {
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