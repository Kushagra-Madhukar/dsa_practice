// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int dp[201][201];
    bool solve(string p, string s, int m, int n){
        if(m == 0 && n == 0) return true;
        if(m==0) return false;
        if(n==0) {
            int i = m;
            while(i>0){
                if(p[i-1] != '*') return false;
                i--;
            }
            return true;
        }
        if(dp[m][n] != -1) return dp[m][n];
        if(p[m-1] == s[n-1] || p[m-1] == '?') return dp[m][n] = solve(p, s, m-1, n-1);
        if(p[m-1] == '*') return dp[m][n] = solve(p, s, m-1, n) || solve(p, s, m, n-1);
        return dp[m][n] = false;
    }
    int wildCard(string pattern,string str)
    {
        int m = pattern.size();
        int n = str.size();
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 && j==0) dp[i][j] = 1;
                else if(i==0) dp[i][j] = 0;
                else if(j==0){
                    int k = i;
                    bool flag = true;
                    while(k>0){
                        if(pattern[k-1] != '*') flag = false;
                        k--;
                    }
                    dp[i][j] = flag;
                }
                else if(pattern[i-1] == str[j-1] || pattern[i-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(pattern[i-1] == '*') dp[i][j] = dp[i][j-1] || dp[i-1][j];
                else dp[i][j] = false;
            }
        }
        return dp[m][n];
    }
};

// { Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}
  // } Driver Code Ends