class Solution {
  public:
    int LongestRepeatingSubsequence(string &s) {
        // Code here
        int m = s.length() ;
        string r = s ; 
        vector<vector<int>> dp(m+1 , vector<int>(m+1 , 0)) ;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1] == r[j-1] && i != j)
                {
                    dp[i][j] = 1+ dp[i-1][j-1] ;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) ;
                }
            }
        }
        return dp[m][m] ;
    
    }
};