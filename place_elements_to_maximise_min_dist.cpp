// Binary search challenge 
#include<iostream>
#include<algorithm>
using namespace std;

bool isFeasible(int mid, int arr[], int n, int k) {
    int pos = arr[0], elements = 1;

    for(int i=1; i<n; i++) {
        if(arr[i] - pos >= mid) {
            pos = arr[i];
            elements++;
            if(elements == k) {
                return true;
            }
        }
    }

    return false;
}

int largestMinDist(int arr[], int n, int k) {
    sort(arr, arr+n);

    int res = -1;
    int left = 1, right = arr[n-1];

    while(left < right) {
        int mid = (left+right)/2;
        if(isFeasible(mid, arr, n, k)) {
            res = max(res, mid);
            left = mid+1;
        }
        else
        {
            right = mid;
        }
    }

    return res;
}

int main() {

    int arr[] = {1, 2, 8, 4, 9};
    int n = 5;
    int k = 3;

    cout<<"Largest minimum distance is : "<<largestMinDist(arr, n, k)<<endl;

    return 0;
}