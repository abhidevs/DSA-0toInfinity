#include<bits/stdc++.h>
using namespace std;
int intSize = 32;

class Node {
    public:
        Node *next[2];
        
        Node() {
            for(int i=0; i<2; i++) {
                next[i] = NULL;
            }
        }
};

Node* trie;

void insertIntoTrie(int num) {
    Node* it = trie;
    for(int i=intSize-1; i>=0; i--) {
        int curBit = (num >> i) & 1;
        if(!it->next[curBit])
            it->next[curBit] = new Node();
        
        it = it->next[curBit];
    }
}

int query(int num) {
    Node* it = trie;
    int ans = 0;

    for(int i=intSize-1; i>=0; i--) {
        int curBit = (num >> i) & 1;
        int opposite = curBit xor 1;

        if(it->next[opposite]) {
            it = it->next[opposite];
            ans |= 1 << i;
        }
        else
        {
            it = it->next[opposite xor 1];
        }    
    }

    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> a(n);

    for(int i=0; i<n; i++)
        cin>>a[i];

    trie = new Node();
    insertIntoTrie(0);
    vector<int> rmax(n+1, 0);
    int R = 0;

    for(int i=n-1; i>=0; i--) {
        R = R xor a[i];
        if(i != n-1) {
            rmax[i] = max(rmax[i+1], query(R));
            insertIntoTrie(R);
        }
        else
        {
            rmax[i] = query(R);
            insertIntoTrie(R);
        }
    }

    free(trie);
    trie = new Node();
    insertIntoTrie(0);
    int ans = 0;
    int L = 0;

    for(int i=0; i<n; i++) {
        L = L xor a[i];
        ans = max(ans, rmax[i+1] + query(L));
        insertIntoTrie(L);
    }

    cout<<ans<<endl;
    return 0;
}