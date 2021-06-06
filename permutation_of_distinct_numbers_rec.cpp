#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void permute(vector<int> &a, int idx) {
    if(idx == a.size()-1) {
        ans.push_back(a);
        return;
    }

    for(int i = idx; i<a.size(); i++) {
        swap(a[i], a[idx]);
        permute(a, idx+1);
        swap(a[i], a[idx]);
    }

    return;
}

int main() {
    
    int n;
    cin>>n;
    vector<int> a(n);

    for(auto &i : a)
        cin>>i;
    
    permute(a, 0);

    // alternative shorter method using predefined functions
    // sort(a.begin(), a.end());
    // do {
    //     ans.push_back(a);
    // } while(next_permutation(a.begin(), a.end()));
    
    for(auto v : ans) {
        for(auto i : v)
            cout<<i<<" ";
        cout<<"\n";
    }

    return 0;
}