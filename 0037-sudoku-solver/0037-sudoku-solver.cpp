class Solution {
public:
    bool isSafe(int digit , int row,int col,vector<vector<char>>&board){
        // 3 rule

        //rowCheck
        int n= board.size();
        for(int k=0;k<n;k++){
            //same digit pehle se same row mey exist karta hai
            if(board[row][k] == digit){
            return false;
            }
        } 


        //colCheck
        for(int k=0;k<n;k++){
            if(board[k][col] == digit){
                //same col mey same digit pehle se exist karta hai
                return false;
            }
        }
        //3*3 sub-box check (if statmnt ko dry run kre tabhi samjh aayega)
        for(int k=0; k<n ;k++){
            if(board[3*(row/3) + k/3][3*(col/3)+k%3] ==digit ){
                //same 3*3 box mey same digit exist karta hai
                return false;
            }
        } 
        //agar teeno rule badhiya follow ho rhe hai toh kya karna hai
        return true;   
    }



    bool solve(vector<vector<char>>&board){
        //entire logic
        //base case

        //1 case hum solve krenge baaki recursn sambhaal lega
        //sabse pehle find the empty cell
        //empty ki pehchaan => '.'(dot hogi uss jagah pe)
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size() ;j++){
                //mai i,j vaali cell par aa gya
                //par pta kaise lagega ki data fill kru ya nhi
                //sirf empty cell par fill karenge
                if(board[i][j] =='.'){
                    //fill this cell, coz its empty
                    //empty cell par mujhe 1->9 digit hit and trial krne hai
                    for(char digit='1';digit<='9';digit++){
                        //konsa digit rakh sakta hu , ye kaise pta lagega
                        //mujhe bss check karna hai , ki konsa digit rakhna safe hai
                        if(isSafe(digit, i ,j,board) ==true){
                            //agar safe hai rakhna
                            board[i][j] = digit;
                            //baaki kon sambhaalega -> recursion
                            bool aageSolveHoPaya= solve(board);
                            if(aageSolveHoPaya ==true){
                                //poora board solve hogya
                                return true;
                            }
                            else{
                                //ye vo case hai -> jha tumne ek digit place krdi hai but recursion se aage ka answer false aa gya
                                //aage board solve nhi ho paya
                                //backtrack -> shayad maine galat digit rakh dia
                                board[i][j]='.';
                            }
                        }
                    }
                    //agar aap yha phoch gye
                    //iska mtlb ye h-> 1->9 takk koi bhi digit yha parr fit nhi ho rhi
                    //pichle khi par galti kari hai
                    return false;
                }
            }
        }
        //yha aagye -> iska matlab
        //board -> completely filled ho gya hai
        //ans aa chuka hai
        return true; 
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};