// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int dp[101][101];
    int matrixMultHelper(int i, int j, int arr[]) {
        if(i>=j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int min_mult = INT_MAX;
        for(int k = i; k<j; k++){
            int temp_ans = matrixMultHelper(i, k, arr) + matrixMultHelper(k+1, j, arr) + arr[i-1] * arr[k] * arr[j];
            min_mult = min(temp_ans, min_mult);
        }
        return dp[i][j] = min_mult;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        if(N<=2) return 0;
        memset(dp, -1, sizeof(dp));
        return matrixMultHelper(1, N-1, arr);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends