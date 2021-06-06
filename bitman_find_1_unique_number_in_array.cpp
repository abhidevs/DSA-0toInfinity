// Program to find a unique number in an array
// where all numbers except one, are present twice

#include<bits/stdc++.h>
using namespace std;

int findUnique(int arr[], int n) {
    int xorsum = 0;
    for(int i=0; i<n; i++) {
        xorsum = xorsum^arr[i];
    }

    return xorsum;
}

int main() {
    int arr[] = {1, 3, 4, 4, 2, 3, 1};
    cout<<findUnique(arr, 7);

    return 0;
}