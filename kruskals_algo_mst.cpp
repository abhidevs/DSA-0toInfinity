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
        int u, v, w;
        cin>>u>>v>>w;
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());
    int cost = 0;

    for(auto i: edges) {
        int w = i[0];
        int u = i[1];
        int v = i[2];
        int x = findSet(u);
        int y = findSet(v);

        if(x == y)
            continue;
        else {
            cout<<u<<" "<<v<<endl;
            cost += w;
            unionSet(u, v);
        }
    }

    cout<<"cost: "<<cost<<endl;
    return 0;
}