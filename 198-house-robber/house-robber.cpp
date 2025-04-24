class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; // Only one house, rob it
        
        int prev2 = 0; // Max money up to i-2
        int prev1 = nums[0]; // Max money up to i-1
        
        for (int i = 1; i < n; i++) {
            int current = max(nums[i] + prev2, prev1); // Rob i or skip i
            prev2 = prev1; // Update for next iteration
            prev1 = current;
        }
        
        return prev1;
    }
};