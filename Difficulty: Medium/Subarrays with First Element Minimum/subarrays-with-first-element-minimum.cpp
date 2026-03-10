class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        int n= arr.size() ;
        vector<int> vec(n ,-1)  ;
        stack<int> st ;
        st.push(0) ;
        for(int i= 1 ;i <n;i++)
        {   
            while(!st.empty() && arr[i] < arr[st.top()])
            { 
                int t=  st.top() ;
                vec[t] = i ;
                st.pop() ;
            }
            st.push(i) ;
            
        }
        int ans = 0;
        for(int i =0 ;i<n ;i++)
        {
            if(vec[i] == -1) ans += n - i  ;
            else ans += vec[i] - i  ;
        }
        return ans ;
    }
};