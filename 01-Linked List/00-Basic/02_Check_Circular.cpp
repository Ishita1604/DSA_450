#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/circular-linked-list/1

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// TIME:  0(N)
// SPACE: O(1)
class Solution {
  public:
    // Traverse entire LL, starting from head->next and stop if:
    // 1) CLL (curr reached head again) i.e. curr == head happens.
    // 2) LL (curr becomes NULL) i.e. curr == NULL happens.

    bool isCircular(Node *head) {
        if (head == NULL) return true;          // 0 node LL is circular.
        if (head->next == NULL) return false;   // 1 node LL.
        else if (head->next == head) return true;
        else {                                  // >1 nodes LL.
            Node *curr = head->next;            // Start traversal from 2nd node to check complete cycle.
            while (curr != head && curr != NULL) {
              curr = curr->next;
            }
            if (curr == head) return true;
            else if (curr == NULL) return false;
        }
    }
};
