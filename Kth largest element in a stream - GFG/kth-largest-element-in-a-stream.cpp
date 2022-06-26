// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i=0;i<k-1;i++){
            ans.push_back(-1);
            minHeap.push(arr[i]);
        }
        for(int i=k-1;i<n;i++){
            minHeap.push(arr[i]);
            if(minHeap.size()>k){
                minHeap.pop();
            }
            ans.push_back(minHeap.top());
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends