#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+2;

// Memoization approach in dp
// vector<vector<int>> combs(N, vector<int>(N, -1));

// int waysOfCoinChange(vector<int> &a, int n, int x) {
//     if(x == 0)
//         return 1;
//     if(x<0)
//         return 0;
    
//     if(n <= 0)
//         return 0;

//     if(combs[n][x] != -1)
//         return combs[n][x];
    
//     return combs[n][x] = waysOfCoinChange(a, n, x-a[n-1]) + waysOfCoinChange(a, n-1, x);
// }

int main() {

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    int x;
    cin>>x;
    
    // Tabulation approach in dp
    vector<vector<int>> combs(n+1, vector<int>(x+1, 0));
    combs[0][0] = 1;
    for(int i=1; i<n+1; i++) {
        for(int j=0; j<x+1; j++) {
            if(j-a[i-1] >= 0)
                combs[i][j] += combs[i][j-a[i-1]];

            combs[i][j] += combs[i-1][j];
        }
    }
    
    cout<<combs[n][x];
    return 0;
}