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

Node* insertToBST(Node* root, int val) {
    if(root == NULL) {
        return new Node(val);
    }

    if(val < root->data) {
        root->left = insertToBST(root->left, val);
    }
    else {
        root->right = insertToBST(root->right, val);
    }

    return root;
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main() {

    Node *root = NULL;
    root = insertToBST(root, 5);
    insertToBST(root, 1);
    insertToBST(root, 3);
    insertToBST(root, 4);
    insertToBST(root, 2);
    insertToBST(root, 7);

    inorder(root);

    return 0;
}