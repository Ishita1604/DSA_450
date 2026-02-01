#include <bits/stdc++.h>
using namespace std;

// Link:   https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1 && https://www.geeksforgeeks.org/dsa/find-pairs-given-sum-doubly-linked-list/

// Prereq: Pair Sum in an Array.
// Link:   https://leetcode.com/problems/two-sum/


class Node {  // DLL.
  public:
    int data;
    Node *next, *prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};  



void print(const vector<pair<int,int>>& v) {  // Print vector of pair.
    if (v.empty()) cout << "No pairs found" << endl;
    else {
        for (const auto& p : v)
        cout << p.first << " " << p.second << endl;
    }
}



class Solution {
  public:
    // 1) Brute Force Approach ----
    // Time:  O(N*N) due to nested loops. V. Very bad solution.
    // Space: O(1)
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int, int>> ans;
        Node* i = head;
        Node* j = NULL;
        // int exp_sum;
        while (i != NULL) {
            j = i->next;
            // exp_sum = target - i->data;       ⇒ This is basically the COMPLEMENT.
            while (j != NULL && i->data+j->data <= target) {
                // if (j->data == exp_sum) {
                if (i->data + j->data == target) {
                    ans.push_back({i->data, j->data});
                    break;
                }
                else j = j->next;
            }
            i = i->next;
        }
        return ans;
    }
        
        
        
        
    
    // 2) Naive Approach: Hash Map ----
    // Time:  O(N) to traverse the DLL elements. 
    // Space: O(N) to create hashset to store DLL elements. Need to return DLL element so no need of hashmap & store element-index key-value.
    vector<pair<int, int>> findPairsWithGivenSum1(Node *head, int target) {
        vector<pair<int, int>> ans;
        unordered_set<int> uset;
        Node* tmp = head;
        int exp_sum; 
        while (tmp != NULL) {
            uset.insert(tmp->data);
            tmp = tmp->next;
        }
        tmp = head;
        while (tmp != NULL) {
            exp_sum = target - tmp->data;   // The COMPLEMENT.
            if (uset.find(exp_sum) != uset.end() && exp_sum != tmp->data) { // Found. ☆☆ 2nd condition works bcos all elements are distinct.
                ans.push_back({tmp->data, exp_sum});
                uset.erase(tmp->data);
            }
            tmp = tmp->next;
        }
        return ans;
    }    

    
    
    
    
    // 3) Optimal Approach: Two Pointer to utilise the SORTED DISTINCT & DOUBLY LL ----
    // Time:  O(N) to traverse the DLL elements. 
    // Space: O(1)
    vector<pair<int, int>> findPairsWithGivenSum2(Node *head, int target) {
        vector<pair<int, int>> ans;
        Node* l = head;   // Left pointer.
        Node* r = head;
        while (r->next != NULL) {
            r = r->next;  // Place right pointer at tail.
        }
        while (l->data < r->data) {
            if (l->data+r->data < target) {
                l = l->next;
            }
            else if (l->data+r->data > target) {
                r = r->prev;
            }
            else if (l->data+r->data == target) {
                ans.push_back({l->data, r->data});
                l = l->next;
            }
        }       
        return ans;
    }    
};




int main() {
    // Create nodes.
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    Node* sixth = new Node(6);
    Node* seventh = new Node(8);
    Node* eighth = new Node(9);

    // Link nodes in DLL.
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;
    fifth->next = sixth;
    sixth->prev = fifth;
    sixth->next = seventh;
    seventh->prev = sixth;
    seventh->next = eighth;
    eighth->prev = seventh;


    int target = 7;
    Solution s;
    // vector<pair<int, int>> ans = s.findPairsWithGivenSum(head, target);
    // vector<pair<int, int>> ans = s.findPairsWithGivenSum1(head, target);
    vector<pair<int, int>> ans = s.findPairsWithGivenSum2(head, target);
    print(ans);

    return 0;
}
