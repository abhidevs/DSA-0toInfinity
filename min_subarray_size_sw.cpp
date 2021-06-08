// Min subarray size for sum>x using sliding window(sw)
#include<bits/stdc++.h>
using namespace std;

int minSubarrayWithSum(int arr[], int n, int x) {
    int sum = 0, minLength = n+1;
    int start = 0, end = 0;

    while(end < n) {
        while(sum <= x &&end < n) {
            sum += arr[end++];
        }

        while(sum > x) {
            if(end - start < minLength) {
                minLength = end - start;
            }
            sum -= arr[start++];
        }
    }

    return minLength;
}

int main() {

    int arr[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n = 6;

    int minLength = minSubarrayWithSum(arr, n, x);
    if(minLength == n+1) {
        cout<<"No such subarray exist in the array"<<endl;
    } else
    {
        cout<<"smallest length subarray is length "<<minLength<<endl;
    }
    
    return 0;
}