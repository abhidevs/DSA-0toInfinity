#include<bits/stdc++.h>
using namespace std;

vector<int> a;
int dpTable[100][100];

int OGS(int i, int j) {
    if(i == j)
        return a[i];

    if(i>j)
        return 0;

    if(dpTable[i][j] != -1)
        return dpTable[i][j];
    
    int l = a[i] + min(OGS(i+2, j), OGS(i+1, j-1));
    int r = a[j] + min(OGS(i, j-2), OGS(i+1, j-1));

    return dpTable[i][j] = max(l, r);
}

int main() {

    int n;
    cin>>n;
    memset(dpTable, -1, sizeof(dpTable));

    a = vector<int>(n);
    for(auto &i : a)
        cin>>i;
    
    cout<<OGS(0, n-1);
    return 0;
}