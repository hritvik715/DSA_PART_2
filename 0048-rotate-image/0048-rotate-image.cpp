class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //step-1. Transpose
        int nrows=matrix.size();
        int ncols = matrix[0].size();

        //ncols ans nrows both are equal

        for(int i =0 ; i<nrows ; i++){
            for(int j =i ; j<ncols ; j++){
                swap(matrix[i][j] , matrix[j][i]);
            }    
        }
        //step 2 reverse row wise 
        for(int i=0 ; i<nrows;i++){
            reverse(matrix[i].begin() , matrix[i].end());//array bna kay aise reverse nhi hoga VS code mey
        }
    }
};

//vs code mey aise create karte 2d vector
// vector<vector<int>> brr ={
//     {1,2,3},
//     {4,5,6},
//     {7,8,9},
//    };
  
//     for(int i=0;i<3 ; i++){
//         reverse(brr[i].begin() ,brr[i].end());
//     }

//     for(int i=0;i<3 ;i++){
//         for(int j=0 ; j<3;j++){
//             cout<<brr[i][j]<<" ";
//         }
//         cout<<endl;
//     }







class solution{
    public:
    void rotate(vector<vector<int>>& nums){
        int nrows = nums.size();
        int ncols = nums[0].size();
        //transpose nikaal rhe hai
        for(int i=0 ; i<nrows ; i++){
            for(int j=i ; j<ncols ; j++)
            swap(nums[i][j] , nums[j][i]);
        }
        for(int i=0 ;i<nrows ; i++){
            reverse(nums.begin() , nums.end());
        }
    }
};























