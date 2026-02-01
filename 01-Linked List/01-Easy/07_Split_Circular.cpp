#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1

// Structure of linked list.
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// Function which splits the circular linked list. The head is pointer to head Node of given lined list.
// The head1_ref1 and *head_ref2 are pointers to head pointers of resultant two halves.
class Solution {
    public:
    // Time:  O(N+n/2)
    // Space: O(1)
    pair<Node *, Node *> splitList(struct Node *head) {
        // ☆ Handle empty & 1-node LL case.
        if (head == NULL || head->next == head) return {head, NULL};
        Node *s = head;
        Node *f = head;
        
        // ☆ Nodes > 1 then find mid of LL.
        while (f->next != head && f->next->next != head) {
            f = f->next->next;
            s = s->next;
        }
        // Make both halves circular.
        Node *h1 = head;
        Node *h2 = s->next;
        s->next = h1;
        if (f->next->next == head) {                   // Even nodes.
            // ★★ V. Imp that f->next will always take us to head, THAT link never broke.
            // So h2 again gets assigned to head.
            // So use tmp ptr with 1 extra traversal.   
            Node *tmp = h2;                            // ★★ Don't start from head, else at end of 1st half, it reaches again to head.  
            while (tmp->next != head) {
                tmp = tmp->next; 
            }
            // At last node of 2nd half →
            tmp->next = h2;
        }
        else {                                         // Odd nodes.
           f->next = h2;
        }
        
        return {h1, h2};
    }
};
