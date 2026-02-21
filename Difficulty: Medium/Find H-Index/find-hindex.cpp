class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int n =citations.size() ;
        sort(citations.begin() , citations.end() ,greater<int>());
        int ans ; 
        for(int i=0;i<n;i++)
        {
            if(citations[i] >= i +1 )
            {
                ans = i+1 ;
            }
            else break ;
        }
        return ans ;
    }
};