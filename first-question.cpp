#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string func(string a,char r1,char r2){
        for(int i=0;i<a.length();i++){
            if(a[i]==r1){
                a[i]=r2;
            }
            else if(a[i]==r2){
                a[i]=r1;
            }
        }
        return a;
    }
    string chooseandswap(string a){
        map<char, int> m;
        char c='a';
        for(int i=0;i<26;i++){
            m[c]=-1;
            c++;
        }
        for(int i=0;i<a.length();i++){
            if(m[a[i]]==-1){
                m[a[i]]=i;
            }
        }
        for(int i=0;i<a.length();i++){
            c='a';
            char r='z';
            int f=0;
            for(;c<a[i];c++){
                if(m[c]!=-1){
                    if(m[c]>i){
                        f=1;
                        r=c;
                        break;
                    }
                }
            }
            if(f==1){
                return func(a,a[i],r);
            }
        }
        return a;
    }
    
};



int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
