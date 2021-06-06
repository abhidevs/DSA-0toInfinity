#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh) + 1;
}

bool isBalanced(Node* root) {
    // Not optimized approach, time complexity O(n^2)
    if(root == NULL) {
        return true;
    }

    if(!isBalanced(root->left)) {
        return false;
    }
    if(!isBalanced(root->right)) {
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return (abs(lh-rh)<=1);
}

bool isBalancedOp(Node* root, int* height) {
    // Optimized approach, time complexity O(n)
    if(root == NULL) {
        return true;
    }

    int lh = 0, rh = 0;
    if(!isBalancedOp(root->left, &lh)) {
        return false;
    }
    if(!isBalancedOp(root->right, &rh)) {
        return false;
    }

    *height = max(lh, rh) + 1;
    
    return (abs(lh-rh) <= 1);
}


int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);

    if(isBalanced(root2)) {
        cout<<"Balanced tree"<<endl;
    }
    else
    {
        cout<<"Unbalanced tree"<<endl;
    }

    int height = 0;

    if(isBalancedOp(root2, &height)) {
        cout<<"Balanced tree"<<endl;
    }
    else
    {
        cout<<"Unbalanced tree"<<endl;
    }
    
    return 0;
}