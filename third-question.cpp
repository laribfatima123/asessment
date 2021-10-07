
#include<bits/stdc++.h> 
using namespace std; 


class Solution{   
public:
    
    int maxPal(int i,int j,string s)
    {
        if(i<0 || j>=s.length() || s[i]!=s[j]) return 0;
        return 1+maxPal(i-1,j+1,s);
    }

    string longestPalindrome(string S){
        int ans=0,n=S.length();
        string res;
        for(int i=0;i<n;i++)
        {
            int o=maxPal(i,i,S),e= i==n-1? -1:maxPal(i,i+1,S);
            if(2*o-1>ans) 
            {
                ans = 2*o-1;
                res=S.substr(i-o+1,2*o-1);
            }
            if(2*e>ans)
            {
                ans = 2*e;
                res=S.substr(i-e+1,2*e);
            }
        }
        return res;
    }
};





int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends