// class Solution {
// public:
//     int getPivotIndex(vector<int>& arr){
//         int s=0;
//         int n= arr.size(); 
//         int e = n-1;
//         int mid= s + (e-s)/2;

//         while(s<=e){
//             if(s==e){//single elemnt vaale case kay andar (-1) return ho rhi thi jo ki hame nhi karni thi toh hamne uss single elemnt ko hi pivot maan liya hai
//                 return s;
//             }
//             if( mid+1 < n && arr[mid] > arr[mid+1]){//valid index honi chahiye islie (mid+1 < n) kiya
//                 return mid;
//             }
//             // if(mid+1 < n && arr[mid]>arr[mid+1] && mid-1>=0 &&arr[mid]>arr[mid-1] && mid+1>=0){//(mid-1) and arr[mid-1]  exist hi nhi hogi agar sirf two elements hue array mey (galat hai ye if condition)
//             //     return mid;
//             // }
            
//             // if( mid-1 >=0 && arr[mid] <arr[mid-1]){//iss condition ki need nhi hai
//             //     return mid-1;
//             // }
//             //kab left orr kab right
//             if(arr[s] > arr[mid]){//toh abb left jaana padega (line A mey arr[s] ki value sabse chooti hogi kuki array sorted hai dono line mey )
//                 e = mid-1;
//             }
//             else{//arr[mid] > arr[s]
//                 //right
//                 s = mid+1;
//             }
//             mid= s + (e-s)/2;
//         }
//         return -1;//upper return nhi hua toh yha return hogi
//     }

//     int binarySearch(vector<int>& arr , int s , int e , int target){
//         int mid = s + (e-s)/2;
//         while(s<=e){
//             if(arr[mid] == target){
//                 return mid;
//             }
//             if(arr[mid] > target){
//                 e = mid-1;
//             }
//             if(arr[mid] < target){
//                 s = mid+1;
//             }
//             mid = s+(e-s)/2;
//         }
//         return -1;
//     }

//     int search(vector<int>& nums, int target) {
//         int pivotIndex = getPivotIndex(nums);
//         //line A -> index -> 0 -> pivotIndex
//         //line B -> pivotIndex+1 -> n-1
//         int n= nums.size();
//         //if target lies inside line A then search in line A
//         if(target >= nums[0] && target <= nums[pivotIndex]){
//             //BS apply
//             int ans = binarySearch(nums , 0 , pivotIndex , target);
//             return ans;
//         }
//         // if target lies inside line B then search in line B
//         // else if(target >= nums[pivotIndex+1] && target <= nums[n-1]){//bhai jb pivotIndex last element pe hoga(n-1) tb (pivotIndex+1) out of bonds ho jayega jisse else if true hi nahi hogi(sayad isi vajah se error arra h), isliye pahle check krna padega ki pivotIndex valid h ya nahi 

//         else if( pivotIndex + 1 < n  && target >= nums[pivotIndex+1] && target <= nums[n-1]){//ye bhi shi hai
//         // // else{
//         //     //BS apply
//             int ans = binarySearch(nums , pivotIndex+1 , n-1 , target);
//             return ans;
//         }

//         // else if(target < nums[pivotIndex] && target <= nums[n-1]){//ye bhi shi hai
//             // int ans=binarySearch(nums , pivotIndex+1 , n-1 , target);
//             // return ans;
//         // }
//         return -1;

//     }
// };//Consider the array [4, 5, 6, 7], which is not rotated (it's already sorted). The pivot index in this case would be the last element since it's the largest and no rotation has taken place. Let's say we are searching for the target 7.

// // Determine the Pivot Index:
// // In this array, the pivot index returned by getPivotIndex would be 3 (the index of the value 7).

// // Without the Condition (pivotIndex + 1 < n) in search:
// // We check if the target 7 is between nums[0] and nums[pivotIndex] (i.e., 4 and 7), and it is.
// // But if we were looking for a number greater than 7, say 8, we would move to the else if condition.

// //The Problematic Else If Condition:
// // else if (target >= nums[pivotIndex + 1] && target <= nums[n - 1])
// // If pivotIndex is 3 (the last index), pivotIndex + 1 would be 4.
// // nums[4] would be out of bounds since the array only has indices 0 to 3.





























class Solution {
public:
    int getPivotIndex(vector<int>& arr){
        int s=0;
        int n= arr.size(); 
        int e = n-1;
        int mid= s + (e-s)/2;

        while(s<=e){
            if(s==e){
                return s;
            }
            if( mid+1 < n && arr[mid] > arr[mid+1]){
                return mid;
            }
            if(arr[s] > arr[mid]){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid= s + (e-s)/2;
        }
        return -1;
    }

    int binarySearch(vector<int>& arr , int s , int e , int target){
        int mid = s + (e-s)/2;
        while(s<=e){
            if(arr[mid] == target){
                return mid;
            }
            if(arr[mid] > target){
                e = mid-1;
            }
            if(arr[mid] < target){
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivotIndex = getPivotIndex(nums);
        int n= nums.size();
        if(target >= nums[0] && target <= nums[pivotIndex]){
            int ans = binarySearch(nums , 0 , pivotIndex , target);
            return ans;
        }
        else if( pivotIndex + 1 < n && target >= nums[pivotIndex+1] && target <= nums[n-1]){
            int ans = binarySearch(nums , pivotIndex+1 , n-1 , target);
            return ans;
        }
        return -1;
    }
};