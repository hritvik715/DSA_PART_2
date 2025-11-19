// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int>x;
//         for(int i=0;i<nums.size();i++){
//             int ans =1;
//             for(int j=0;j<nums.size();j++){
//                 if(i != j){
//                     ans = ans * nums[j];
//                 }
//             }
//             x.push_back(ans);
//         }
//         return x;
//     }
// };


//optimal way 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> suffix(nums.size()) , prefix(nums.size()) , ans(nums.size());

        prefix[0] =1;
        for(int i=1;i<nums.size() ;i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        suffix[nums.size()-1] = 1;
        for(int j=nums.size()-2 ;j>=0;j--){
            suffix[j] = suffix[j+1] * nums[j+1];
        }

        for(int i=0;i<nums.size() ;i++){
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }
};