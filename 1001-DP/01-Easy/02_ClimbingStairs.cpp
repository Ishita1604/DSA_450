#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    // ⌣⌣⌣⌣⌣⌣⌣ (1) Recursive Approach ⌣⌣⌣⌣⌣⌣⌣
    // TC: O(2^N) as depth of recursion tree is 2^N.
    // SC: O(N) as depth of recursion stack is N.
    int solve0(int n) {
        // Base cases/Stopping conditions:
        if (n < 0) return 0;     // Impossible scenerio.
        if (n == 0) return 1;    // Way found to climb next stair.
       
        // Recursive relation:
        return solve0(n-1) + solve0(n-2);
    }

    int climbStairs0(int n) {
        return solve0(n);
    }





    // ⌣⌣⌣⌣⌣⌣⌣ (2) DP using Memoization ⌣⌣⌣⌣⌣⌣⌣
    // TC: O(N) as we reach each stair exactly once.
    // SC: O(N) for DP array & recursive stack.
    int solve1(vector<int> &dp, int n) {
        if (n <= 1) return 1;   // No need to enter recursion.

        // Base cases:
        dp[0] = 0;    // Impossible scenerio.
        dp[1] = 1;    // Way found to climb next stair.

        if (dp[n] != -1) {
            return dp[n];            
        }
        else {
            return dp[n] = solve1(dp, n-1) + solve1(dp, n-2);
        }
    }

    int climbStairs1(int n) {
        vector<int> dp(n+1, -1);
        return solve1(dp, n);
    }





    // ⌣⌣⌣⌣⌣⌣⌣ (3) Bottom Up Approach / Tabulation (With Extra Space) ⌣⌣⌣⌣⌣⌣⌣
    // Step 1: Define state for ith element i.e. dp[i] = Number of ways to reach ith stair.
    // Step 2: Fill DP array with base cases, and remaining values, using F(n).
    // TC: O(n)
    // SC: O(n) for DP array.
    int climbStairs2(int n) {
        if (n == 0 || n == 1 || n == 2) return n;

        vector<int> dp(n+1, n);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (int i=3; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }





    // ⌣⌣⌣⌣⌣⌣⌣ (4) Bottom Up Approach / Tabulation (With Constant Space/Optimal) ⌣⌣⌣⌣⌣⌣⌣
    // No need to store all values in dp array. As only previous 2 values are needed. Similar to Fibonacci series.
    // TC: O(n)
    // SC: O(1) as no need of DP array, only variables.
    int climbStairs(int n) {
        if (n == 0 || n == 1 || n == 2) return n;

        int a = 1;  // i-2      .✦ ݁˖ Different from base cases values.
        int b = 2;  // i-1
        int c = 0;  // i

        for (int i=3; i<=n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }


};
