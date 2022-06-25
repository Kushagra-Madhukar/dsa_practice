// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// class comparator {
    
// }
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>> maxHeap;
        for(auto num: nums){
            freq[num]++;
        }
        for(auto i: freq){
            maxHeap.push({i.second, i.first});
        }
        for(int i=0;i<k;i++){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends