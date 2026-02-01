#include <bits/stdc++.h>
using namespace std;

// Link:   https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1 && https://www.geeksforgeeks.org/dsa/sort-a-linked-list-of-0s-1s-or-2s/

// Prereq: Sort Array of 0s, 1s, and 2s.
// Link:   https://leetcode.com/problems/sort-colors/


class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};


class Solution {
  public:
    // 1) Expected Approach: Counting & Overwriting Method ----
    // Time:  O(N)
    // Space: O(1) but data overwriting not good practice.
    Node* segregate(Node* head) {
        int zeroes = 0, ones = 0, twos = 0;
        Node* tmp = head;
        while (tmp != NULL) {
            if (tmp->data == 0) zeroes++;
            else if (tmp->data == 1) ones++;
            else if (tmp->data == 2) twos++;
            tmp = tmp->next;
        }
        tmp = head;
        while (zeroes--) {
            tmp->data = 0;
            tmp = tmp->next;
        }
        while (ones--) {
            tmp->data = 1;
            tmp = tmp->next;
        }
        while (twos--) {
            tmp->data = 2;
            tmp = tmp->next;
        }
        return head;
    }
    
    
    
    
    // 2) Optimal Approach: Updating the Links ----
    // Data replacement not allowed so update the links.
    // Time:  O(N)
    // Space: O(1)
    Node* segregate1(Node* head) {
        if (head == NULL) return head;
        // Creating 3 dummy nodes to act as head as we're creating new LLs.
        // (Not really creating LL but changing links). 
        Node* dmy0 = new Node(-1);
        Node* dmy1 = new Node(-1);
        Node* dmy2 = new Node(-1);
        
        // We won't change the dummy heads, else later joining issue.
        // Use p0 p1 p2 ptrs to traverse LL.
        Node* p0 = dmy0;
        Node* p1 = dmy1;
        Node* p2 = dmy2;
        
        Node* tmp = head;     // To traverse LL.
        Node* nextTmp = NULL; // ✦✦ To store the next node and break link b/w current tmp & next node.
        // Else original LL continues & causes cycles/wrong links.
        
        while (tmp != NULL) {
            nextTmp = tmp->next; // ✦✦ 
            if (tmp->data == 0) {
                p0->next = tmp;
                p0 = p0->next;
            }
            else if (tmp->data == 1) {
                p1->next = tmp;
                p1 = p1->next;
            }
            else if (tmp->data == 2) {
                p2->next = tmp;
                p2 = p2->next;
            }
            tmp->next = NULL;
            tmp = nextTmp;
        }
        
        // Assigning new head.
        if (dmy0->next) head = dmy0->next;
        else if (dmy1->next) head = dmy1->next;
        else head = dmy2->next;
        
        // Building further LL.
        if (head == dmy0->next) {
            p0->next = (dmy1->next) ? dmy1->next : dmy2->next;
            p1->next = dmy2->next;
        }
        else if (head == dmy1->next) {
            p1->next = (dmy2->next) ? dmy2->next : NULL;
        }
       
        return head;
    }
    
};
