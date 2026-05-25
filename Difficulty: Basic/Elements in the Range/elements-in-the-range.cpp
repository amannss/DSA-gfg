class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        int n =  end - start + 1 ;
        // if(arr.size() < n) return false ;
        int cnt = 0 ;
        for(int i= 0;i< arr.size() ;i++ )
        {   
            if(arr[i] == start || arr[i]== end) cnt++ ;
            else if(arr[i] > start && arr[i] < end) cnt++ ;
        } 
        return cnt == n ;
    }
};
