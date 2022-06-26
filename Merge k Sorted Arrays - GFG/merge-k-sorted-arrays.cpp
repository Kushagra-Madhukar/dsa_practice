// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        int activePointers = K;
        vector<int> ans;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        for(int i=0;i<activePointers;i++){
            minHeap.push({arr[i][0], {i, 0}});
        }
        while(!minHeap.empty()){
            // if(minHeap.size()>=activePointers){
                pair<int, pair<int, int>> current = minHeap.top();
                minHeap.pop();
                ans.push_back(current.first);
                int x = current.second.first;
                int y = current.second.second;
                // if(y>=K-1) activePointers--;
                // else minHeap.push({arr[x][y + 1], {x, y+1}});
                if(y+1<K) minHeap.push({arr[x][y + 1], {x, y+1}});
            // }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends