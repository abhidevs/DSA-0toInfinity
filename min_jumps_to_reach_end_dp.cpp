#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main() {

    int n;
    cin>>n;
    vector<int> arr(n);

    for(auto &i : arr)
        cin>>i;

    vector<int> jumps(n, INF);
    if(arr[0] == 0) {
        cout<<"Not possible"<<endl;
        return 0;
    }

    jumps[0] = 0;
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(i <= (j + arr[j]))
                jumps[i] = min(jumps[i], jumps[j]+1);
        }
    }

    cout<<jumps[n-1]<<endl;
    return 0;
}