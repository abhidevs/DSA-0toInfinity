#include<bits/stdc++.h>
using namespace std;
int p = 32;
const int N = 1e5+3, MOD = 1e9+7;
vector<long long> powers(N);

long long calcHash(string s) {
    long long hash = 0;
    for(int i=0; i<s.length(); i++)
        hash = (hash + (s[i] - 'a' + 1) * powers[i]) % MOD;

    return hash;
}

int main() {
    powers[0] = 1;
    for(int i=1; i<N; i++)
        powers[i] = (powers[i-1] * p) % MOD;

    vector<string> strings = {"aa", "ab", "cc", "b", "cc", "aa", "abcdefghijklmnop"};
    vector<long long> hashes;

    for(auto e: strings)
        hashes.push_back(calcHash(e));

    sort(hashes.begin(), hashes.end());
    int distinct = 0;
    for(int i=0; i<hashes.size(); i++) {
        if(i == 0 || hashes[i] != hashes[i-1])
            distinct++;
    }

    cout<<distinct<<endl;
    return 0;
}