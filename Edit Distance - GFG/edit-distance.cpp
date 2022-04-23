// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int dp[101][101];
    int solve(int m, int n, string s, string t) {
        if(m == 0) return n;
        if(n == 0) return m;
        if(dp[m][n] != -1) return dp[m][n];
        if(s[m-1] == t[n-1]) return dp[m][n] = solve(m-1, n-1, s, t);
        return dp[m][n] = 1 + min(min(solve(m, n-1, s, t), solve(m-1, n, s, t)), solve(m-1, n-1, s, t));
    }
    int editDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        memset(dp, -1, sizeof(dp));
        return solve(m, n, s, t);
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends