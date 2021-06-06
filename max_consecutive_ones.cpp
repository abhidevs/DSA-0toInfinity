#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    int k;
    cin>>n;
    cin>>k;
    vector<int> a(n);

    for(auto &i: a) {
        cin>>i;
    }

    int zeroCount = 0, i = 0, ans = 0;

    for(int j=0; j<n; j++) {
        if(a[j] == 0) {
            zeroCount++;
        }
        while(zeroCount > k) {
            if(a[i] == 0) {
                zeroCount--;
            }
            i++;
        }

        ans = max(ans, j-i+1);
    }

    cout<<ans;

    return 0;
}