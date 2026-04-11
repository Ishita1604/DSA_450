#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int fib0(int n) {
        // ⌣⌣⌣⌣⌣⌣⌣ (1) Recursive Approach ⌣⌣⌣⌣⌣⌣⌣
        // F(n) = F(n-1)+F(n-2)
        // TC: O(2^n) as T(n) = T(n-1)+T(n-2)+k ⟹ T(n) ≈ 2T(n-1)+k. Further solved by multiplication & substitution.
        // SC: O(n) as max depth of recursion tree is n levels.
        if (n <= 1) return n;     // Base cases: F(0)=0, F(1)=1.
        return fib0(n-1) + fib0(n-2);
    }




    // ⌣⌣⌣⌣⌣⌣⌣ (2) DP using Memoization ⌣⌣⌣⌣⌣⌣⌣
    // In recursion, same function calls for repetitive subproblems being made. Like F(2), F(3), ...
    // So store these repeating values in 1D DP Array. Ensures each subproblem is only calculated once.
    // TC: O(n) as array returns computed F(n) values in O(1) time for all values (0,n).
    // SC: O(n) for both array & recursive stack.
    int solve(vector<int> &dp, int n) {
        dp[0] = 0;                // Base cases: F(0)=0, F(1)=1.
        dp[1] = 1;
        if (dp[n] == -1) {        // Check if already solved.
            return dp[n] = solve(dp, n-1) + solve(dp, n-2);
        }
        else {
            return dp[n];
        }
    }

    int fib1(int n) {        
        if (n <= 1) return n;     
        vector<int> dp(n+1, -1);  // Size n+1 & initial values -1.        

        return solve(dp, n);
    }




    // ⌣⌣⌣⌣⌣⌣⌣ (3) Bottom Up Approach / Tabulation (With Extra Space) ⌣⌣⌣⌣⌣⌣⌣
    // Step 1: Define state for ith element i.e. dp[i] = ith Fibonacci number.
    // Step 2: Fill DP array with base cases, and remaining using F(n).
    // Smallest subproblem first. DP array accessed instead of recursive calls ⟹ Iterative solution.
    // TC: O(n)
    // SC: O(n) for DP array.
    int fib2(int n) {
        if (n <= 1) return n;
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }




    // ⌣⌣⌣⌣⌣⌣⌣ (4) Bottom Up Approach / Tabulation (With Constant Space/Optimal) ⌣⌣⌣⌣⌣⌣⌣
    // No use of storing F(n) values ∀ [1,n] as only previous 2 considered.
    // So store just previous 2 values in 2 variables ⟹ No need of DP array.
    // TC: O(n)
    // SC: O(1) 
    int fib3(int n) {
        if (n <= 1) return n;
        int a = 0, b = 1, c = 0;
        
        for (int i=2; i<=n; i++) {
            c = a + b;  // F(n)
            a = b;
            b = c;
        }
        
        return c;
    }
    
};

