#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/dsa/move-last-element-to-front-of-a-given-linked-list/

class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};


// Function to move the last node to the front of the LL.
// Time:  O(N)
// Space: O(1)
Node *moveToFront(Node *head) {
  if (head == NULL || head->next == NULL) return head;
   Node *curr = head;
   Node *prev = NULL;
   while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
   prev->next = NULL;   // OR prev->next = curr->next;
   curr->next = head;
   return curr;  
}


void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}


int main() {
    // Create LL: 1->2->3->4->5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Linked list before: " << endl;
    printList(head);

    head = moveToFront(head);

    cout << "Linked list after: " << endl;
    printList(head);

    return 0;
}
