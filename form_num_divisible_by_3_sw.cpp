// form a number that is divisible by 3 from a subarray using sliding window(sw)
#include<bits/stdc++.h>
using namespace std;

void formNumFromSubarr(vector<int> arr, int k) {
    pair<int, int> ans;
    int sum = 0;
    
    for(int i=0; i<k; i++) {
        sum += arr[i];
    }

    bool found = false;

    if(sum % 3 == 0) {
        ans = make_pair(0, k-1);
        found = true;
    }

    for(int i=k; i<arr.size(); i++) {
        if(found) {
            break;
        }

        sum += (arr[i] - arr[i-k]);

        if(sum % 3 == 0) {
            ans = make_pair(i-k+1, i);
            found = true;
        }
    }

    if(found) {
        for(int i=ans.first; i<=ans.second; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    } else
    {
        cout<<"No such subarray exists that is divisble by 3"<<endl;
    }
    
}

int main() {

    vector<int> arr = {84, 23, 45, 12, 56, 82};
    int k = 3;

    formNumFromSubarr(arr, k);

    return 0;
}