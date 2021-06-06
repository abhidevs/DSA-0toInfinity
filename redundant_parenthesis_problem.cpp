#include<bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin>>s;
    stack<char> st;
    bool flag = false;

    for(int i=0; i<s.size(); i++) {
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            st.push(s[i]);
        }
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            if(st.top() == '(') {
                flag = true;
                break;
            }

            while(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/') {
                st.pop();
            }
            st.pop();
        }
        
    }

    cout<<flag;

    return 0;
}