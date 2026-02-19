class Solution {
  public:
    

    int longCommSubstr(string& s1, string& s2) {
        // your code here
        int m = s1.length() ;
        int n = s2.length() ;
        vector<vector<int>> dp(m+1, vector<int>(n+1,  0)) ;
        int maxlen = 0 ;
        for(int i=1;i<= m;i++)
        {
            for(int j=1 ;j<=n;j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1] ;
                    maxlen = max(maxlen , dp[i][j]) ;
                }
                else 
                    dp[i][j] = 0 ;  
            }
        }
        return maxlen;
    }
};