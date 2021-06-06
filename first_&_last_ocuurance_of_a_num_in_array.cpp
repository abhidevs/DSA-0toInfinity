#include<bits/stdc++.h>
using namespace std;

int firstOcc(int arr[], int size, int pos, int key) {

    if(pos==size)
        return -1;

    if(arr[pos] == key) {
        return pos;
    }
    return firstOcc(arr, size, pos+1, key);
}

int lastOcc(int arr[], int size, int pos, int key) {

    if(pos==size)
        return -1;

    int restArray = lastOcc(arr, size, pos+1, key);

    if(restArray != -1)
        return restArray;

    if(arr[pos] == key)
        return pos;

    return -1;
}

int main() {

    int arr[] = {4, 2, 1, 2, 5, 2, 7};
    int key = 2;
    cout<<"First ocuurance of "<<key<<" - index "<<firstOcc(arr, 7, 0, key)<<endl;
    cout<<"Last ocuurance of "<<key<<" - index "<<lastOcc(arr, 7, 0, key)<<endl;
    return 0;
}