#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+2;

// DP Memoization approach
// vector<vector<int>> dpTable(N, vector<int>(N, -1));

// int lcs(string &s1, string &s2, int n, int m) {
//     if(n == 0 || m == 0)
//         return 0;

//     if(dpTable[n][m] != -1)
//         return dpTable[n][m];

//     if(s1[n-1] == s2[m-1])
//         dpTable[n][m] = 1 + lcs(s1, s2, n-1, m-1);
//     else
//         dpTable[n][m] = max(lcs(s1, s2, n, m-1), lcs(s1, s2, n-1, m));
    
//     return dpTable[n][m];
// }

int main() {

    string s1, s2;
    cin>>s1>>s2;

    int n = s1.size(), m = s2.size();

    // DP Tabulation approach, Bottom up
    vector<vector<int>> dpTable(n+1, vector<int>(m+1, -1));

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(i == 0 || j == 0) {
                dpTable[i][j] = 0;
                continue;
            }

            if(s1[i-1] == s2[j-1])
                dpTable[i][j] = 1 + dpTable[i-1][j-1];
            else
                dpTable[i][j] = max(dpTable[i-1][j], dpTable[i][j-1]);
        }
    }

    cout<<dpTable[n][m]<<endl;
    return 0;
}