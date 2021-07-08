// Print the indices of occurences of a substring in the mainstring
// time complexity O(ms * ss),  ms = mainstring size, ss = substring size
#include<bits/stdc++.h>
using namespace std;

int main() {
    string mainStr, subStr;
    getline(cin, mainStr);
    getline(cin, subStr);

    int ms = mainStr.size(), ss = subStr.size();
    for(int i=0; i<ms-ss+1; i++) {
        if(mainStr.substr(i, ss) == subStr)
            cout<<"found at index "<<i<<endl;
    }

    return 0;
}