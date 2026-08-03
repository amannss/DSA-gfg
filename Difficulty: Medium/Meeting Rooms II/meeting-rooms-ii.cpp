class Solution {
  public:
  typedef pair <int ,int> p ;
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int n  = start.size() ;
        vector<p> vec ; 
        for(int i = 0 ; i < n ;i++)
        {
            vec.push_back({start[i] , end[i]});
        }
        sort(vec.begin() , vec.end() ) ;
        priority_queue< p , vector<p> , greater <p>> pq ;
        int cnt = 1 ;
        int i = 0 ;
        while( i < n )
        {
            int a = vec[i].first ; int b = vec[i].second ;
            while(!pq.empty() && pq.top().first <=a )
            {
                pq.pop() ;
            }
            i++ ;
            pq.push({b ,a }) ;
            int v =  pq.size() ;
            cnt = max(cnt , v)  ;
        }
        return cnt ;
    }
};
