class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // int rows  = matrix.size();
        // int columns  = matrix[0].size();
        // //total elements
        // int n = rows * columns;

        // int s = 0;
        // int e = n-1;
        // int mid = s + (e-s)/2;
        // while(s<=e){
        //     //mid ka use karke 2d array ka rowIndex and colIndex find karenge
        //     int rowIndex = mid/columns;
        //     int colIndex = mid%columns; 

        //     if(matrix[rowIndex][colIndex] == target){
        //         return true;
        //     }
        //     if(target > matrix[rowIndex][colIndex]){
        //         //right
        //         s = mid + 1;
        //     }
        //     else{
        //         //left
        //         e = mid -1;
        //     }
        //     mid = s + (e-s)/2;
        // }
        // return false;






        int rows = matrix.size();
        int cols = matrix[0].size();

        int size = rows*cols;
        int s=0;
        int e=size-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            int rowindx = mid/cols;
            int colindx = mid%cols;

            if(matrix[rowindx][colindx] == target){
                return true;
            }
            else if(matrix[rowindx][colindx] > target){
                e = mid-1;
            }
            else{ //arr[rowindx][colindx] < target
                s = mid+1;
            }
        }
        return false;

    }
};












class solution {
    public:
    bool seaarch(vector<vector<int>> &matrix , int target){
        int nrow = matrix.size();
        int ncol = matrix[0].size();
        int n=nrow*ncol;

       
        int s=0;
        int e = n-1;

        int mid = s+(e-s)/2;
        while(s<=e){
            int rowIndex = mid/ncol;
            int colIndex = mid%ncol;
            if(matrix[rowIndex][colIndex]==target){
                return true;
            }
            else if(matrix[rowIndex][colIndex] <target){
                s = mid+1;
            }
            else{//matrix[r][c] > target
                e = mid-1;
            }
        }
        return false;
    }
};






















