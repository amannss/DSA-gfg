class Solution {
  public:
  typedef long long ll ; 

    int numTrees(int v) {
        // ncr = n! /r!(n-r)!
        // in catalan number 
        // n = 2n aand r = n where n is given so 
        // let ncr
        int n = 2*v ;
        int r= v ;
        
        ll ans = 1  ;
        for(int i =1 ; i<=r ;i++)
        {
            ans = ans *(n-r+i) ;
            ans = ans / i  ;
        }
        ans /= (v+1 ) ; // catalan formula 
        return ans ;
    }
    vector<int> countBSTs(vector<int>& arr) {
        // Code here
        vector<int> temp = arr ; 
        int n = arr.size() ;
        sort(temp.begin() ,temp.end() ) ;
        unordered_map<int ,pair < int , int>> mp ;
        for(int i=0;i<n ; i++) // O(n) ; traaverse in temp 
        {
            int smaller = i - 0 ;
            int larger =  n - i - 1;
            mp[temp[i]] = { smaller , larger } ;
        }
        for(int i=0 ; i<n;i++)// O(n) ; traverse in arr 
        {
            int smaller = mp[arr[i]].first ;
            int larger = mp[arr[i]].second ;
            int ans = numTrees(smaller ) * numTrees(larger ) ;
            arr[i] = ans ;
        }
        return arr ;
    }
};