#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;

class Group {
    public:
        long pref, suff, sum, ans;

        Group(long pref, long suff, long sum, long ans) {
            this->pref = pref;
            this->suff = suff;
            this->sum = sum;
            this->ans = ans;
        }
};

long a[N];
Group* tree[4*N];

void build(int node, int st, int end) {
    if(st == end) {
        if(a[st] <= 0)
            tree[node] = new Group(0, 0, a[st], 0);
        else
            tree[node] = new Group(a[st], a[st], a[st], a[st]);
        return;
    }

    int mid = (st + end)/2;
    build(2*node, st, mid);
    build(2*node+1, mid+1, end);

    long sum = tree[2*node]->sum + tree[2*node+1]->sum;
    long pref = max(tree[2*node]->pref, tree[2*node]->sum + tree[2*node+1]->pref);
    long suff = max(tree[2*node+1]->suff, tree[2*node+1]->sum + tree[2*node]->suff);
    long ans = max(tree[2*node]->suff + tree[2*node+1]->pref, max(tree[2*node]->ans, tree[2*node+1]->ans));

    tree[node] = new Group(pref, suff, sum, ans);
}

void update(int node, int st, int end, int idx, long val) {
    if(st == end) {
        a[st] = val;

        if(a[st] <= 0)
            tree[node] = new Group(0, 0, a[st], 0);
        else
            tree[node] = new Group(a[st], a[st], a[st], a[st]);
        return;
    }

    int mid = (st + end)/2;
    if(idx <= mid)
        update(2*node, st, mid, idx, val);
    else
        update(2*node+1, mid+1, end, idx, val);
    
    long sum = tree[2*node]->sum + tree[2*node+1]->sum;
    long pref = max(tree[2*node]->pref, tree[2*node]->sum + tree[2*node+1]->pref);
    long suff = max(tree[2*node+1]->suff, tree[2*node+1]->sum + tree[2*node]->suff);
    long ans = max(tree[2*node]->suff + tree[2*node+1]->pref, max(tree[2*node]->ans, tree[2*node+1]->ans));

    tree[node] = new Group(pref, suff, sum, ans);
}

int main() {
    int n, m;
    cin>>n>>m;

    for(int i=0; i<n; i++)
        cin>>a[i];

    build(1, 0, n-1);
    cout<<tree[1]->ans<<endl;

    for(int i=0; i<m; i++) {
        int idx;
        long val;
        cin>>idx>>val;
        update(1, 0, n-1, idx, val);
        cout<<tree[1]->ans<<endl;
    }

    return 0;
}