// Time complexity of getting fibonacci series using dp is O(n)
// So when n > 10^8 then it will give a time limit error(tle)
// Using matrix exponentiation we can compute fibonacci series upto n number
// in O(log n) time

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+2, MOD = 1e9+7;

// function to multiply to square matrix
vector<vector<int>> multiplyMatrix(vector<vector<int>> &a, vector<vector<int>> &b) {
    int sz = a.size();
    vector<vector<int>> ans(sz, vector<int>(sz, 0));

    for(int i=0; i<sz; i++) {
        for(int j=0; j<sz; j++) {
            for(int k=0; k<sz; k++)
                ans[i][j] += a[i][k] * b[k][j];
        }
    }

    return ans;
}

// function for matrix exponentiation
vector<vector<int>> matrixExpo(vector<vector<int>> &a, int n) {
    if(n == 0) {
        int sz = a.size();
        vector<vector<int>> ans(sz, vector<int>(sz, 0));

        for(int i=0; i<sz; i++)
            ans[i][i] = 1;

        return ans;
    }

    if(n == 1)
        return a;

    vector<vector<int>> temp = matrixExpo(a, n/2);
    vector<vector<int>> ans = multiplyMatrix(temp, temp);

    if(n&1)
        ans = multiplyMatrix(ans, a);

    return ans;
}

int main() {
    int n;
    cin>>n;

    vector<vector<int>> a = {{1, 1}, {1, 0}};
    vector<vector<int>> ans = matrixExpo(a, n);
    
    int sz = ans.size();
    for(int i=0; i<sz; i++) {
        for(int j=0; j<sz; j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }

    cout<<n<<"th fibonacci number is "<<ans[0][1];
    return 0;
}