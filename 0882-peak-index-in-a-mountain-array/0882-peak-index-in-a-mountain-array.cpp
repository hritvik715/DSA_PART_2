class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //isse ham max in an array se bhi kar sakte hai lekin uski complexity O(n) hoti here hame O(logn) mey karna hai
        // //1st methodd
        // int max = INT_MIN;
        // int maxIndex = -1;
        // for(int i =0 ; i<arr.size() ; i++){
        //     if(arr[i] > max){
        //         max = arr[i];
        //         maxIndex = i;
        //     }
        //     return maxindex;
        // }



        //using O(logn) => binary search(thoda musqil method)

        // int s=0;
        // int n = arr.size();
        // int e = n-1;
        // int mid = s + (e-s)/2;
        // while(s<e){
        //     if(arr[mid] <arr[mid+1]){
        //         //move right
        //         s = mid + 1;
        //     }
        //     else{
        //         //ya toh main line B par hu
        //         //ya toh mai ans pr hi hu
        //         e = mid;
        //     }
        //     mid = s + (e-s)/2;
        // }
        // return mid;//start bhi same block pe chla jaayegaa , end bhi same block pe chla jaayega and toh mid bhi same block mey ho jaayega jo tum return karna chaho kar sakte ho
        // return s;
        // return e;




        //3rd method(aasaan tareeka)(store and compute technique)
        // int s=0;
        // int n = arr.size();
        // int e = n-1;
        // int mid = s + (e-s)/2;
        // int ansIndex= -1;
        // while(s<=e){
        //     if(arr[mid]<arr[mid+1]){
        //         // ansIndex = mid +1;
        //         s = mid+1;
        //     }
        //     else{// arr[mid] < arr[mid-1] or arr[mid] > arr[mid+1]   
        //         //may or may not be
        //         ansIndex = mid;//answer store kra liya
        //         e = mid -1;//and baad mey mujhe left toh jaana hi hai
        //     }
        //     mid =  s + (e-s)/2;// (1-(1/2)) =1  and (1+0)/2 = 0
        // }
        // return mid;



        //4th method(babbar se thoda sa different method)
        // int ans = -1;
        // int start = 0;
        // int end = arr.size()-1;
        // while(start <= end){
        //     int mid = (start + (end-start)/2);
        //     if(arr[mid+1] > arr[mid]){//A
        //         //peak hoga right side
        //         start = mid+1;
        //     }
        //     else if(arr[mid] < arr[mid-1]){
        //         //line B
        //         //peak hogi left mey
        //         //left move kro
        //         end  = mid-1;
        //     }
        //     else{
        //         ans =  mid;//jabb answer milega then only it will be true 
        //         break;
        //     }
        // }
        // return ans;







        //5th method
        int s=0;
        int e= arr.size()-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid] > arr[mid+1] && arr[mid]>arr[mid-1]){
                return mid;
            }
            else if(arr[mid+1] > arr[mid]){
                s = mid+1;
            }
            else{//arr[mid+1] < arr[mid]
                e = mid-1;
            }
        }
        return 0;
    }
};//sirf last kay 3 methods dekh