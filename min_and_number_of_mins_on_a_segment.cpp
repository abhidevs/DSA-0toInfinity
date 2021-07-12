#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+2, MOD = 1e9+7;
pair<int, int> tree[4*N];
int a[N];

void build(int node, int st, int end) {
    if(st == end) {
        tree[node].first = a[st];
        tree[node].second = 1;
        return;
    }

    int mid = (st +end) / 2;
    build(2*node, st, mid);
    build(2*node+1, mid+1, end);

    if(tree[2*node].first < tree[2*node+1].first) {
        tree[node].first = tree[2*node].first;
        tree[node].second = tree[2*node].second;
    }
    else if(tree[2*node+1].first < tree[2*node].first) {
        tree[node].first = tree[2*node+1].first;
        tree[node].second = tree[2*node+1].second;
    }
    else {
        tree[node].first = tree[2*node].first;
        tree[node].second = tree[2*node].second + tree[2*node+1].second;
    }
}

pair<int, int> query(int node, int st, int end, int l, int r) {
    if(st>r || end<l)
        return {MOD, -1};

    if(l <= st && r >= end)
        return tree[node];
    
    int mid = (st + end) / 2;
    pair<int, int> q1 = query(2*node, st, mid, l, r);
    pair<int, int> q2 = query(2*node+1, mid+1, end, l, r);

    pair<int, int> ans;
    if(q1.first < q2.first)
        ans = q1;
    else if(q2.first < q1.first)
        ans = q2;
    else {
        ans.first = q1.first;
        ans.second = q1.second + q2.second;
    }

    return ans;
}

void update(int node, int st, int end, int idx, int val) {
    if(st == end) {
        a[st] = val;
        tree[node].first = val;
        tree[node].second = 1;
        return;
    }

    int mid = (st + end) / 2;
    if(idx <= mid)
        update(2*node, st, mid, idx, val);
    else
        update(2*node+1, mid+1, end, idx, val);

    if(tree[2*node].first < tree[2*node+1].first) {
        tree[node].first = tree[2*node].first;
        tree[node].second = tree[2*node].second;
    }
    else if(tree[2*node+1].first < tree[2*node].first) {
        tree[node].first = tree[2*node+1].first;
        tree[node].second = tree[2*node+1].second;
    }
    else {
        tree[node].first = tree[2*node].first;
        tree[node].second = tree[2*node].second + tree[2*node+1].second;
    }
}

signed main() {
    int n, m;
    cin>>n>>m;

    for(int i=0; i<n; i++)
        cin>>a[i];
    
    build(1, 0, n-1);

    while(m--) {
        int type;
        cin>>type;

        if(type == 1) {
            // Here input 1 is being used for update operation
            int idx, val;
            cin>>idx>>val;
            update(1, 0, n-1, idx, val);
        }
        else if(type == 2) {
            // input 2 is being used for query operation
            int l, r;
            cin>>l>>r;
            pair<int, int> ans = query(1, 0, n-1, l, r-1);
            cout<<ans.first<<" "<<ans.second<<endl;
        }
    }

    return 0;
}