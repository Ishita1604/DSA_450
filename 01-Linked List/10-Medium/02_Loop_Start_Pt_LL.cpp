#include <bits/stdc++.h>
using namespace std;

// Starting Point/First Node of the loop/cycle.
// Link:   https://leetcode.com/problems/linked-list-cycle-ii/ OR https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1

// Prereq: https://leetcode.com/problems/linked-list-cycle/ OR https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1


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
    int cycleStart(Node* head) {
        unordered_set<Node*> umap;
        Node* tmp = head;
        while (tmp != NULL) {
            if (umap.find(tmp) != umap.end()) return tmp->data; // Encountered same node again.
            umap.insert(tmp);
            tmp = tmp->next;
        }
        return -1; // Linear LL.
    }
    


    // 2. Optimal Approach — Floyd’s slow & fast ptr approach.
    // 1st collision (Inside) ⇒ Loop confirmed. Reset slow to head & move both 1 step. 2nd collision ⇒ At 1st node of loop.
    // ∵ Distance(Collision → 1st node of loop) == Distance(Head → 1st node of loop). ⊹ ࣪ ˖
    // Time:  O(N)
    // SPACE: O(1) .✦ ݁˖
    int cycleStart1(Node* head) {
        if (head == NULL) return -1;
        Node* slow = head;
        Node* fast = head;
        bool loop = 0;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                loop = 1;
                break;               // 1st collision done.  
            }          
        }
        if (loop == 1) {             // ୨ৎ Don't check by slow == fast as edge cases fail.
            slow = head;             // Reset slow to start of LL.
            while (slow != fast) {
                slow = slow->next;   // Move both by 1 step.
                fast = fast->next;
            }
            return slow->data;
        }
        return -1;
    }
};


