class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {


        //using hashmap


        // vector<int> x;
        // for(int i=0;i<nums.size() ;i++){
        //     for(int j=i+1 ;j<nums.size() ;j++){
        //         if(nums[i] + nums[j] == target ) {
        //             x.push_back(i);
        //             x.push_back(j);
        //         }
        //     }
        // }
        // return x;


        //2nd way (isme original array ki index change ho jaayegi)
        // int i=0;
        // int j=nums.size()-1;
        // vector<int>x;
        // sort(nums.begin() , nums.end());
        // while(i<=j){
        //     if(nums[i] + nums[j] ==target) {
        //         x.push_back(i);
        //         x.push_back(j);
        //         i++;//ye mai bhool jaata hu (agar ye nhi denge toh infinite loop chalta rahega)
        //         j--;//ye mai bhool jaata hu
        //     }
        //     else if(nums[i] + nums[j] > target ) j--;
        //     else i++;
        // }
        // cout<<x[i]<<" "<<x[j]<<endl;
        // return x;

        //using hashmaps
        unordered_map<int , int> x;
        for(int i=0;i<nums.size() ; ++i){
            int need = target -nums[i];
            if(x.count(need)){
                return {x[need] , i};
            }
            x[nums[i]] = i;//map mey index and value store kar rhe hai hum log
        }
        return {};

    }
};