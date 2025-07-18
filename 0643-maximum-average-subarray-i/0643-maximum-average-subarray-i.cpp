class Solution {
public:
    // double bruteForce(vector<int>&nums , int &k){
    //     int maxSum = INT_MIN;
    //     int i =  0 , j = k-1;
    //     while(j <nums.size()){//O(n)
    //         int sum = 0;//har new loop kay liye sum=0 hai
    //         for(int y=i ; y<=j ; y++){//n se kam chlega ye loop lekin phir bhi O(n) hi hoga
    //             sum += nums[y];
    //         }
    //         maxSum = max(maxSum , sum);
    //         j++;
    //         i++;
    //     }
    //     // double maxAvg = maxSum / k;//int/int =int aayega decimal laane kay liye (int/float) ya     (float/int) karna hoga
    //     double maxAvg = maxSum / (double)k;
    //     return maxAvg;
    // }

    // double sldiding window method ye O(n) mey chal rha hai
    double slidingWindow(vector<int>& nums , int& k){
        int i =0 , j=k-1;//4-1=3
        int sum = 0;
        for(int y=i  ; y<=j ; y++){
            sum += nums[y];
        }
        int maxSum = sum;
        j++;//j==4//j==6//agar (j) pehle  hi out of bound chla gya toh while loop chalega hi nhi
        while(j <  nums.size()){//note->Bhai line 32 ke baad firse while condition evaluate     hogi...tum vapas line 28 pe kyun Jaa rhe ho
            sum -= nums[i++];
            sum += nums[j++];//j=5 (pehle pichla J use karna hai phir increase karna hai )
            maxSum = max(maxSum , sum);
        }
        double maxAvg = maxSum / (double)k;

        return maxAvg;
    }


    double findMaxAverage(vector<int>& nums, int k) {
        // return bruteForce(nums , k);
        return slidingWindow(nums,k);
    }
};