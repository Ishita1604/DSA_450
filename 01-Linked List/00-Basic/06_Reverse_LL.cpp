#include <bits/stdc++.h>
using namespace std;

// Link: https://leetcode.com/problems/reverse-linked-list/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // In-place Reversal Approach / Iterative ———→
        // TIME:  O(N)
        // SPACE: O(1)
        // Initialise ---
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = NULL;
        
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
};

