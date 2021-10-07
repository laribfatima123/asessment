#include<iostream> 
using namespace std; 

 
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    struct meeting {
        int s;
        int e;
        int o;
    };
    
    static bool comp( struct meeting m1, struct meeting m2){
        if(m1.e< m2.e) return true;
        else if (m1.e> m2.e) return false;
        else if(m1.o < m2.o) return true;
        return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        struct meeting m[n];
        
        for(int i=0; i<n;i++){
            m[i].s = start[i];
            m[i].e = end[i];
            m[i].o = i+1;
         }
         
         sort(m,m+n,comp);
         vector<int> ans;
         int endCount= m[0].e;
         ans.push_back(m[0].o);
         int c=1;
         
         for(int i= 1; i<n ;i++){
             if(m[i].s > endCount){
                 endCount= m[i].e;
                 ans.push_back(m[i].o);
                 c++;
             }
         }
         return c;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  