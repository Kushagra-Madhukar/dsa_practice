// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string S){
        int n = S.size();
        string ans = "";
        for(int i=0;i<n;i++){
            if(n-i < ans.size()) break;
            for(int j=i;j<n;j++) {
                string s1 = S.substr(i, j-i+1);
                string s2 = s1;
                reverse(s2.begin(), s2.end());
                if(s1 == s2 && j-i+1 > ans.size()) ans = s1;
            }
        }
        return ans;
        // string T = S;
        // reverse(T.begin(), T.end());
        // int dp[n+1][n+1] = {-1};
        // for(int i = 0; i<=n;i++){
        //     for(int j=0;j<=n;j++){
        //         if(i==0 || j==0) {
        //             dp[i][j] = 0;
        //             continue;
        //         }
        //         if(S[i-1] == T[j-1]) {
        //             dp[i][j] = 1 + dp[i-1][j-1];
        //             continue;
        //         }
        //         dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        //     }
        // }
        // string lP = "";
        // int i = n, j = n;
        // while(i>0 && j>0){
        //     if(S[i-1] == T[j-1]) {
        //         lP += S[i-1];
        //         i--; j--;
        //     }
        //     else if(dp[i][j-1]>dp[i-1][j]) j--;
        //     else i--;
        // }
        // reverse(lP.begin(), lP.end());
        // return lP;
    }
};

// { Driver Code Starts.



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