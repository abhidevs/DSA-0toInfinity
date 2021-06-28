// Longest common subsequence with 3 strings using DP
#include<bits/stdc++.h>
using namespace std;

int dpTable[205][205][205];

int LCS3(string &s1, string &s2, string &s3, int i, int j, int k) {
    if(i == 0 || j == 0 || k == 0)
        return 0;

    if(dpTable[i][j][k] != -1)
        return dpTable[i][j][k];

    if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]) {
        return dpTable[i][j][k] = 1 + LCS3(s1, s2, s3, i-1, j-1, k-1);
    }

    int l = LCS3(s1, s2, s3, i-1, j, k);
    int r = LCS3(s1, s2, s3, i, j-1, k);
    int p = LCS3(s1, s2, s3, i, j, k-1);
    return dpTable[i][j][k] = max({l, r, p});
}

int main() {
    memset(dpTable, -1, sizeof(dpTable));
    string s1, s2, s3;
    cin>>s1>>s2>>s3;

    cout<<LCS3(s1,s2, s3, s1.size(), s2.size(), s3.size());
    return 0;
}