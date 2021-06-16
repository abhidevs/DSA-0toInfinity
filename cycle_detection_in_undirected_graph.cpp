#include<bits/stdc++.h>
using namespace std;

bool isCycle(int src, vector<vector<int>> &adj, vector<bool> vis, int parent) {
    vis[src] = true;
    for(auto i: adj[src]) {
        if(i != parent) {
            if(vis[i])
                return true;
            if(!vis[i] && isCycle(i, adj, vis, src))
                return true;
        }
    }

    return false;
}

int main() {

    int n, m;
    cin>>n>>m;
    vector<vector<int>> adjList(n);

    for(int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool cycle = false;
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++) {
        if(!visited[i] && isCycle(i, adjList, visited, -1)) {
            cycle = true;
        }
    }

    if(cycle)
        cout<<"Cycle is present in the above graph";
    else
        cout<<"No cycle present in the above graph";

    return 0;
}