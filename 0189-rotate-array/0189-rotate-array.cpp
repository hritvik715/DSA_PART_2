class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k   = k % n;
        int index = 0;
        int temp[1000000];
        for(int i=nums.size()-k;i<nums.size();i++){
            temp[index] = nums[i];
            index++;
        }

        for(int i = nums.size()-1;i>=0;i--){
            if(i-k >=0){
                nums[i] = nums[i-k];
            }
        }

        for(int i=0;i<k;i++){
            nums[i] = temp[i];
        }
        
    }
};