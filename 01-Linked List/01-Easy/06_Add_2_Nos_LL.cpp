#include <bits/stdc++.h>
using namespace std;

// Link: https://leetcode.com/problems/add-two-numbers/

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
    // Time:  O(max(N1, N2))
    // Space: O(max(N1, N2)) needed ATQ, not extra.
    // Using dummy node to track new answer LL.
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;
        ListNode *dummy = new ListNode(-1);
        ListNode *curr3 = dummy;  // ★★ Create new LL ⇒ Dummy node ★★
        int cry = 0;

        while (curr1 != NULL || curr2 != NULL) {
            int sum = cry;        // ★★
            if (curr1) sum += curr1->val;
            if (curr2) sum += curr2->val;
            ListNode *newNode = new ListNode(sum % 10);
            cry = sum / 10;

            curr3->next = newNode;
            curr3 = newNode;

            if (curr1) curr1 = curr1->next;
            if (curr2) curr2 = curr2->next;
        }
        
        // Reached end of both LL & carry is left, then create new node.
        if (cry) {
            ListNode *newNode = new ListNode(cry);
            curr3->next = newNode;
        }

        return dummy->next;       // ★★ Return head of answer LL.
    }
};