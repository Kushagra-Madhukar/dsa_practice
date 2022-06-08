// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int findMaxPath(int i, int j, int N, vector<vector<int>> &Matrix){
    //     if(i == N-1 && j == N-1) return Matrix[i][j];
    //     if(i == N-1) return Matrix[i][j] + findMaxPath(i, j+1)
    //     int bottom = INT_MIN;
    //     int diagonal = INT_MIN;
    //     int right = INT_MIN;
    //     if(i<N-1)
    // }
    int dp[501][501];
    void maxSumPath(int i, int j, int sum, int &maxSum, int N, vector<vector<int>> &Matrix) {
        if(i<0 || j<0) return;
        if(i==N-1) {
            maxSum = max(maxSum, Matrix[i][j] + sum);
            return;
        }
        if(j==N-1) {
            maxSumPath(i+1, j, sum + Matrix[i][j], maxSum, N, Matrix);
            maxSumPath(i+1, j-1, sum + Matrix[i][j], maxSum, N, Matrix);
            return;
        }
        maxSumPath(i+1, j, sum + Matrix[i][j], maxSum, N, Matrix);
        maxSumPath(i+1, j-1, sum + Matrix[i][j], maxSum, N, Matrix);
        maxSumPath(i+1, j+1, sum + Matrix[i][j], maxSum, N, Matrix);
    }
    int recursiveMaxPath(int i, int j, int N, vector<vector<int>> &Matrix) {
        if(i<0 || j<0 || i>=N || j>=N) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        if(i==N-1) return Matrix[i][j];
        int dy[] = {1, -1, 0};
        int ans = INT_MIN;
        for(int u=0;u<3;u++){
            int newY = j + dy[u];
            if(newY>=0 && newY<N){
                ans = max(ans, Matrix[i][j] + recursiveMaxPath(i+1, newY, N, Matrix));
            }
        }
        return dp[i][j] = ans;
        // int a = dp[i+1][j] != -1 ? dp[i+1][j] : Matrix[i][j] + recursiveMaxPath(i+1, j, N, Matrix);
        // int b = dp[i+1][j-1] != -1 ? dp[i+1][j-1] : Matrix[i][j] + recursiveMaxPath(i+1, j-1, N, Matrix);
        // int c = dp[i+1][j+1] != -1 ? dp[i+1][j+1] : Matrix[i][j] + recursiveMaxPath(i+1, j+1, N, Matrix);
        // return dp[i][j] = max(max(a, b), c);
    }
    int maximumPath(int N, vector<vector<int>> Matrix){
        int maxSum = INT_MIN;
        // return findMaxPath(0, 0, N, Matrix);
        memset(dp, -1, sizeof(dp));
        for(int j=0;j<N;j++){
        //   maxSumPath(0, j, 0, maxSum, N, Matrix);
            maxSum = max(maxSum, recursiveMaxPath(0, j, N, Matrix));
        }
        return maxSum;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends