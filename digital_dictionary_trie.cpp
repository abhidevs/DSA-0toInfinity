#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    Node* next[26];
    bool end;

    Node() {
        for(int i=0; i<26; i++)
            next[i] = NULL;
        end = false;
    }
};

class Trie {
    Node *root;
    public:
        Trie() {
            root = new Node();
        }

        void insertIntoTrie(string &s) {
            Node *it = root;
            for(auto c: s) {
                if(!it->next[c-'a'])
                    it->next[c-'a'] = new Node();
                it = it->next[c-'a'];
            }

            it->end = true;
        }

        void find(string &s) {
            Node *it = root;
            for(auto c: s) {
                if(!it->next[c-'a']) {
                    cout<<"No suggestions found"<<endl;
                    insertIntoTrie(s);
                    return;
                }

                it = it->next[c-'a'];
            }

            vector<string> res;
            printall(it, s, res, "");
            for(auto c: res)
                cout<<s<<c<<endl;
        }

        void printall(Node* it, string &s, vector<string> &res, string cur) {
            if(it == NULL)
                return;
            
            if(it->end)
                res.push_back(cur);

            for(int i=0; i<26; i++) {
                if(it->next[i])
                    printall(it->next[i], s, res, cur + char('a'+i));
            }
        }
};

int main() {
    Trie t;
    int n;
    cin>>n;

    vector<string> a(n);
    for(auto &s: a) {
        cin>>s;
        t.insertIntoTrie(s);
    }

    int query;
    cin>>query;
    while(query--) {
        string s;
        cin>>s;
        t.find(s);
    }

    return 0;
}