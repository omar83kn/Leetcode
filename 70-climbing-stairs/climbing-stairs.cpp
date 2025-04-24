class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1; // Base cases: 1 way for n=0 or n=1
        
        int prev1 = 1; // Ways to climb 1 step
        int prev2 = 1; // Ways to climb 0 steps
        int current;
        
        for (int i = 2; i <= n; i++) {
            current = prev1 + prev2; // Ways to reach step i
            prev2 = prev1;           // Update for next iteration
            prev1 = current;
        }
        
        return current;
    }
};