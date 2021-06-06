#include<bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin>>s;
    vector<int> dict(256, -1);
    int maxLength = 0, start = -1;

    for(int i=0; i<s.size(); i++) {
        if(dict[s[i]] > start) {
            start = dict[s[i]];
        }
        dict[s[i]] = i;
        maxLength = max(maxLength, i-start);
    }

    cout<<maxLength<<endl;

    return 0;
}