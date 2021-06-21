#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 6;
vector<int> parent(N);
vector<int> size(N);

void makeSet(int v) {
    parent[v] = v;
    size[v] = 1;
}

int findSet(int v) {
    if(v == parent[v])
        return v;
    return parent[v] = findSet(parent[v]);
}

void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);

    if(a != b) {
        if(size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main() {

    for(int i=0; i<N; i++) {
        makeSet(i);
    }

    int n, m;
    cin>>n>>m;
    vector<vector<int>> edges;

    for(int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        edges.push_back({u, v});
    }

    bool cycle = false;
    for(auto i: edges) {
        int u = i[0];
        int v = i[1];
        int x = findSet(u);
        int y = findSet(v);

        if(x == y)
            cycle = true;
        else
            unionSet(u, v);
    }

    if(cycle)
        cout<<"Cycle is present in the above graph";
    else
        cout<<"No cycle prsent in the given graph";

    return 0;
}