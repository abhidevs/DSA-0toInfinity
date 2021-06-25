#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2, MOD = 1e9 + 7;

// Memoization approach in dp
// vector<int> squares(N, MOD);

// int minSquares(int n) {
//     if(n == 0 || n == 1 || n == 2 || n == 3)
//         return n;

//     if(squares[n] != MOD)
//         return squares[n];

//     for(int i=1; i*i<=n; i++)
//         squares[n] = min(squares[n], 1+minSquares(n - i*i));
    
//     return squares[n];
// }

int main() {

    int n;
    cin>>n;

    // Alternative dp approach, Bottom up

    vector<int> squares(n+1, MOD);

    squares[0] = 0;
    squares[1] = 1;
    squares[2] = 2;
    squares[3] = 3;

    for(int i=1; i*i<=n; i++) {
        for(int j=0; i*i+j<=n; j++)
            squares[i*i+j] = min(squares[i*i+j], 1+squares[j]);
    }

    cout<<squares[n];
    return 0;
}