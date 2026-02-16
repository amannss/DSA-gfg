// User function Template for C++

class Solution {
  public:
  int solve(vector<int>&price , vector<int> &len ,int N,int idx ,vector<vector<int>> &dp)
  {     
      if(idx==0 )
      {
          return N*price[0] ;
      }
      if(dp[idx][N]!= -1 ) return dp[idx][N] ;
      if(len[idx]<=N)
      {
          return dp[idx][N] = max(price[idx-1] + solve(price ,len,N-len[idx] ,idx , dp)
                                ,solve(price,len,N,idx-1,dp));
      }
      else return dp[idx][N] = solve(price , len ,N,idx-1, dp) ;
  }
    int cutRod(vector<int> &price) {
        // code here
        int n =price.size() ;
        vector<int> len(n+1) ;
        for(int i=0;i<=n;i++) len[i] = i ;
        
        vector<vector<int>> dp(n+1 ,vector<int>(n+1  , -1)) ;
        int ans = solve(price , len , n ,n,dp) ;
        return ans ;
    }
};