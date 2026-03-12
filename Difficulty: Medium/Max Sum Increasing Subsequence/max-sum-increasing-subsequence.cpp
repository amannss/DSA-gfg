class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        // code here
        int n= arr.size() ;
        vector<int> dp(n) ;
        for(int i = 0; i < n; i++) dp[i] = arr[i];
        dp[0] = arr[0] ;
        int sum = arr[0] ;
        for(int i =1; i<n;i++)
        {
            for(int j = 0 ; j < i ;j++)
            {   
                
                if(arr[i] >arr[j])
                {
                    int take  = arr[i] + dp[j] ;
                    dp[i] = max(dp[i] , take ) ;
                    sum = max(sum , dp[i]) ;
                }
            }
        }
        return sum ;
    }
};