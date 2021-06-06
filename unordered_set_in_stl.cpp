#include<iostream>
#include<unordered_set>
using namespace std;

int main() {

    unordered_set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(1);
    s.insert(4);
    s.insert(2);

    for(auto i: s) {
        cout<<i<<" ";
    }
    cout<<endl;

    s.erase(2);

    for(auto i: s) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}