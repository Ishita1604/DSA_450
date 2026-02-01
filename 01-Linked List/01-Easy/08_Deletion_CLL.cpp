#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) { // Constructor.
        data = x;
        next = NULL;
    }
};



// Print CLL forward.
void printCLL(Node* head, int &n) {
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } 
    while (temp != head);
    cout << "       Size " << n << endl;

}




Node* deleteNode(Node* head, int pos, int &n) {
    if (pos > n) return head;             // False-positive case.
    if (head == NULL) return NULL;        // Empty LL.
    if (head->next == head) {             // 1-Node in LL.
        delete head;
        return NULL;
    }


    // Deletion at the beginning.
    // Time:  O(N) to traverse till tail.
    // Space: O(1) as only constant extra ptrs tmp & tail used.
    if (pos == 1) {                       // ✧ Nodes >1 in LL. Approaches  →
        //   1) Store head as tmp, move head directly to 2nd node, & delete tmp.
        //   ✘ BAD bcos  →  TAIL is still pointing to original head. So we HAVE TO adjust tail ptr.
        //   2) Place tmp at 2nd node, overwrite head's value with it. Update head->next = tmp->next & delete tmp. 
        //   ✘ BAD bcos  →  Didn't actually delete head ptr, just modified its value.
        //   3) "GET" tail ptr, update tail->next = head->next. Delete head.
        //   ✔ BEST bcos →  Deletes actual node & no data copying.
        
        Node* tmp = head;
        Node* tail = head->next;
        while (tail->next != head) {
            tail = tail->next;            // Tail is tailing here.
        }
        tail->next = head->next;
        head = head->next;
        delete tmp;
    }


    // Deletion at specific position.
    // Time:  O(N) N=position.
    // Space: O(1) as only constant extra ptrs tmp & prev used.
    if (pos > 1 && pos < n) {
        Node* tmp = head;
        Node* prev = NULL;
        int ct = 1;  
	    while (tmp->next != head) {
            prev = tmp;
            tmp = tmp->next;
            ct++;
            if (ct == pos) {            // Found the position to delete at.
                prev->next = tmp->next;
                tmp->next = NULL;
                delete tmp;
                break; // ☆☆
            }
		}
	}


    // Deletion at the end.
    // Time:  O(N) to traverse till tail.
    // Space: O(1) as only constant extra ptrs tmp & tail used.
    if (pos == n) {
        Node* tail = head;
        Node* tmp = NULL;
        while (tail->next != head) {
            tmp = tail;
            tail = tail->next;         // Tail is tailing.
        }
        tmp->next = tail->next;
        tail->next = NULL;
        delete tail;
    }

    n--; // ☆☆
    return head; // Updated head.                 
}




int main() {
    int n = 0;            // LL size.

    // Create nodes.
    Node* head = new Node(1);   n++;
    Node* second = new Node(2); n++;
    Node* third = new Node(3);  n++;
    Node* fourth = new Node(4); n++;
    Node* fifth = new Node(5);  n++;

    // Link nodes to form CLL.
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = head;   // Circular link.

    cout << "Before Deletion: ";
    printCLL(head, n);

    head = deleteNode(head, 1, n);
    cout << "After Deletion at Beginning: ";
    printCLL(head, n);

    head = deleteNode(head, n, n);
    cout << "After Deletion at End: ";
    printCLL(head, n);

    int p = 2;            // Specific position to delete at.
    head = deleteNode(head, p, n);
    cout << "After Deletion at Position " << p << ": ";
    printCLL(head, n);

    return 0;
}