class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> freq;

        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }


        for(int i=0;i<nums.size();i++){
            if(freq[nums[i]] == 1){
                return nums[i];
            }
        }
        return 0;
    }
};