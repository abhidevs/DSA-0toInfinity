#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+2, MOD = 1e9+7;
int val[N], wt[N];

vector<vector<int>> dpTable(N, vector<int>(N, -1));

int knapsack(int n, int w) {
    if(w<=0)
        return 0;

    if(n<=0)
        return 0;

    if(dpTable[n][w] != -1)
        return dpTable[n][w];

    if(wt[n-1] > w)
        dpTable[n][w] = knapsack(n-1, w);
    else
        dpTable[n][w] = max(knapsack(n-1, w), knapsack(n-1, w - wt[n-1]) + val[n-1]);
    
    return dpTable[n][w];
}

int main() {

    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>wt[i];

    for(int i=0; i<n; i++)
        cin>>val[i];
    
    int w;
    cin>>w;

    cout<<knapsack(n, w);
    return 0;
}