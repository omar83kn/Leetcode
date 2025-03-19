class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;  
        for (int i = 0; i < nums.size() - 1 && i <= maxReach; i++) {
            maxReach = max(maxReach, i + nums[i]);
            
            
            if (maxReach >= nums.size() - 1) {
                return true;
            }
        }
        
        return (nums.size() == 1) || (maxReach >= nums.size() - 1);
    }
};