#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    
    for(auto &i: a) {
        cin>>i;
    }

    deque<int> dq;
    vector<int> ans;

    for(int i=0; i<k; i++) {
        while(!dq.empty() and a[dq.back()]<a[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    ans.push_back(a[dq.front()]);

    for(int i=k; i<n; i++) {
        if(dq.front() == i-k) {
            dq.pop_front();
        }
        while(!dq.empty() and a[dq.back()]<a[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(a[dq.front()]);
    }

    for(auto i: ans) {
        cout<<i<<" ";
    }

    return 0;
}