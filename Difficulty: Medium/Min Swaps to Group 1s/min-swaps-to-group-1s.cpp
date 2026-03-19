class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // Complete the function
        int n = arr.size() ;
        int cntone = 0 ;
        
        for(auto it : arr ) if(it == 1 ) cntone++ ;
        if(cntone == 0)return -1 ;
        int x = 0 ;
        int i =0; int j=0;
        while(j<cntone) if(arr[j++] == 1) x++ ;
        int ans = cntone - x ; ;
        while(j<n)
        {
            if(arr[j] ==1) x++ ;
            if(arr[i]==1) x-- ;
            ans  = min(cntone - x ,ans ) ; 
            i++ ;j++ ;
        }
        return ans ;
    }
};