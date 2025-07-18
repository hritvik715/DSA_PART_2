class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans=0;
        int lSum=0;
        int rSum=0;
        int tSum=0;
        for(auto x:nums) tSum+= x;

        for(int i=0 ; i<nums.size() ; i++){
            rSum = tSum-lSum-nums[i];

            if(lSum==rSum) return i;

            lSum  += nums[i];
        }
        return -1;
    }
};