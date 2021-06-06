#include<bits/stdc++.h>
using namespace std;

string keypadArr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keypad(string s, string ans) {
    if(s.length() == 0) {
        cout<<ans<<endl;
        return;
    }

    char ch = s[0];
    string letters = keypadArr[ch-'0'];
    string ros = s.substr(1);

    for(int i=0; i<letters.length(); i++) {
        keypad(ros, ans + letters[i]);
    }
}

int main() {

    keypad("23", "");
    return 0;
}