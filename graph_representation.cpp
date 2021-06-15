#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define rep(i, a, b) for(int i=a; i<b; i++)

const int N = 1e5+2, MOD = 1e9+7;
vvi adjl(N);

int main() {
    // Adjacency Matrix implementation
    int n, m;
    cin>>n>>m;

    vvi adjm(n+1, vi(n+1, 0));
    rep(i, 0, m) {
        int x, y;
        cin>>x>>y;

        adjm[x][y] = 1;
        adjm[y][x] = 1;
    }

    cout<<"adjacency matrix of above graph:"<<endl;
    rep(i, 1, n+1) {
        rep(j, 1, n+1)
            cout<<adjm[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl<<endl;

    // Adjacency List implementation
    cin>>n>>m;
    rep(i, 0, m) {
        int x, y;
        cin>>x>>y;

        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }
    
    cout<<"adjacency list of the above graph:"<<endl;
    rep(i, 1, n+1) {
        cout<<i<<" -> ";
        for(int x: adjl[i])
            cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}