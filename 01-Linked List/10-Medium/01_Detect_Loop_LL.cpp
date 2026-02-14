#include <bits/stdc++.h>
using namespace std;

// Every CLL has loop/cycle. But not every looped LL is CLL. 
// Link: https://leetcode.com/problems/linked-list-cycle/ OR https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1


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
    // SPACE: O(N) extra space to store previously visited node. 
    bool detectLoop(Node* head) {
        unordered_set<Node*> umap;
        Node* tmp = head;
        while (tmp != NULL) {
            if (umap.find(tmp) != umap.end()) return true;
            umap.insert(tmp);
            tmp = tmp->next;
        }
        return false;
    }



    // 2. Optimal Approach — Floyd’s slow & fast ptr approach.
    // If cycle exists ⇒ Slow & fast meet. Else linear LL ⇒ They travel off & never meet.
    // Intuition: Fast moves +2 steps towards while slow moves +1 step away.
    // So net, fast moves +1 step towards slow & net gap d reduces by 1 each iteration.
    // d ⇒ d-1 ⇒ d-2 .... ⇒ 0 i.e. eventually meet.
    // Time:  O(N)
    // SPACE: O(1)
    bool detectLoop1(Node* head) {
        if (head == NULL) return false;
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
