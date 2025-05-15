class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maxSum = 0;
        
        // Calculate initial sum of first k elements
        for (int i = 0; i < k; ++i) {
            maxSum += nums[i];
        }

        double currentSum = maxSum;
        // Slide the window
        for (int i = k; i < n; ++i) {
            currentSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, currentSum);
        }

        return maxSum / k;
    }
};
