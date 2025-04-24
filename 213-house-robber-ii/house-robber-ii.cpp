class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; // Only one house, rob it
        if (n == 2) return max(nums[0], nums[1]); // Two houses, choose max
        
        // Case 1: Rob houses 0 to n-2 (exclude last)
        int max1 = robRange(nums, 0, n-2);
        // Case 2: Rob houses 1 to n-1 (exclude first)
        int max2 = robRange(nums, 1, n-1);
        
        return max(max1, max2);
    }
    
private:
    int robRange(vector<int>& nums, int start, int end) {
        int prev2 = 0; // Max money up to i-2
        int prev1 = nums[start]; // Max money up to i-1
        
        for (int i = start + 1; i <= end; i++) {
            int current = max(nums[i] + prev2, prev1); // Rob i or skip i
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};