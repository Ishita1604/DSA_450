#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Printing array elements.
    void print(vector<int> arr) {
        int n = arr.size();
        cout << "[";
        for (int x=0; x<n-1; x++)
            cout << arr[x] << ", ";
        cout << arr[n-1] << "]";
        cout << endl;
    }

    /*--------------------------------
     1. Brute Force Approach
     Idea:  Reverse traverse and assign to new array.
     Time:  O(N)
     Space: O(N)
    --------------------------------*/
    void reverseArray(vector<int> &arr) {
        int n = arr.size(); // sizeof(arr) / sizeof(arr[0]);  Don't use in case of vector.
        vector<int> brr(n);
        int j = 0;
        for (int i=n-1; i>=0; i--) {
            brr[j] = arr[i];
            j++;
        }
        arr = brr;
    }

    /*--------------------------------
     2. Two Pointer In-place Approach
     ----> Optimal  ✮⋆｡°✩ ⋆·˚
     Idea:  Rotating a rod 180 degrees around its center.
     Time:  O(N/2)
     Space: O(1)
    --------------------------------*/
    void reverseArray2(vector<int> &arr) {
        int n=arr.size();
        int i=0, j=n-1;
        for (int i=0; i<n/2; i++) {
            int el = arr[i];
            arr[i] = arr[j];
            arr[j] = el;
            j--;
        }
    }

    /*--------------------------------
     3. Two Pointer Not In-place
     ----> Just for practice – No advantage over brute force. ꕥ
     Idea:  Fill both ends of new array in one pass.
     Time:  O(N/2)
     Space: O(N)
    --------------------------------*/
    void reverseArray3(vector<int> &arr) {
        int n = arr.size();
        vector<int> brr(n);
        int i=0, j=n-1;
        for (int i=0; i<n/2; i++) {
            int el = arr[i];
            brr[i] = arr[j];
            brr[j] = el;
            j--;
        }
        arr = brr;
    }

    /*--------------------------------
     4. Recursion Approach
     ----> Sometimes to move forward, we need to take a step back. ꕥ
     Idea:  After reaching half way, repeat the swapping to our way out.
     Time:  O(N/2)
     Space: O(N/2)
    --------------------------------*/
    void reverseArray4(vector<int> &arr, int i=0) {   // Don't initialize i inside, or everytime it resets to 0.
        int n = arr.size();
        if (i == n/2) return;        //   (1) Base condition.
        reverseArray4(arr, i+1);     //   (2) Recursive function call with updated parameter.    Don't use i++ inside!
        swap(arr[i], arr[n-1-i]);    //   (3) Process.
    }
};

int main() {
    vector<int> arr{1,2,3,4};
    Solution s;
    cout << "\nOriginal Array:\n";
    s.print(arr);
    cout << "\nReversed Array:\n";
    // s.reverseArray(arr);
    // s.reverseArray2(arr);
    // s.reverseArray3(arr);
    s.reverseArray4(arr);
    s.print(arr);

    return 0;
}
