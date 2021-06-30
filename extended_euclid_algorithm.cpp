#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2, MOD = 1e9+7;

struct triplet {
    int x, y, gcd;
};

triplet extendedEucid(int a, int b) {
    if(b==0) {
        triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }

    triplet smallAns = extendedEucid(b, a%b);
    triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b) * smallAns.y;
    
    return ans;
}

int main() {
    int a, b;
    cin>>a>>b;

    triplet ans = extendedEucid(a, b);
    cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<endl;

    return 0;
}