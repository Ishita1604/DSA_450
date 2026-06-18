#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Printing the min-max pair.
    void printPair(pair <int, int> &p) {
        cout << p.first << "  " << p.second;
        cout << endl;
    }
    
    /*--------------------------------
        1. Naive Approach
        Idea: Start with upper & lower bounds of INT & reassign.
        Time:  O(2N)
        Space: O(1)
    --------------------------------*/
    pair<int, int> getMinMax(vector<int> arr) {
        int n = arr.size();
        int maxi = INT_MIN, mini = INT_MAX;

        for (int i=0; i<n; i++)  // Setmaxi function.
        if (arr[i] < mini)
            mini = arr[i];

        for (int i=0; i<n; i++)  // Setmini function.
        if (arr[i] > maxi)
            maxi = arr[i];
        
        return {mini, maxi};
    }

    
    /*--------------------------------
        2. Better Approach
        Idea: Maintain maxi and mini in single parse.
        ----> Combined both setmaxi and setmini functions in one parse.
        Time:  O(N)    ⇢   More # comparisons = 2*N  ˙◠˙
        Space: O(1)
    --------------------------------*/
    pair<int, int> getMinMax2(vector<int> arr) {
        int n = arr.size();
        int maxi = INT_MIN, mini = INT_MAX;
        for (int i=0; i<n; i++) {
            if (arr[i] < mini)     
                mini = arr[i];
            if (arr[i] > maxi)
            maxi = arr[i];
        }
        return {mini, maxi};
    }
    
    /*--------------------------------
        3. Sorting Approach
        •°˚╰┈➤ STL std::sort() uses Intro sort algo, a combi of Heap, Insertion & Quick sort.
        Time:  O(N*logN)
        Space: O(1)
    --------------------------------*/
    pair<int, int> getMinMax3(vector<int> arr) {
        int n = arr.size();
        sort(&arr[0], &arr[n]);  // Sorts elements in memory range [1st, last).
        // sort(arr.begin(), arr.end());
        pair<int, int> p{arr[0], arr[n-1]};
        return p;
    }

    /*--------------------------------
        4. Linear Search Approach
        Idea: Why bring external mini & maxi? Use array's elements instead.
         ° Init with 1st element      ⇢ 2*(N-1) comparisons
         ✦ Init with 1st 2 element   ⇢  Less # comparisons = 1+2*(N-2) = 2N-3  •ᴗ•
        Time:  O(N)
        Space: O(1)
    --------------------------------*/
    pair<int, int> getMinMax4(vector<int> arr) {
        int n = arr.size();
        int mini, maxi;
        if (arr[0] < arr[1]) mini = arr[0], maxi = arr[0];    // Comparison # 1
        else mini = arr[1], maxi = arr[0];
        for (int i=2; i<n; i++) {                             // 2*(N-2) comparisons
            if (arr[i] < mini) int mini = arr[i];
            else if (arr[i] > maxi) arr[i] = maxi;
        }
        return {mini, maxi};
    }

    /*--------------------------------
        5. Tournament Method | D&C
        Idea: Divide into 2, recursively find mini & maxi of each part, & combine. 
        Concept:
        { n = 1      0 Comparison
          n = 2      1 Comparison
          n > 2      2 Comparisons as after combining prev 2 arrays, we'll have 2 minis and 2 maxis. So # 2 for each.
        }

        ✦ Recurrence:
        { T(1) = 0, T(2) = 1     // Base cases are non-recurring so not added.
          T(n) = 2T(n/2) + 2     // When n > 2, at each recursive level, above leaves, the "combine/final step" is exactly 2 comparisons.
        }

        Time:  T(n) ≈ 3/2n - 2 when n is power of 2, else more.                 Even lesser   •‿•
        Space: O(logN) for recursive stack with max height of binary tree.
    --------------------------------*/
    pair<int, int> getMinMax5(vector<int> arr, int i, int j) {
        int n = arr.size();
        int mini, maxi;
        
        // When n = 1 so # 0 comp.
        if (i == j) mini = maxi = arr[i];
        // When n = 2 so # 1 comp.
        else if (j == i+1) {
            if (arr[i] < arr[j]) mini = arr[i], maxi = arr[j];
            else mini = arr[j], maxi = arr[i];
        }

        // When n > 2 so 2 comp.
        // Divide the array into 2.
        else {
            int mid = (i+j)/2;
            pair<int, int> p1 = getMinMax5(arr, i, mid);
            pair<int, int> p2 = getMinMax5(arr, mid+1, j);
            if (p1.first < p2.first) mini = p1.first;
            else mini = p2.first;
            if (p1.second > p2.second) maxi = p1.second;
            else maxi = p2.second;
        }

        return {mini, maxi};
    }
};

int main()
{
    vector<int> arr{5,1,2,3,4};
    pair<int, int> p;
    Solution s;
    // p = s.getMinMax(arr);
    // p = s.getMinMax2(arr);
    // p = s.getMinMax3(arr);
    // p = s.getMinMax4(arr);
    p = s.getMinMax5(arr, 0, arr.size()-1);
    s.printPair(p);

    return 0;
}