#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int num) {
    for(int j=2; j<=sqrt(num); j++) {
        if (num%j == 0)
        {
            return false;
        }
    }
    return true;
}

int main() {

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n1, n2, temp, i = 0;
    cin>>n1>>n2;

    if (n1>n2)
    {
        temp = n1;
        n1 = n2;
        n2 = temp;
    }
    temp = n1;
    
    int primes[n2-n1];

    for(; n1<=n2; n1++) {
        if (isPrime(n1))
        {
            primes[i++] = n1;
        }
    }

    cout<<"between "<<temp<<" and "<<n2<<" there are "<<i<<" prime numbers"<<endl;

    if (i) {
        for(int j=0; j<i; j++) {
            cout<<primes[j]<<" ";
        }
    }
    
    return 0;
}