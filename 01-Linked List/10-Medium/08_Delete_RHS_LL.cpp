#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1


class Node {
   public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// Print the LL.
void print(Node* head) { 
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


class Solution {
  public:
    // 1. Brute Force Approach — Use 2 loops, for each node check remaining & delete greater value node.
    // Time:  O(N*N)
    // Space: O(1)
    Node *compute(Node *head) {
        // For node deletion in LL, it's compulsory to map prev ptr.
        // Bcos if node deleted directly, then WHO will store address of remaining list?
        // As when WE delete curr, NO NODE updates its next to point to curr's next.
        // Traversal may be safe but LL structure broken.
        // ∴ Memory got freed but ptr still points to already deleted memory ⇒ DANGLING pointer.
        
        Node* curr1 = head;
        Node* curr2 = NULL;;
        Node* prev = NULL;
        Node* tmp = NULL;
        bool flg;

        if (head == NULL) return NULL;

        while (curr1 != NULL) {    // ₊˚⊹♡   Last node will never be deleted.
            flg = 0;
            curr2 = (curr1->next) ? curr1->next : NULL; // ⋆˙⟡
            while (curr2 != NULL) {
                if (curr2->data > curr1->data) {
                    if (curr1 == head) {  // Deletion at ⇒ Head.
                        head = curr1->next;  // Saving the remaining LL link.
                        tmp = curr1;                        
                        curr1 = curr1->next; // curr1 = head;
                        tmp->next = NULL;
                        delete tmp;
                        flg = 1; // ✧˖
                    }
                    else {  // Deletion at ⇒ Middle.
                        tmp = curr1;
                        prev->next = curr1->next;  // Saving the remaining LL link.    V.V. Imp.
                        curr1 = curr1->next;
                        tmp->next = NULL;
                        delete tmp;
                        flg = 1; // ✧˖
                        break;
                    }
                }
                else {  // Deletion X.
                    if (curr2->next) curr2 = curr2->next;
                    else break;
                }
            }
            
            // The curr1 needs to be moved a step ahead, so first update prev.
            if (flg == 0) { // ✧˖
                prev = curr1;
                curr1 = curr1->next;
            }
        }
        return head;       
    }



    // 2. Naive Approach — Using stack.
    // Time:  O(N)
    // Space: O(N)
    Node *compute1(Node *head) {
        stack<Node*> st;
        Node* tmp = head;

        // Compare elements & build stack.
        while (tmp != NULL) {
            while ((!st.empty() && tmp->data > st.top()->data))
                st.pop();
            st.push(tmp);
            tmp = tmp->next;
        }
        
        // Rebuild LL from stack.
        Node* nxt = NULL;  // .✦₊˚
        while (!st.empty()) {
            Node* node = st.top();
            st.pop();
            node->next = nxt; // .⟡₊˚
            nxt = node;
        }
        head = nxt;
        return head;
    }



    // 3. Optimal Approach — Reverse LL .
    // Time:  O(N logN)
    // Space: O(1)
    Node *compute2(Node *head) {
        stack<Node*> st;
        Node* tmp = head;

        // Compare elements & build stack.
        while (tmp != NULL) {
            while ((!st.empty() && tmp->data > st.top()->data))
                st.pop();
            st.push(tmp);
            tmp = tmp->next;
        }
        
        // Rebuild LL from stack.
        Node* nxt = NULL;  // .✦₊˚
        while (!st.empty()) {
            Node* node = st.top();
            st.pop();
            node->next = nxt; // .⟡₊˚
            nxt = node;
        }
        head = nxt;
        return head;
    }

};


int main() {
    // Create linked list: 12 -> 15 -> 10 -> 11 -> 5 -> 6 -> 2 -> 3 -> X
    Node* head = new Node(12);
    head->next = new Node(15);
    head->next->next = new Node(10);
    head->next->next->next = new Node(11);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next->next = new Node(3);

    Solution s;
	cout << "Original LL    ";
	print(head);
	cout << " Updated LL    ";
	// print(s.compute(head));
	print(s.compute1(head));


    return 0;
}
