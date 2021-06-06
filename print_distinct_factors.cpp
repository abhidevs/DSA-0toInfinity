#include<bits/stdc++.h>
using namespace std;

bool exist(int n, vector<int> arr) {
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] == n) {
            return true;
        }
    }
    
    return false;
}

vector<int> getDistinctFactors(int n) {
    vector<int> a;
    int idx = 0;

    // time complexity - O(n)
    // int limit = n/2;
    // for(int i=1; i<=limit; i++) {
    //     if(n%i == 0 && !exist(i, a)) {
    //         if(a.size() == 1) {
    //             limit = n/i;
    //         }
    //         a.push_back(i);
    //     }
    // }

    // a.push_back(n);

    // better approach, time complexity - O(sqrt(n))
    for(int i=1; i<=sqrt(n); i++) {
        if(n%i == 0) {
            if(!exist(i, a))
                a.insert(a.begin() + idx, i);

            if(!exist(n/i, a))
                a.insert(a.begin() + ++idx, n/i);
        }
    }
    return a;
}

int main() {

    int n;
    cin>>n;

    vector<int> ans = getDistinctFactors(n);

    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }

    return 0;
}