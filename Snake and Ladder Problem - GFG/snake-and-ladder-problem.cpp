// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        unordered_map<int, int> snakeLadderMap;
        for(int i=0;i<2*N;i+=2){
            snakeLadderMap[arr[i]] = arr[i+1]; 
        }
        queue<pair<int, int>> q;
        q.push({0, 1});
        vector<int> vis(31, 0);
        vis[0] = vis[1] = 1;
        while(!q.empty()){
            pair<int, int> ele = q.front();
            int throws = ele.first;
            int pos = ele.second;
            q.pop();
            if(pos==30) return throws;
            for(int i=1; i<=6;i++){
                int newPos = pos + i;
                if(newPos==30) return throws + 1;
                if(newPos<30 && newPos>=0 && !vis[newPos]){
                    vis[newPos] = 1;
                    if(snakeLadderMap.find(newPos) == snakeLadderMap.end()) q.push({throws+1, newPos});
                    else q.push({throws+1, snakeLadderMap[newPos]});
                }
            }
        }
        return -1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends