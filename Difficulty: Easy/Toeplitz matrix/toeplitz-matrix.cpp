class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        // code here
        int r = mat.size() ;
        int c = mat[0].size() ;
        
        for(int k = 0 ;k < r ; k++)
        {   
            int i = k; 
            int j = 0 ;
            int val = mat[i][j] ;
            while(i < r && j < c)
            {
                if(mat[i][j] != val ) return false ;
                i++ ;j++;
            }
        }
        for(int k = 0 ;k<c ; k++)
        {
            int i = 0 ;
            int j = k ;
            int val = mat[i][j] ;
            while(i < r && j < c)
            {
                if(mat[i][j] != val ) return false ;
                i++ ;j++;
            }
        }
        return true  ;
    }
};