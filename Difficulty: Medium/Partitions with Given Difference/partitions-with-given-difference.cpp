class Solution {
  public:

  int solve(vector<int>& arr, int target, int idx, vector<vector<int>>& dp)
  { 
      if(target < 0 ) return 0 ;
      if(idx == 0 )
      {
          if(target == 0 && arr[0]== 0) return 2;
          if(target == 0 || arr[0]== target ) return 1 ;
          return 0;
      }

      if(dp[idx][target] != -1) return dp[idx][target];

      if(arr[idx] <= target)
      {
          return dp[idx][target] =
              solve(arr, target - arr[idx], idx-1, dp) +
              solve(arr, target, idx-1, dp);
      }
      else 
          return dp[idx][target] =
              solve(arr, target, idx-1, dp);
  }

  int countPartitions(vector<int>& arr, int diff) {
      int sum = accumulate(arr.begin(), arr.end(), 0);

      if(sum < diff) return 0; // not possible
      if((sum + diff) % 2 != 0) return 0; // odd 

      int target = (sum + diff) / 2;
      int n = arr.size() ; 
      vector<vector<int>> dp(n, vector<int>(target + 1, -1));

      int ways = solve(arr, target, n- 1 , dp);

      return ways ;
  }
};
