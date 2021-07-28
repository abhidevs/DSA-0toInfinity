#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,
                                    tree_order_statistics_node_update>;

int main() {
    int q; cin>>q;
    oset<int> s;

    while(q--) {
        int c, t; cin>>c;

        switch(c) {
            case 1:
                cin>>t;
                s.insert(t);
                break;

            case 2:
                cin>>t;
                cout<<*s.find_by_order(t)<<endl;
                break;

            case 3:
                cin>>t;
                cout<<s.order_of_key(t)<<endl;
                break;

            default:
                cout<<"Wrong input\n";
                cout<<"Enter 1 to insert value\n2 for getting kth element\n3 for number of smaller elements than k\n";
                break;
        }
    }
    
    return 0;
}