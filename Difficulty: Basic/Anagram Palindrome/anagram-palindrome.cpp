class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        vector<int> freq(26,0) ;
        int n  =s.length() ;
        for(int i=0;i<n;i++) freq[s[i] - 'a']++ ;
        int cntodd= 0;
        for(int i=0;i<26;i++)
        {
            if(freq[i]%2 != 0) cntodd++;
            if(cntodd > 1) return false ;
        }return true ;
    }
};