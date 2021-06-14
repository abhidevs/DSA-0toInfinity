#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int> a(n);
    for(auto &i: a)
        cin>>i;

    sort(a.begin(), a.end());
    long long minDiff = 0, maxDiff = 0;

    for(int i=0; i<n/2; i++) {
        // maxDiff += (a[i+n/2] - a[i]); // alternative approach
        maxDiff += (a[n-i-1] - a[i]);
        minDiff += (a[2*i+1] - a[2*i]);
    }

    cout<<"minimum difference : "<<minDiff<<endl;
    cout<<"maximum difference : "<<maxDiff<<endl;
    return 0;
}