#include<iostream>
#include<cmath>
using namespace std;

int main() {

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    bool prime = true;
    cin>>n;

    for(int i=2; i<=sqrt(n); i++) {
        if (n%i == 0)
        {
            prime = false;
            break;
        }
    }

    if (prime)
    {
        cout<<n<<" is a prime number";
    } else
    {
        cout<<n<<" is not a prime number";
    }
    
    return 0;
}