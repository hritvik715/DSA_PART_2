class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> freq;  // map to store frequency of each number

        for (int num : nums) {
            freq[num]++;              // increase count
            if (freq[num] > 1) {      // if count > 1 → duplicate found
                return num;
            }
        }

        return -1; // no duplicate found (theoretically won't happen as per problem)
    }
};