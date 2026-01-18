#include <bits/stdc++.h>
using namespace std;

// Link: https://leetcode.com/problems/middle-of-the-linked-list/

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
    // Time:  O(N)
    // Space: O(N)
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) { // Else segmentation fault.
            fast = fast->next->next;
            slow = slow->next; 
        }
        if (fast->next == NULL) return slow; // Odd nodes.
        else return slow->next;              // Even nodes.
    }
};
