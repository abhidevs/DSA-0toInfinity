#include<bits/stdc++.h>
using namespace std;

int getBit(int n, int pos) {
    return ((n & (1<<pos)) != 0);
}

int setBit(int n, int pos) {
    return (n | (1<<pos));
}

int clearBit(int n, int pos) {
    int mask = ~(1<<pos);
    return (n & mask);
}

int updateBit(int n, int pos, int val) {
    int mask = ~(1<<pos);
    n = n & mask;
    return (n | (val<<pos));
}

int main() {
    cout<<"getBit() - "<<getBit(6, 3)<<endl;
    cout<<"setBit() - "<<setBit(6, 0)<<endl;
    cout<<"clearBit() - "<<clearBit(6, 2)<<endl;
    cout<<"updateBit() - "<<updateBit(6, 3, 1)<<endl;

    return 0;
}