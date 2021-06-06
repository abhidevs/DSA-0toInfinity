#include<bits/stdc++.h>
using namespace std;

int main() {
    string str = "31562";
    cout << str << endl;
    
    sort(str.begin(), str.end(), greater<int>());
    cout << str;

    return 0;
}