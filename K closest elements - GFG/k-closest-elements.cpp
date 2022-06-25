// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int i=0;i<n;i++){
            int diff = abs(arr[i]-x);
            if(diff!=0) minHeap.push({diff, arr[i]});
        }
        int i = 0;
        while(i<k && !minHeap.empty()){
            int absdiff = minHeap.top().first;
            int val = minHeap.top().second;
            minHeap.pop();
            if(!minHeap.empty() && minHeap.top().first == absdiff) {
                priority_queue<int> maxHeap;
                maxHeap.push(val);
                while(!minHeap.empty() && minHeap.top().first == absdiff){
                    int currVal = minHeap.top().second;
                    minHeap.pop();
                    maxHeap.push(currVal);
                }
                while(i<k && !maxHeap.empty()){
                    ans.push_back(maxHeap.top());
                    maxHeap.pop();
                    i++;
                }
            }
            else {
                ans.push_back(val);
                i++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends