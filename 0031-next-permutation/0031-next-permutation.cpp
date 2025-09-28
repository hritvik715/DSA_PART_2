class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n = nums.size();
        int i = n - 2;

        // Step 1: Find the first decreasing element from the right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // If found a valid i (not -1), proceed to step 2 & 3
        if (i >= 0) {
            int j = n - 1;
            // Step 2: Find the rightmost element greater than nums[i]
            while (nums[j] <= nums[i]) {
                j--;
            }
            // Step 3: Swap
            swap(nums[i], nums[j]);
        }

        // Step 4: Reverse the suffix starting at i+1
        reverse(nums.begin() + i + 1, nums.end());
    
    }
};