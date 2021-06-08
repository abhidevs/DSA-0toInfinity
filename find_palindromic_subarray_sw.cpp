// subarray where concatinating all the elements form a palindrome using sliding window(sw)
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int num) {
    int temp = num, n = 0;
    
    while (temp > 0)
    {
        n = n*10 + temp%10;
        temp /= 10;
    }
    
    if(num == n) {
        return true;
    }
    return false;
}

int findPalindromicSubarr(vector<int> arr, int k) {
    int num = 0;

    for(int i=0; i<k; i++) {
        num = num*10 + arr[i];
    }

    if(isPalindrome(num)) {
        return 0;
    }

    for(int i=k; i<arr.size(); i++) {
        num = (num% (int)pow(10, k-1)) * 10 + arr[i];

        if(isPalindrome(num)) {
            return i-k+1;
        }
    }

    return -1;
}

int main() {

    vector<int> arr = {2, 3, 5, 1, 1 ,5};
    int k = 4;

    int ans = findPalindromicSubarr(arr, k);

    if(ans == -1) {
        cout<<"Palindromic subarray doesn't exist in this array"<<endl;
    }
    else
    {
        for(int i=ans; i<ans+k; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}