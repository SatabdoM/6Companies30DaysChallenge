class Solution {
public:
    double f(int row,int col,int k,int n,vector<int>&d_row,vector<int>&d_col,vector<vector<vector<double>>>&dp)
    {
        //base case if the knight goes out of the chessboard or the number of moves by the knight are exhausted
        if(row<0 || row>=n ||col<0|| col>=n )
            return 0;
        //if the number of moves by the knight are exhausted but he is still on the chessboard then return 1
        if(k==0)    
            return dp[row][col][k]=1;

        if(dp[row][col][k]!=-1)
            return dp[row][col][k];

        double step_prob=0;
        for(int i=0;i<8;i++)
        {
            int n_row=row+d_row[i];
            int n_col=col+d_col[i];
            step_prob+=f(n_row,n_col,k-1,n,d_row,d_col,dp)/8;
        }
        return dp[row][col][k]= step_prob;
    }
    double knightProbability(int n, int k, int row, int col) 
    {
        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        vector<int>d_row{-2,-1,1,2,2,1,-1,-2};
        vector<int>d_col{1,2,2,1,-1,-2,-2,-1};
        return f(row,col,k,n,d_row,d_col,dp);
        
    }
};
