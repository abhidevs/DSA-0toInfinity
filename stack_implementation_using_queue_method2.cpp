#include<bits/stdc++.h>
using namespace std;

class Stack {
    int n;
    queue<int> q1;
    queue<int> q2;
    
    public:
    Stack() {
        n = 0;
    }

    void push(int val) {
        q1.push(val);
        n++;
    }

    void pop() {
        if(q1.empty()) {
            cout<<"Stack is empty"<<endl;
            return;
        }

        while(q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();
        n--;

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int top() {
        if(q1.empty()) {
            cout<<"Stack is empty"<<endl;
            return -1;
        }

        // while(q1.size() != 1) {
        //     q2.push(q1.front());
        //     q1.pop();
        // }

        // int ans = q1.front();
        // q2.push(ans);

        // queue<int> temp = q1;
        // q1 = q2;
        // q2 = temp;
        
        return q1.back();
    }

    int size() {
        return n;
    }
};

int main() {

    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<st.top()<<endl;
    st.pop();

    cout<<st.top()<<endl;
    st.pop();
    cout<<st.size()<<endl;

    cout<<st.top()<<endl;
    st.pop();

    cout<<st.top()<<endl;
    st.pop();

    cout<<st.top()<<endl;
    st.pop();
    cout<<st.size()<<endl;

    return 0;
}