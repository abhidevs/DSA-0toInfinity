#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 102, MOD = 1e9+7;
int a[N];
vector<vector<int>> dpTable(N, vector<int>(N, -1));

// DP Memoization approach
// int mcm(int i, int j) {
//     if(i == j)
//         return 0;
    
//     if(dpTable[i][j] != -1)
//         return dpTable[i][j];
    
//     dpTable[i][j] = MOD;
//     for(int k=i; k<j; k++)
//         dpTable[i][j] = min(dpTable[i][j], mcm(i, k) + mcm(k+1, j) + a[i-1]*a[k]*a[j]);

//     return dpTable[i][j];
// }

int main() {

    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>a[i];

    // DP Tabulation approach
    for(int i=1; i<n; i++)
        dpTable[i][i] = 0;

    for(int l=2; l<n; l++) {
        for(int i=1; i<n-l+1; i++) {
            int j=i+l-1;
            dpTable[i][j] = MOD;
            for(int k=i; k<j; k++)
                dpTable[i][j] = min(dpTable[i][j], dpTable[i][k] + dpTable[k+1][j] + a[i-1]*a[k]*a[j]);
        }
    }

    cout<<dpTable[1][n-1]<<endl;
    return 0;
}