class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        priority_queue<int , vector<int> , greater<int>> pq ;
        int n = arr.size(); 
        vector<int> ans(n) ;
        for(int i= 0; i<n;i++)
        {   pq.push(arr[i]) ;
            if(pq.size() <k )
            {   
                ans[i] = -1 ;
                continue ;
            }
            else 
            {
                if(pq.size() > k) pq.pop() ;
                ans[i] = pq.top() ;
            }
        }
        return ans; 
    }
};