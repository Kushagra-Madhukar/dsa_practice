// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int dp[1001][1001];
    // int maxScore1(int i, int j, int arr[]) {
    //     if(dp[i][j] != -1) return dp[i][j];
    //     switch(j-i) {
    //         case 0:
    //             return arr[i];
    //         case 1:
    //             return dp[i][j] = max(arr[j], arr[i]);
    //         default:
    //             return dp[i][j] = max(arr[i] + maxScore1(i+1, j), arr[j] + maxScore1(i, j-1));
    //     }
    // }
    int helper(int i, int j, int arr[]){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(j==i) return dp[i][j] = arr[i];
        int x = dp[i][j-2] != -1 ? dp[i][j-2] : helper(i, j-2, arr);
        int y = dp[i+1][j-1] != -1 ? dp[i+1][j-1] : helper(i+1, j-1, arr);
        int z = dp[i+2][j] != -1 ? dp[i+2][j] : helper(i+2, j, arr);
        int a = arr[i] + min(y, z);
        int b = arr[j] + min(x, y);
        return dp[i][j] = max(a, b);
    }
    bool is1winner(int N,int arr[]) {
        memset(dp, -1, sizeof(dp));
        long long int totalSum = 0;
        for(int i=0;i<N;i++) totalSum += arr[i];
        long long int firstSum = helper(0, N-1, arr);
        return firstSum > (totalSum - firstSum);
        // 2 , 6 , 3
        //j-i == 0 => return a[i]
        // j-i == 1 => return dp[i][j] = max(a[j], a[i])
        //else return dp[i][j] = max(a[i] + score1(i+1, j), a[j] + score1(i, j-1))
        // 2 + score1(6, 3)
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.is1winner(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends