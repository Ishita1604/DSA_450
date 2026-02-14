#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1


class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    // 1. Brute Force — Hashset Approach — Store visited nodes and check.
    // Time:  O(N)
    // Space: O(N) 
    void removeLoop(Node* head) {
        
    }
    


    // 2. Optimal Approach — Floyd’s slow & fast ptr approach.
    // When slow reaches last node of loop, update its next to NULL.
    // Time:  O(N)
    // Space: O(1)
    void removeLoop(Node* head) {
        // If loop exists, remove it. If not do nothing, eat 5★.
        Node* slow = head;
        Node* fast = head;
        Node* loopStartPt = NULL;
        bool loop = 0;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                loop = 1;
                break;                             // 1st collision done ⇒ Loop exists.
            }          
        }
        if (loop == 1) {             
            slow = head;                          // Reset slow to head of LL.
            while (slow != fast) {
                slow = slow->next;   
                fast = fast->next;
            }                                     // 2nd collision done ⇒  At 1st node of loop.
            loopStartPt = slow;                   // Reset slow to 1st node of loop.
            while (slow->next != loopStartPt) {   // ݁˖⊹₊˚‧︵‿₊
                slow = slow->next;
            }   
            slow->next = NULL;                    // ⊹ ࣪ ˖ Update link.
        }
    }
};
