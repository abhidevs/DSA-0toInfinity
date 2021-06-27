#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];

    int curr = 0, maxTillNow = 0;
    for(int i=0; i<n; i++) {
        curr += a[i];
        maxTillNow = max(curr, maxTillNow);
        if(curr < 0)
            curr = 0;
    }

    cout<<maxTillNow<<endl;
    return 0;
}