class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> window;  
        
        for (int i = 0; i < nums.size(); i++) {
            if (window.count(nums[i]) && abs(i - window[nums[i]]) <= k) {
                return true;
            }
            
            window[nums[i]] = i;
            
            
            if (i >= k) {
                window.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};