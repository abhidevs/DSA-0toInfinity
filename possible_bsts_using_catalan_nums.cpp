#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<Node*> constructBSTs(int start, int end) {
    vector<Node*> bsts;

    if(start > end) {
        bsts.push_back(NULL);
        return bsts;
    }

    for(int i=start; i<=end; i++) {
        vector<Node*> leftSubtrees = constructBSTs(start, i-1);
        vector<Node*> rightSubtrees = constructBSTs(i+1, end);

        for(int j=0; j<leftSubtrees.size(); j++) {
            Node* left = leftSubtrees[j];
            for(int k=0; k<rightSubtrees.size(); k++) {
                Node* right = rightSubtrees[k];
                Node* node = new Node(i);

                node->left = left;
                node->right = right;
                bsts.push_back(node);
            }
        }
    }

    return bsts;
}

void preorder(Node* root) {
    if(root == NULL) {
        return;
    }

    cout<<root->data<<' ';
    preorder(root->left);
    preorder(root->right);
}


int main() {

    vector<Node*> allBsts = constructBSTs(1, 3);

    for(int i=0; i<allBsts.size(); i++) {
        cout<<i+1<<" : ";
        preorder(allBsts[i]);
        cout<<endl;
    }

    return 0;
}