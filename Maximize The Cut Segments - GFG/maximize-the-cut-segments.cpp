// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int dp[n+1];
        dp[0] = 0;
        for(int i = 1; i<n+1;i++) dp[i] = -1;
        for(int i = 1; i<n+1;i++) {
            int t = -1, k = -1, l = -1;
            if(i >= x) t = dp[i-x];
            if(i >= y) k = dp[i-y];
            if(i >= z) l = dp[i-z];
            if(t >= 0 || k >= 0 || l >= 0) dp[i] = 1 + max({t, k , l});
        }
        return max(dp[n], 0);
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends