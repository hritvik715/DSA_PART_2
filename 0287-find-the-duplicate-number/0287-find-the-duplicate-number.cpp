class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> freq;  // map to store frequency of each number

        for (int num : nums) {
            // freq[num]++;              // increase count
            freq[num] = freq[num] + 1; //freq[1] does not exist yet, so by default freq[1] = 0
            if (freq[num] > 1) {      // if count > 1 → duplicate found
                return num;
            }
        }

        return -1; // no duplicate found (theoretically won't happen as per problem)
    }
};


//  Iteration 1 → num = 3
//  freq = { 3 : 1 }

//  Iteration 2 → num = 1
//  freq = { 1 : 1 , 3 : 1 }

//  Iteration 3 → num = 3
//  freq = { 1 : 1 , 3 : 2 }  ← duplicate found here!
//  return 3
