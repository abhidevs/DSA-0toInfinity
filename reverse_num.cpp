#include<iostream>
using namespace std;

int main() {

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, rem, temp, reversedNum = 0;
    cin>>n;
    temp = n;

    while(n) {
        rem = n%10;
        n /= 10;
        reversedNum = reversedNum*10 + rem;
    }
    
    cout<<"Reverse of "<<temp<<" is "<<reversedNum;

    return 0;
}