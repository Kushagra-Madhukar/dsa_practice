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