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

Node* searchInBST(Node* root, int key) {
    if(root == NULL) {
        return NULL;
    }

    if(root->data == key) {
        return root;
    }
    if(root->data > key) {
        return searchInBST(root->left, key);
    }
    return searchInBST(root->right, key);
}

Node* inorderSucc(Node* root) {
    Node* curr = root;

    while(curr && curr->left!=NULL) {
        curr = curr->left;
    }
    return curr;
}

// Deletion in a BST
Node* deleteInBST(Node* root, int key) {

    if(key < root->data) {
        root->left = deleteInBST(root->left, key);
    }
    else if(key > root->data) {
        root->right = deleteInBST(root->right, key);
    }
    else {
        if(root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
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

    if(searchInBST(root, 3) == NULL) {
        cout<<"Key doesn't exist"<<endl;
    } else
    {
        cout<<"Key found"<<endl;
    }

    root = deleteInBST(root, 3);
    inorder(root);
    cout<<endl;
    
    if(searchInBST(root, 4) == NULL) {
        cout<<"Key doesn't exist"<<endl;
    } else
    {
        cout<<"Key found"<<endl;
    }

    return 0;
}