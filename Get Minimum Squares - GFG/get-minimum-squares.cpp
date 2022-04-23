// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int MinSquares(int n)
	{
	    int dp[n+1] = {INT_MAX};
	    dp[0] = 0;
	    for(int j = 1; j<=n; j++){
	        dp[j] = j;
	        for(int i = 1; i*i<=j;i++){
	            dp[j] = min(1 + dp[j - i*i], dp[j]);
	        }
	    }
	    return dp[n];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends