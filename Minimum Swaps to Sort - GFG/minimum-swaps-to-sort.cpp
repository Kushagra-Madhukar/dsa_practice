// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<pair<int, int>> numsSorted;
	    int n = nums.size();
	    for(int i=0;i<n;i++){
	        numsSorted.push_back({nums[i], i});
	    }
	    vector<int> vis(n, 0);
	    sort(numsSorted.begin(), numsSorted.end());
	    int swaps = 0;
	    for(int i=0;i<n;i++){
	        if(!vis[i] && numsSorted[i].second != i) {
	            int curr = 0;
                int j = i;
	            while(!vis[j]){
	                vis[j] = true;
	                curr++;
	                j = numsSorted[j].second;
	            }
	            swaps += curr-1;
	        }
	    }
	    return swaps;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends