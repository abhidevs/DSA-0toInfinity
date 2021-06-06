#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = NULL;
        }
};

void insertAtHead(Node* &head, int val) {
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

void insertAtTail(Node* &head, int val) {
    Node* n = new Node(val);

    if(head == NULL) {
        head = n;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

void display(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void putEvenPosAfterOdd(Node* &head) {

    Node* odd = head;
    Node* even = head->next;
    Node* evenStart = even;

    while(odd->next != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        
        if(odd->next != NULL) {
            even->next = odd->next;
            even = even->next;
        }
    }

    odd->next = evenStart;
    if(odd->next != NULL) {
        even->next = NULL;
    }
}


int main() {

    Node* head = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    for(int i=0; i<7; i++) {
        insertAtTail(head, arr[i]);
    }

    display(head);
    putEvenPosAfterOdd(head);
    display(head);

    return 0;
}