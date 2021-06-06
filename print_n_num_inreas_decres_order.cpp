#include<bits/stdc++.h>
using namespace std;

void printInDecOrder(int n) {
    if( n==0)
        return;

    cout<<n<<endl;
    printInDecOrder(n-1);
}

void printInIncOrder(int n) {
    if(n==0)
        return;

    printInIncOrder(n-1);
    cout<<n<<endl;
}

int main() {
    int n;
    cin>>n;
    
    printInDecOrder(n);
    printInIncOrder(n);

    return 0;
}