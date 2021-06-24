#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
// int fibs[N];

// Using concept of Memoization in DP
// int fib(int n) {
//     if(n == 0 || n == 1)
//         return 0;
//     if(n == 2)
//         return 1;

//     if(fibs[n] != -1)
//         return fibs[n];

//     fibs[n] = fib(n-1) + fib(n-2);
//     return fibs[n];
// }

int main() {

    int n;
    cin>>n;

    // Using concept of tabulation in DP
    vector<int> fibs(n+1);
    fibs[0] = 0;
    fibs[1] = 0;
    fibs[2] = 1;

    for(int i=3; i<=n; i++) {
        fibs[i] = fibs[i-1] + fibs[i-2];
    }

    cout<<fibs[n]<<endl;
    return 0;
}