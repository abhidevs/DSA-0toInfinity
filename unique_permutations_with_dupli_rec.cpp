// Program to generate all unique permutation
// on an array of numbers even having duplicate values

#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> a, vector<vector<int>> &ans, int idx) {
    if(idx == a.size()-1) {
        ans.push_back(a);
        return;
    }

    for(int i=idx; i<a.size(); i++) {
        if(i != idx && a[i] == a[idx]) 
            continue;

        swap(a[i], a[idx]);
        helper(a, ans, idx+1);
    }
}

vector<vector<int>> permute(vector<int> nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    helper(nums, ans, 0);
    return ans;
}

int main() {

    int n;
    cin>>n;
    vector<int> a(n);

    for(auto &i : a)
        cin>>i;
    
    vector<vector<int>> ans = permute(a);

    for(auto v : ans) {
        for(auto i : v)
            cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}