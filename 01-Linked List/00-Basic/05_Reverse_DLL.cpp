#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};


class Solution {
  public:
    // Brute Force — Reverse the Data Approach:
    // TIME:  O(2N) 2 passes used.
    // SPACE: O(N) stack is used.
    Node *reverse(Node *head) {
        stack<int> st;
        Node *tmp = head;

        while (tmp != NULL) {
            // Traverse DLL & push to stack.
            st.push(tmp->data);
            tmp = tmp->next;
        }
        tmp = head; // Again head to start.

        while (tmp != NULL) {
            // Swap DLL data with stack's top.
            tmp->data = st.top();
            st.pop();
            tmp = tmp->next;
        }
        return head;
    }
    



    // Better — Reverse the Connections Approach:
    // TIME:  O(N)
    // SPACE: O(1) using 2 variables, last & tmp ptr.
    Node *reverse1(Node *head) {
        if (head == NULL) return head;
        
        Node *curr = head;
        Node *tmp = NULL;
        Node *last = NULL; // To preserve previous node.

        while (curr != NULL) {
            // Swapping logic using tmp.
            tmp = curr->next;
            curr->next = last;
            curr->prev = tmp;
            last = curr;
            curr = curr-> prev; // Move ahead in DLL.
        }
        return last; // Return new head.
    }




    // Optimal — Reverse the Connections Approach:
    // TIME:  O(N)
    // SPACE: O(1) using 1 variable, tmp ptr.
    Node *reverse2(Node *head) {
        if (head == NULL) return head;
        
        Node *curr = head;
        Node *tmp = NULL;  // To preserve front node.

        while (curr != NULL) {
            // Swapping logic using tmp.
            tmp = curr->next;
            curr->next = curr->prev;
            curr->prev = tmp;
            
            if (tmp == NULL) head = curr; // When we reach end of DLL.
            curr = curr-> prev;           // Move ahead in DLL.
        }
        return head; // Return new head.
    }
};
