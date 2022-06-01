// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unordered_map<string, int> mp;
    int solve(int i, int j, string &S, bool isTrue) {
        if(i>j) return 0;
        if(i==j) {
            if(isTrue) return S[i] == 'T';
            else return S[i] == 'F';
        }
        string key = to_string(i);
        key.append(" ");
        key.append(to_string(j));
        key.append(" ");
        key.append(to_string(isTrue));
        if(mp.find(key) != mp.end()) return mp[key];
        int ans = 0;
        for(int k=i+1;k<j;k+=2) {
            int lT = solve(i, k-1, S, true);
            int lF = solve(i, k-1, S, false);
            int rT = solve(k+1, j, S, true);
            int rF = solve(k+1, j, S, false);
            if(S[k] == '&') {
                if(isTrue) ans += lT*rT;
                else ans += lF*rF + lF*rT + lT*rF;
            }
            else if(S[k] == '|') {
                if(isTrue) ans += lT*rT + lT*rF + lF*rT;
                else ans += lF*rF;
            }
            else if(S[k] == '^') {
                if(isTrue) ans += lT*rF + lF*rT;
                else ans += lT*rT + lF*rF;
            }
        }
        return mp[key] = ans % 1003;
    }
    int countWays(int N, string S){
      mp.clear();
      return solve(0, N-1, S, true); 
    }
};
// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends