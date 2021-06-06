#include<iostream>
#include<set>
using namespace std;

int main() {

    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);

    for(auto i: s) {
        cout<<i<<" ";
    }
    cout<<endl;

    s.erase(2);
    s.erase(s.begin());

    for(auto i: s) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}