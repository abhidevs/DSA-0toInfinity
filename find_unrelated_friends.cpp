// Find number of possible combinations of unrelated friends group of 2 people 
// from the given graph
// Using connected component approach

#include<bits/stdc++.h>
using namespace std;

vector<bool> visited;
int n, m;
vector<vector<int>> adj;
vector<int> components;

int getComp(int idx) {
    if(visited[idx]) {
        return 0;
    }
    visited[idx] = true;
    int ans = 1;
    
    for(auto i: adj[idx]) {
        if(!visited[i]) {
            ans += getComp(i);
            visited[i] = true;
        }
    }

    return ans;
}

int main() {

    cin>>n>>m;
    adj = vector<vector<int>>(n);
    visited = vector<bool>(n);

    for(int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            components.push_back(getComp(i));
        }
    }

    int ans = 0;
    for(auto i: components) {
        ans += i*(n-i);
    }

    cout<<ans/2<<endl;
    return 0;
}