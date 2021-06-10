#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

int main() {

    int k;
    cin>>k;

    vector<vi> a(k);

    rep(i, 0, k) {
        int size;
        cin>>size;

        a[i] = vector<int>(size);
        rep(j, 0, size) {
            cin>>a[i][j];
        }
    }

    vi idx(k, 0);
    priority_queue<pii, vii, greater<pii>> pq;

    rep(i, 0, k) {
        pq.push({a[i][0], i});
    }

    vi ans;

    while(!pq.empty()) {
        pii x = pq.top();
        pq.pop();
        ans.push_back(x.ff);
        
        if(idx[x.ss]+1 < a[x.ss].size()) {
            pq.push({a[x.ss][idx[x.ss]+1], x.ss});
        }

        idx[x.ss]++;
    }

    rep(i, 0, ans.size()) {
        cout<<ans[i]<<" ";
    }

    return 0;
}