#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

struct Node {
    int data;
    struct Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* nxt = NULL;
        while (curr != NULL) {
            nxt = curr->next;  // Preserve address of next LL.
            curr->next = prev; // Reversal logic.
            prev = curr;
            curr = nxt;
        }
        return prev;          // New head is prev.
    }
    
    // Time:  O(3N) very costly.
    // Space: O(N)
    // 1.   Addition MSD←LSD & carry forward L←R, but backward traversal is complex. So, reverse LL & bring LSD at FRONT.
    // 2.   Peform addition logic.
    // 3.   Reverse back. Create new node if carry remains.
    Node* addOne(Node* head) {     // Return head of list after adding one.
        head = reverseList(head);
        
        Node* curr = head;
        int cry = 1;               // To add 1 initially, & later act as carry.
        while (curr != NULL) {
            curr->data = curr->data+cry;
            if (curr->data < 10) { // Just add 1 to last (now 1st) node.
                cry = 0;           // No carry forward.
                break;             // :) All done
            } 
            else {  
                curr->data = 0;    // Node became 2 digit after adding.
                cry = 1;           // So carry forward to next node.
            }
            curr = curr->next;     // Move ahead & repeat with all nodes.
        }
        head = reverseList(head);  // Reverse LL again.
        
        if (cry == 1) {            // At the end. carry is left, so Add new node at FRONT.
            Node *newNode = new Node(1);  
            newNode->next = head;
            head = newNode;
        }
        
        return head;
    }
};
