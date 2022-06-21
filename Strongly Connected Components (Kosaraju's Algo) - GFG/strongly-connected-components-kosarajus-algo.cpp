// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	void topoSort(int node, vector<int> &vis, vector<int> adj[], stack<int> &topo){
	    vis[node] = 1;
	    for(auto nbr: adj[node]){
	        if(!vis[nbr]){
	            vis[nbr] = 1;
	            topoSort(nbr, vis, adj, topo);
	        }
	    }
	    topo.push(node);
	}
// 	int helper(int N, int i, vector<int> &vis, vector<int> &adj[], int &count, vector<int> &cycleVis) {
// 	    vis[i] = 1;
// 	    cycleVis[i] = 1;
// 	    for(auto it: adj[i]) {
// 	        if(!vis[it]) helper(V, it, vis, adj, count, cycleVis);
// 	        else if(cycleVis[it]) count++;
// 	    }
// 	}
	void connectedComponent(int node, vector<int> &vis, vector<int> adj[]){
	    vis[node] = 1;
	    for(auto nbr: adj[node]){
	        if(!vis[nbr]){
	            vis[nbr] = 1;
	            connectedComponent(nbr, vis, adj);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> topo;
        vector<int> vis(V, 0);
        for(int i=0;i<V;i++){
            if(!vis[i]) {
                topoSort(i, vis, adj, topo);
            }
        }
        vector<int> adjTranspose[V];
        for(int i=0;i<V;i++){
            vis[i] = 0;
            for(auto child: adj[i]){
                adjTranspose[child].push_back(i);
            }
        }
        int ans = 0;
        while(!topo.empty()){
            int node = topo.top();
            topo.pop();
            if(!vis[node]){
                ans++;
                connectedComponent(node, vis, adjTranspose);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends