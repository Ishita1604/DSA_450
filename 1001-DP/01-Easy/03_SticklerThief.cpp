#include <bits/stdc++.h>
using namespace std;

// Link: https://leetcode.com/problems/house-robber/

// Why DP?
// 1. Thief has option to choose at each house.
// 2. Max/optimal answer is needed.
// 3. Overlapping sub-problems. Check from recursion tree.


class Solution {
public:
    // ⌣⌣⌣⌣⌣⌣⌣ (1) Top Down / Recursive Approach ⌣⌣⌣⌣⌣⌣⌣
    // TC: O(2^N) so TLE.
    // SC: O(N)
    int solve0(vector<int> &nums, int i, int n) {   // House I/P array is nums, each house index i, # of houses n, returns max money. 
        if (i >= n) return 0;                       // Stopping condition if entire I/P array traversed.

        // Thief has 2 options i.e. steal or skip.
        int steal = nums[i] + solve0(nums, i+2, n);    // If steal, must skip i+1 (returns ₹0), & make choice at i+2.
        int skip = solve0(nums, i+1, n);               // If skip, can make choice at i+1.

        return max(steal, skip);                       // Return ₹ of optimal path.
    }

    int rob0(vector<int>& nums) {
        int n = nums.size();
        return solve0(nums, 0, n);
    }





    // ⌣⌣⌣⌣⌣⌣⌣ (2) Top Down / DP using Memoization + Recursion ⌣⌣⌣⌣⌣⌣⌣
    // TC: O(N) as we reach each house exactly once.
    // SC: O(N) for DP array & recursive stack.
    int solve1(vector<int> &nums, int i, int n, vector<int> &dp) { 
        if (i >= n) return 0; // As entire array traversed.
 
        if (dp[i] != -1) {    // As already calculated ₹ value.
            return dp[i]; 
        }

        int steal = nums[i] + solve1(nums, i+2, n, dp);    
        int skip = solve1(nums, i+1, n, dp);               

        return dp[i] = max(steal, skip); 
    }

    int rob1(vector<int> nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);  // DP array.
        return solve1(nums, 0, n, dp);
    }

    


  
    // ⌣⌣⌣⌣⌣⌣⌣ (3) Bottom Up Approach / Tabulation (With Extra Space) ⌣⌣⌣⌣⌣⌣⌣
    // Step 1: Define state for ith element i.e. dp[i] = Max money stolen till house i.
    // Step 2: Fill DP array with base cases, and remaining values, using F(n).
    // TC: O(N)
    // SC: O(N) for DP array.
    int rob2(vector<int> nums) {
        int n = nums.size();
        
        // Base cases.
        if (n == 0) return 0;        // 0th house, nothing to steal, so ₹0.
        if (n == 1) return nums[0];  // 1st house, so only 1st to steal.

        vector<int> dp(n+1, -1);     // Index i in dp[] stores ₹ of index (i-1) in nums[].
        dp[0] = 0;
        dp[1] = nums[0];

        for (int i=2; i<=n; i++) {
            int steal = nums[i-1] + dp[i-2];   // Current ₹ + previous to adjacent ₹.
            int skip = dp[i-1];                // ₹ till previous.
            dp[i] = max(steal, skip);
        }
        
        return dp[n];   // Max ₹ till all houses.
    }




    // ⌣⌣⌣⌣⌣⌣⌣ (4) Bottom Up Approach / Tabulation (With Constant Space/Optimal) ⌣⌣⌣⌣⌣⌣⌣
    // Only previous 2 values dp[i-1] and dp[i-2] are needed. So just store them.
    // TC: O(N)
    // SC: O(1) as no need of DP array, only variables.
    int rob(vector<int> nums) {
        int n = nums.size();
        
        // Base cases.
        if (n == 0) return 0;        // 0th house.
        if (n == 1) return nums[0];  // 1st house.

        int prevPrev = 0;    // dp[i-1]
        int prev = nums[0];  // dp[i-2]
        
        for (int i=2; i<=n; i++) {
            int steal = nums[i-1] + prevPrev;   
            int skip = prev;               
            int tmp = max(steal, skip);   // Temp variable.

            prevPrev = prev;
            prev = tmp;
        }
        
        return prev;  // .✦ ݁˖
    }
};


int main() {


    return 0;
}