#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> colors;
bool bipart;

void setColor(int u, int current) {
    if(colors[u] != -1 && colors[u] != current) {
        bipart = false;
        return;
    }

    colors[u] = current;
    if(visited[u])
        return;
    
    visited[u] = true;
    for(auto i: adj[u]) {
        setColor(i, current xor 1);
    }
}

int main() {

    bipart = true;
    int n, m;
    cin>>n>>m;

    adj = vector<vector<int>>(n);
    visited = vector<bool>(n, false);
    colors = vector<int>(n, -1);

    for(int i=0;i<m; i++) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            setColor(i, 0);
        }
    }

    if(bipart)
        cout<<"Given graph is bipartite";
    else
        cout<<"Given graph is not bipartite";

    return 0;
}