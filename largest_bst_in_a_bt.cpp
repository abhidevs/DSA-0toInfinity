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

struct Info {
    int size;
    int max;
    int min;
    int ans;
    bool isBst;
};

Info largestBSTinBT(Node* root) {
    if(root == NULL) {
        return {0, INT_MIN, INT_MAX, 0, true};
    }

    if(root->left == NULL && root->right == NULL) {
        return {1, root->data, root->data, 1, true};
    }

    Info leftInfo = largestBSTinBT(root->left);
    Info rightInfo = largestBSTinBT(root->right);

    Info current;
    current.size = (1 + leftInfo.size + rightInfo.size);

    if(leftInfo.isBst && rightInfo.isBst && leftInfo.max < root->data && rightInfo.min > root->data) {
        current.min = min(leftInfo.min, min(rightInfo.min, root->data));
        current.max = max(rightInfo.max, max(leftInfo.max, root->data));

        current.ans = current.size;
        current.isBst = true;

        return current;
    }

    current.ans = max(leftInfo.ans, rightInfo.ans);
    current.isBst = false;
    return current;
}


int main() {

    Node* root = new Node(15);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(5);

    cout<<"Largest BST in BT : "<<largestBSTinBT(root).ans<<endl;

    return 0;
}