class Solution {
  public:
   typedef long long ll ;
    int maxPeopleDefeated(int p) {
        // Code Here
        ll l = 1 ; ll h = 10000;
        ll ans = 0  ; 
        while(l <= h )
        {
            ll mid = (l+h) /2 ;
            ll check  = ( mid *(mid + 1 )*(2*mid+1) )/6 ; // this gives sum till mid 
            if(check <= p )  { ans = mid ;l = mid + 1 ; }
            else h = mid  - 1 ;
            
        }
        return (int)ans ;
    }
};
