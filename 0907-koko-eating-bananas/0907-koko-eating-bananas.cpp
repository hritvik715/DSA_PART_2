class Solution {
public:

    bool canKokoFinishBananasWithKSpeed(vector<int>&piles , int h ,  int k){
        long long int totalHoursTakenByKokoToFinishAllBananas =0;
        for(int i=0; i<piles.size() ;i++)
            totalHoursTakenByKokoToFinishAllBananas += ceil(piles[i] /(double)k);



        // if( totalHoursTakenByKokoToFinishAllBananas <= h) return true;
        // return false;
        //OR
        return  totalHoursTakenByKokoToFinishAllBananas <=h;
        
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int start =1;
        int ans = 0; 
        // auto it = max_element(piles.begin(), piles.end());
        // int end = *it;
        //instead of line 5 and 6 you can direct do this also 
        int end = *max_element(piles.begin(), piles.end());
        //end to mera pakka answer hai
        //mtlb jitni value end ki hai utni speed agar koko rakhegi 
        //toh vo guard se bach jaayegi
        //lekin hame toh minimise karna hai


        //T.C : O(Log(max(piles)) * O(n)) -> O(n*log(ax(piles)))
        while(start  <= end){
            int mid = start + ((end-start)>>1);
            int k= mid;
            if(canKokoFinishBananasWithKSpeed(piles,h,k)){
                //koko will finish all bananas without being caught
                ans = k;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;

    }
};