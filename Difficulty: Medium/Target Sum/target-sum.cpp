class Solution {
  public:
    int solve(vector<int>& arr ,int target , int idx, vector<vector<int>> &dp)
    {
        if(target < 0) return 0 ;
        
        if(idx == 0)
        {
            if(target == 0 && arr[0] == 0) return 2;
            if(target == 0 || target == arr[0]) return 1;
            return 0;
        }
        
        if(dp[idx][target] != -1) return dp[idx][target];
        
        int not_take = solve(arr, target, idx-1, dp);
        int take = 0;
        if(arr[idx] <= target)
            take = solve(arr, target - arr[idx], idx-1, dp);
        
        return dp[idx][target] = take + not_take;
    }

    long long findTargetSumWays(int n, vector<int>& arr, int target) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        if(sum < abs(target)) return 0;
        if((sum + target) % 2 != 0) return 0;
        
        int req = (sum + target) / 2;
        
        vector<vector<int>> dp(n, vector<int>(req+1, -1));
        return solve(arr, req, n-1, dp);
    }
};
