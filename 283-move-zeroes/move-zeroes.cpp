class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0; // Pointer for placing non-zero elements

        // Move non-zero elements forward
        for (int fast = 0; fast < nums.size(); ++fast) {
            if (nums[fast] != 0) {
                nums[slow++] = nums[fast];
            }
        }

        // Fill the remaining elements with 0
        while (slow < nums.size()) {
            nums[slow++] = 0;
        }
    }
};
