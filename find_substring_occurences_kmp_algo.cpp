#include<bits/stdc++.h>
using namespace std;

vector<int> getPrefix(string s) {
    int n = s.length();
    vector<int> pi(n, 0);

    for(int i=1; i<n; i++) {
        int j = pi[i-1];

        while(j>0 && s[i]!=s[j])
            j = pi[j-1];

        if(s[i] == s[j])
            j++;

        pi[i] = j;
    }

    return pi;
}

int main() {
    string str, substring;
    getline(cin, str);
    getline(cin, substring);
    vector<int> res = getPrefix(substring);

    // for(auto i: res)
    //     cout<<i<<" ";

    int pos = -1;
    int i=0, j=0;
    while(i<str.size()) {
        if(str[i] == substring[j]) {
            j++;
            i++;
        }
        else {
            if(j != 0)
                j = res[j-1];
            else
                i++;
        }
        
        if(j == substring.size()) {
            pos = i - substring.size();
            break;
        }
    }
    
    cout<<pos<<endl;
    return 0;
}