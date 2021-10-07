#include <bits/stdc++.h>

using namespace std;

class Solution{
public:

static int comp(string X , string Y)
{
    string XY = X.append(Y);
    string YX = Y.append(X);
    
    return XY.compare(YX) > 0 ? 1 : 0;
}
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	string printLargest(vector<string> &arr) {
	    // code here
        sort(arr.begin() , arr.end(), comp );
        string ans = "";
        for(auto i : arr)
            ans += i;
	
	    return ans;
	}
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
} 