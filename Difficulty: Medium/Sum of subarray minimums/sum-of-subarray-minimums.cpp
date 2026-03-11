class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n =arr.size() ;
        vector<int> nsl(n,-1) ;
        vector<int> nsr(n ,n );
        stack<int> st ;
        int mod = 1e9 + 7 ;
        
        for(int i=0;i<n ;i++ )
        {
            while(!st.empty() && arr[st.top() ] > arr[i])
            {
                int t =st.top() ;
                nsr[t] = i ;
                st.pop() ;
            }
            st.push(i) ;
        }
        while(!st.empty()) st.pop();
        
        for(int j =n-1;j>=0 ;j--)
        {
            while(!st.empty() && arr[st.top() ] >= arr[j])
            {
                int t = st.top() ;
                nsl[t]=  j ;
                st.pop() ;
            }
            st.push(j) ;
        }
        
        int ans = 0;
        for(int i= 0; i< n;i++)
        {   
            int count = (i - nsl[i]) * (nsr[i] - i ) ;
            ans += count   * arr[i] ;
        }
        return ans % mod  ; 
    }
};