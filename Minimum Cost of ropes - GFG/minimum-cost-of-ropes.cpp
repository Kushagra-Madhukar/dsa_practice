// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        long long minCost = 0;
        priority_queue<long long, vector<long long>, greater<long long>> minRopes;
        for(long long i=0;i<n;i++){
            minRopes.push(arr[i]);
        }
        while(!minRopes.empty() && minRopes.size() > 1){
            long long rope1 = minRopes.top();
            minRopes.pop();
            long long rope2 = minRopes.top();
            minRopes.pop();
            minCost += rope1 + rope2;
            minRopes.push(rope1+rope2);
        }
        return minCost;
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends