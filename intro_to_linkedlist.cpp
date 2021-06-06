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

bool search(Node* head, int key) {
    Node* temp = head;
    while(temp != NULL) {
        if(temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteNode(Node* &head, int val) {
    Node* temp = head;

    if(head == NULL) {
        return;
    }

    if(temp->data == val) {
        Node* toDelete = temp;
        head = head->next;
        delete toDelete;
        return;
    }

    if(temp->next == NULL && temp->data != val) {
        return;
    }

    while(temp->next->data != val) {
        temp = temp->next;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    
    delete toDelete;
}

void deleteAtHead(Node* &head) {
    Node* toDelete = head;
    head = head->next;

    delete toDelete;
}

// iterative approach
Node* reverse(Node* &head) {
    Node* prevPtr = NULL;
    Node* currPtr = head;
    Node* nextPtr;

    while(currPtr != NULL) {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
    }

    return prevPtr;
}

// recursive approach
Node* reverseRec(Node* &head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* newHead = reverseRec(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

Node* reverseKnodes(Node* &head, int k) {
    Node* prevPtr = NULL;
    Node* currPtr = head;
    Node* nextPtr;

    int count = 0;
    
    while(currPtr!=NULL && count<k) {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
        count++;
    }

    if(nextPtr != NULL) {
        head->next = reverseKnodes(nextPtr, k);
    }

    return prevPtr;
}

void makeCycle(Node* &head, int pos) {
    Node* temp = head;
    Node* startNode;
    int count = 1;

    while(temp->next != NULL) {
        if(count == pos) {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }

    temp->next = startNode;
}

bool detectCycle(Node* &head) {
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow) {
            return true;
        }
    }

    return false;
}

void removeCycle(Node* &head) {
    Node* slow = head;
    Node* fast = head;

    do {
        slow = slow->next;
        fast = fast->next->next;
    } while(slow!=fast);

    fast = head;

    while(slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
}

int length(Node *head) {
    int l=0;
    Node* temp = head;
    
    while(temp!=NULL) {
        l++;
        temp = temp->next;
    }

    return l;
}

Node* appendKnodesToStart(Node* &head, int k) {
    Node* newHead;
    Node* newTail;
    Node* tail = head;

    int l = length(head);
    k = k%l;
    int count = 1;

    while(tail->next != NULL) {
        if(count == l-k) {
            newTail = tail;
        }

        if(count == l-k+1) {
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }

    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

void intersect(Node* &head1, Node* &head2, int pos) {
    Node* temp1 = head1;
    pos--;

    while(pos--) {
        temp1 = temp1->next;
    }

    Node* temp2 = head2;
    while(temp2->next != NULL) {
        temp2 = temp2->next;
    }

    temp2->next = temp1;
}

int findIntersectionPoint(Node* &head1, Node* &head2) {
    int l1 = length(head1);
    int l2 = length(head2);

    int d = 0;
    Node* ptr1;
    Node* ptr2;

    if(l1>l2) {
        d = l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    } else
    {
        d = l2-l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while(d) {
        ptr1 = ptr1->next;
        if(ptr1 == NULL) {
            return -1;
        }

        d--;
    }

    while(ptr1!=NULL && ptr2!=NULL) {
        if(ptr1 == ptr2) {
            return ptr1->data;
        }
        
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

Node* mergeLL(Node* &head1, Node* &head2) {
    Node* p1 = head1;
    Node* p2 = head2;
    Node* dummyNode = new Node(-1);
    Node* p3 = dummyNode;

    while (p1!=NULL && p2!=NULL)
    {
        if(p1->data < p2->data) {
            p3->next = p1;
            p1 = p1->next;
        } 
        else {
            p3->next = p2;
            p2 = p2->next;
        }

        p3 = p3->next;
    }

    while(p1 != NULL) {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }

    while(p2 != NULL) {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }

    return dummyNode->next;
}

Node* mergeLLrec(Node* &head1, Node* &head2) {
    if(head1==NULL) {
        return head2;
    }
    if(head2==NULL) {
        return head1;
    }
    
    Node* result;

    if(head1->data < head2->data) {
        result = head1;
        result->next = mergeLLrec(head1->next, head2);
    }
    else {
        result = head2;
        result->next = mergeLLrec(head1, head2->next);
    }

    return result;
}


int main() {

    Node* head = NULL;

    insertAtTail(head, 3);
    insertAtTail(head, 5);
    insertAtTail(head, 8);
    insertAtTail(head, 10);
    insertAtTail(head, 12);

    display(head);
    // cout<<search(head, 8)<<endl;

    // deleteNode(head, 12);
    // display(head);

    // deleteNode(head, 10);
    // display(head);

    // deleteAtHead(head);
    // display(head);

    // deleteAtHead(head);
    // display(head);
    
    // deleteNode(head, 7);
    // display(head);

    // Node* newHead = reverse(head);
    // display(newHead);
    // newHead = reverseRec(newHead);
    // display(newHead);

    // newHead = reverseKnodes(newHead, 2);
    // display(newHead);

    // makeCycle(head, 3);
    // cout<<detectCycle(head)<<endl;

    // removeCycle(head);
    // cout<<detectCycle(head)<<endl;
    // display(head);

    // Node* newHead = appendKnodesToStart(head, 3);
    // display(newHead);

    Node* head2 = NULL;
    insertAtTail(head2, 2);
    insertAtTail(head2, 6);
    display(head2);

    // intersect(head, head2, 3);
    // display(head);
    // display(head2);
    // cout<<findIntersectionPoint(head, head2);

    // Node* newHead = mergeLL(head, head2);
    Node* newHead = mergeLLrec(head, head2);
    display(newHead);

    return 0;
}