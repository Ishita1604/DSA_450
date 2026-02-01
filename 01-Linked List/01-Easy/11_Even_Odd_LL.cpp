#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

// Must: Exact same as sort LL of 0s, 1s, 2s.

struct Node
{
    int data;
    struct Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    // Start with 2 dummy heads, build separate even odd LL by changing LL links. Then combine.
    // Time:  O(N) to traverse LL.
    // Space: O(1)
    Node* divide(Node* head) {
        Node* tmp = head;
        Node* tmpNext = NULL;
        Node* dmy_e = new Node(-1);   // Head of even LL.
        Node* dmy_o = new Node(-1);   // Head of odd LL.
        Node* pe = dmy_e;             // Ptr to traverse even LL.
        Node* po = dmy_o;             // Ptr to traverse odd LL.
        
        while (tmp != NULL) {
            tmpNext = tmp->next;
            if (tmp->data % 2 == 0) { // Even node.
                pe->next = tmp;
                pe = pe->next;
            }
            else {                    // Odd node.
                po->next = tmp;
                po = po->next;
            }
            tmp->next = NULL;         // ツ To break original connections.
            tmp = tmpNext;
        }
        
        if (dmy_e->next) {
            head = dmy_e->next;
            pe->next = dmy_o->next;
        }
        else head = dmy_o->next;
        
        return head;
        
    }
};
