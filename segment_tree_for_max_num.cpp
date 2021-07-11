#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+2;
int tree[4*N], a[N];

void build(int node, int st, int end) {
    if(st == end) {
        tree[node] = a[st];
        return;
    }

    int mid = (st +end) / 2;
    build(2*node, st, mid);
    build(2*node+1, mid+1, end);
    tree[node] = max(tree[2*node], tree[2*node+1]);
}

int query(int node, int st, int end, int l, int r) {
    if(st>r || end<l)
        return INT_MIN;

    if(l <= st && r >= end)
        return tree[node];
    
    int mid = (st + end) / 2;
    int q1 = query(2*node, st, mid, l, r);
    int q2 = query(2*node+1, mid+1, end, l, r);
    return max(q1, q2);
}

void update(int node, int st, int end, int idx, int val) {
    if(st == end) {
        a[st] = val;
        tree[node] = val;
        return;
    }

    int mid = (st + end) / 2;
    if(idx <= mid)
        update(2*node, st, mid, idx, val);
    else
        update(2*node+1, mid+1, end, idx, val);

    tree[node] = max(tree[2*node], tree[2*node+1]);
}

signed main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>a[i];

    build(1, 0, n-1);
    while(1) {
        int type;
        cin>>type;

        if(type == -1)
            break;

        else if(type == 1) {
            int l, r;
            cin>>l>>r;
            cout<<query(1, 0, n-1, l, r)<<endl;
        }

        else if(type == 2) {
            int idx, val;
            cin>>idx>>val;
            update(1, 0, n-1, idx, val);
            cout<<query(1, 0, n-1, 0, n-1)<<endl;
        }

        else
        {
            cout<<"Invalid input!\n";
            cout<<"Press 1 for query\nPress 2 for update\nInput -1 to stop\n";
        }
        
    }

    return 0;
}