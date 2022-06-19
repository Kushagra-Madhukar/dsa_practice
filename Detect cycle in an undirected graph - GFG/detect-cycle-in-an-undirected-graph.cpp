// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool cycleCheckBFS(int node, int parent, vector<int> adj[], vector<int> &vis) {
        vis[node] = 1;
        queue<pair<int, int>> q;
        q.push({node, -1});
        while(!q.empty()){
            int curr = q.front().first;
            int par = q.front().second;
            q.pop();
            for(auto neighbour: adj[curr]) {
                if(!vis[neighbour]){
                    vis[neighbour] = 1;
                    q.push({neighbour, curr});
                }
                else if(vis[neighbour] && par != neighbour){
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V+1, 0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(cycleCheckBFS(i, -1, adj, vis)) return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends