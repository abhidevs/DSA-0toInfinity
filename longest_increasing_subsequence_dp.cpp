#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2, MOD = 1e9+7;

// Memoization approach in dp
// vector<int> dpTable(N, -1);

// int lis(vector<int> &a, int n) {
//     if(dpTable[n] != -1)
//         return dpTable[n];

//     dpTable[n] = 1;

//     for(int i=0; i<n; i++) {
//         if(a[n] > a[i])
//             dpTable[n] = max(dpTable[n], 1+lis(a, i));
//     }

//     return dpTable[n];
// }

int main() {
    
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];

    // Tabulation approach in dp
    vector<int> dpTable(n, 1);
    int ans = 0;

    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(a[i] > a[j])
                dpTable[i] = max(dpTable[i], 1+dpTable[j]);
            ans = max(ans, dpTable[i]);
        }
    }

    cout<<ans<<endl;
    return 0;
}