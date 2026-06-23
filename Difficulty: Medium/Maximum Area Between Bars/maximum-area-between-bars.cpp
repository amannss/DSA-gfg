class Solution {
  public:
    int maxArea(vector<int> &heights) {
        // code here
        int n = heights.size() ;
        int i=0;int j = n-1 ;
        int ans = INT_MIN;
        while(i<j)
        {
            int l = min(heights[i] , heights[j]) ;
            int b = j-i-1 ;
            ans = max(ans , l*b) ;
            if(heights[i] < heights[j]) i++ ;
            else j-- ;
        }
        return ans ;
    }
};