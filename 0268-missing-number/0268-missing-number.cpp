class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int SE =0;
        int SI=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            SE+= nums[i];
            SI+=i+1;
        }
        ans = SI-SE;
        return ans;
    }
};