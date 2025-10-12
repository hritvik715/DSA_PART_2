class Solution {
public:

    void printMap(unordered_map<int , int>&freqMap){
        unordered_map<int , int>::iterator it;
        cout<<"\n---Map has below things-------\n";
           for(it = freqMap.begin();it!=freqMap.end();it++){
            int key = it->first;
            int  freq = it->second;
            cout<<key << " " <<freq<<endl;
            
        }
    }

    int singleNumber(vector<int>& nums) {
        // int ans = 0;
        // int n = nums.size();
        // for (int i = 0; i < n; i++) {
        //     ans = ans ^ nums[i];
        // }
        // return ans;


        //2nd way
        // sort(nums.begin() ,nums.end());// vector increasing order
        // int n = nums.size();
        // int ans = -1;
        // int i =0;
        // while(i < n){
        //     if( i + 1 < n && nums[i] == nums[i+1]){
        //          i = i+2;
        //     }
        //     else{
        //         ans = nums[i];
        //         break;
        //     }

        // }
        // return ans;
    
    
    



        //3rd way (hashing method)
        //frequncy table
        unordered_map<int , int>freqMap;
        
        //add freq to the map/table
        for(int i =0 ; i<nums.size() ;i++){
            int num = nums[i];
            freqMap[num]=freqMap[num] +1;//suru may MAP mey entry hai hi nhi toh vo apne aap zero de dega initially
            // printMap(freqMap);
        }
        // return -1;

        unordered_map<int , int>::iterator it;
        int ans;
        for(it = freqMap.begin();it!=freqMap.end();it++){
            int key = it->first;
            int  freq = it->second;
            // cout<<key << " " <<freq<<endl;
            if(freq == 1){
                ans = key;
                break;
            }
            
        }
     
        return ans; 
    }
};