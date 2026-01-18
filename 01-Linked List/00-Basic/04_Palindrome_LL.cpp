#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    // Approach 1 — Stack:
    // TIME:  0(2N)
    // SPACE: O(N)
    bool isPalindrome1(Node *head) {
        // Using stack's LIFO. Traverse all nodes & push into stack.
        // Again go to LL head, pop the stack and compare each node.
        // If match, palindrome else, not.
        stack<int> st;
        if (head == NULL) return false;
        Node *tmp = head;
        while (tmp != NULL) {
            st.push(tmp->data);
            tmp = tmp->next;
        }
        tmp = head;   // Again go to start.
        while (tmp != NULL) {
            if (tmp->data != st.top()) return false;
            st.pop();
            tmp = tmp->next;
        }
        return true;
    }
    
    

    // Approach 2 — Reverse half LL & compare:
    Node *reverse(Node *head) {      // Helper function.
        Node* prev = NULL;
        Node* curr = head;
        Node* nxt = NULL;
        
        while (curr != NULL) {
            // Preserve address of next LL.
            nxt = curr->next;
            // Reversal ---
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        // New head is prev. Also curr & next both become NULL at end.
        return prev;
    }
    
    // TIME:  O(3N/2) = O(N)
    // SPACE: O(1)
    bool isPalindrome(Node *head) {
        // Reverse 2nd half then compare both halves.
        if (head == NULL) return false;
        // Floyd's slow fast to find middle of LL.
        Node *slow = head;
        Node *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node *head2 = slow->next;    // Head of 2nd half.
        head2 = reverse(head2);
        Node *i = head;
        Node *j = head2;
        slow->next = NULL;           // Break link b/w halves. As end of 1st points to tail of LL now.
        // Now compare both halves.
        while (j != NULL) {
            if (i->data != j->data) return false;
            else {
                i = i->next;
                j = j->next;
            }
        }
        return true;
    }


};
