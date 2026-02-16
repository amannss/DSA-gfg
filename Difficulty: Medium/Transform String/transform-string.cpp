class Solution {
  public:
    int transform(string A, string B) {
        int n = A.length();
        
        // Step 1: check frequency
        unordered_map<char,int> mp;
        for(char c : A) mp[c]++;
        for(char c : B) {
            mp[c]--;
            if(mp[c] == 0) mp.erase(c);
        }
        if(mp.size() != 0) return -1;
        
        // Step 2: count operations from right
        int i = n - 1;
        int j = n - 1;
        int cnt = 0;
        
        while(i >= 0) {
            if(A[i] == B[j]) {
                i--;
                j--;
            } else {
                cnt++;
                i--;
            }
        }
        
        return cnt;
    }
};
