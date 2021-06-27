// Count number of binary strings without consecutive ones
// Formula :
// one[i] = zero[i]
// zero[i] = one[i-1] + zero[i-1]
//         = zero[i-2] + zero[i-1]
// This is same as formula of nth fibonacci number
// So, we can use the fibonacci formula for this problem

// Final Ans = zero[i] + one[i]
//           = zero[i] + zero[i-1]
//           = zero[i+1]
//           = Fib[n+1]

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int> fib(n+2, 0);
    fib[0] = 1;
    fib[1] = 1;

    for(int i=2; i<=n+1; i++)
        fib[i] = fib[i-1] + fib[i-2];

    cout<<fib[n+1];
    return 0;
}