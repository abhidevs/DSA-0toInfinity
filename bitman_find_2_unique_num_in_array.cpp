// Program to find 2 unique numbers in an array
// where all numbers except two, are present twice

#include<bits/stdc++.h>
using namespace std;

int getBit(int n, int pos) {
    return ((n & (1<<pos)) != 0);
}

void findUnique(int arr[], int n) {
    int xorsum = 0;

    for(int i=0; i<n; i++) {
        xorsum = xorsum^arr[i];
    }

    int tempxor = xorsum;
    int setbit = 0;
    int pos = 0;

    while(setbit != 1) {
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }

    int newxor = 0;
    for(int i=0; i<n; i++) {
        if(getBit(arr[i], pos-1)) {
            newxor = newxor^arr[i];
        }
    }

    cout<<newxor<<" "<<(tempxor^newxor);
}

int main() {
    int arr[] = {2, 4, 6, 7, 4, 9, 6, 2};

    findUnique(arr, 8);
    return 0;
}