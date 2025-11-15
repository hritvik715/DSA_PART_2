class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        //bruteforce
        // for(int i=0;i<nums.size() ; i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i] == nums[j]){
        //             return true;
        //         }
        //     }
        // }
        // return false;



        // using map
        // unordered_map<int , int > freq;

        // for(int i=0;i<nums.size();i++){
        //     freq[nums[i]]++;
        //     if(freq[nums[i]] >1) return true;
        // }

        // return false;
       



       //using sets
       unordered_set<int> x;
       for(int i=0;i<nums.size();i++){
        if(x.count(nums[i])) return true;
        x.insert(nums[i]);
       }

       
       return false;



    }
};    