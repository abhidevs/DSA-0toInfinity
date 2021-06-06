#include<bits/stdc++.h>
using namespace std;

void substrWithAscii(string s, string ans) {
    if(s.length() == 0) {
        cout<<"\""<<ans<<"\""<<endl;
        return;
    }

    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);
    
    substrWithAscii(ros, ans);
    substrWithAscii(ros, ans+ch);
    substrWithAscii(ros, ans+to_string(code));
}

int main() {

    substrWithAscii("AB", "");
    return 0;
}