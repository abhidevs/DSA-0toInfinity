#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
        TrieNode *next[2];
        TrieNode() {
            next[0] = NULL;
            next[1] = NULL;
        }
};

TrieNode* buildTrie(vector<int> &a) {
    TrieNode *root = new TrieNode();
    int n = a.size();

    for(int i=0; i<n; i++) {
        int num = a[i];
        TrieNode* cur = root;

        for(int i=31; i>=0; i--) {
            int bit = num>>i & 1;
            if(cur->next[bit] == NULL)
                cur->next[bit] = new TrieNode();

            cur = cur->next[bit];
        }
    }

    return root;
}

int helper(TrieNode *root, vector<int> &a) {
    int res = 0;

    for(int i=0; i<a.size(); i++) {
        int num = a[i];
        TrieNode *it = root;
        int curMax = 0;

        for(int i=31; i>=0; i--) {
            int bit = (num >> i) & 1 ? 0 : 1;
            if(it->next[bit]) {
                curMax <<= 1;
                curMax |= 1;
                it = it->next[bit];
            }
            else
            {
                curMax <<= 1;
                curMax |= 0;
                it = it->next[bit xor 1];
            }
        }

        res = max(res, curMax);
    }

    return res;
}

int main() {
    vector<int> a = {3, 10, 5, 15, 2};
    TrieNode *root = buildTrie(a);

    cout<<helper(root, a);
    return 0;
}