#include <bits/stdc++.h>
using namespace std;

// Link: https://leetcode.com/problems/linked-list-cycle/

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// TIME:  O(N)
// SPACE: O(1)  —  Optimal      —  Floyd’s slow fast pointer approach.
// SPACE: O(N)  —  Brute Force  —  Hash set appraoch, extra space to store if node previously visited. 
class Solution
{
public:
    bool hasCycle(Node *head) {
        if (head == NULL) return false;
        // Floyd’s approach. If cycle exists at some point both meet.
        // If linear LL they travel off and never meet.
        Node *slow = head;
        Node *fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};