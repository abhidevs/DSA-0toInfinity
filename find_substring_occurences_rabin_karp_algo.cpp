#include<bits/stdc++.h>
using namespace std;
int p = 30;
const int N = 1e5+7, MOD = 1e9+7;
vector<long long> powers(N);

int main() {
    string str, substring;
    getline(cin, str);
    getline(cin, substring);
    int n = str.length(), s = substring.length();
    vector<long long> hash(n+1, 0);

    powers[0] = 1;
    for(int i=1; i<N; i++) {
        powers[i] = (powers[i-1] * p) % MOD;
    }

    for(int i=0; i<n; i++) {
        hash[i+1] = (hash[i] + (str[i] - 'a' + 1) * powers[i]) % MOD;
    }

    long long substrHash = 0;
    for(int i=0; i<s; i++) {
        substrHash = (substrHash + (substring[i] - 'a' + 1) * powers[i]) % MOD;
    }

    for(int i=0; i+s-1<n; i++) {
        long long currHash = (hash[i+s] - hash[i] + MOD) % MOD;
        if(currHash == (substrHash * powers[i]) % MOD) {
            cout<<"substring found at index "<<i<<endl;
        }
    }

    return 0;
}