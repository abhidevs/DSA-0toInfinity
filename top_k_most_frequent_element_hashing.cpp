#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];

    map<int, int> freq;
    for(int i=0; i<n; i++) {
        int presentSize = freq.size();
        if(freq[a[i]] == 0 && presentSize == k)
            break;
        freq[a[i]]++;
    }

    vector<pair<int, int>> ans;
    map<int, int> :: iterator it;

    for(it = freq.begin(); it!=freq.end(); it++) {
        if(it->second != 0)
            ans.push_back({it->second, it->first});
    }

    sort(ans.begin(), ans.end(), greater<pair<int, int>>());
    vector<pair<int, int>> :: iterator it1;

    for(it1=ans.begin(); it1!=ans.end(); it1++)
        cout<<it1->second<<" "<<it1->first<<endl;

    return 0;
}