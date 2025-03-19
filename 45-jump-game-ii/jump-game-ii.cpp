class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;          
        int currentMax = 0;     
        int nextMax = 0;        
        
       
        for (int i = 0; i < nums.size() - 1; i++) {
            nextMax = max(nextMax, i + nums[i]);
            if (i == currentMax) {
                jumps++;              
                currentMax = nextMax; 
                if (currentMax >= nums.size() - 1) {
                    return jumps;
                }
            }
        }
        
        return jumps;
    }
};