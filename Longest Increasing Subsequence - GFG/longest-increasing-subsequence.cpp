// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        int dp[n+1];
        dp[0] = 1;
        for(int i=1;i<n;i++){
            dp[i] = 1;
            for(int j=i-1;j>=0;j--){
                if(a[i]>a[j]) dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        int max_val = INT_MIN;
        for(int i=0;i<n;i++){
            max_val = max(max_val, dp[i]);
        }
        return max_val;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends