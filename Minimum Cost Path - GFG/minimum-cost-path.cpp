// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    // void DFS(int cost, int i, int j, int &minCost, vector<int> &vis, int n, int m, vector<vector<int>>& grid) {
    //     if(i == n-1 && j == m-1) {
    //         minCost = min(minCost, cost + grid[i][j]);
    //         return;
    //     }
    //     int dx[] = {1, 0, -1, 0};
    //     int dy[] = {0, 1, 0, -1};
    //     for(int k=0;k<4;k++){
    //         int newX = i + dx[k];
    //         int newY = j + dy[k];
    //         if(newX >=0 && newX < n && newY >= 0 && newY < m)
    //     }
    // }
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int minCost = INT_MAX;
        int n = grid.size();
        int m = grid[0].size();
        // vector<int> dist(n*m, INT_MAX);
        int dist[n][m];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                dist[i][j] = INT_MAX;
            }
        }
        dist[0][0] = grid[0][0];
        // dist[0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        // pq.push({dist[0], 0});
        pq.push({dist[0][0], {0, 0}});
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, 1, -1, 0};
        // int ds[] = {m, -m, 1, -1};
        while(!pq.empty()){
            pair<int, int> coords = pq.top().second;
            int x = coords.first;
            int y = coords.second;
            int cost = pq.top().first;
            // int node = p.second;
            pq.pop();
            if(x == n-1 && y == m-1) break;
            for(int i=0; i<4;i++){
                int u = x + dx[i];
                int v = y + dy[i];
                if(u>=0 && v>=0 && u<n && v<m && dist[u][v] > dist[x][y] + grid[u][v]){
                    dist[u][v] = dist[x][y] + grid[u][v];
                    pq.push({dist[u][v], {u, v}});
                }
            }
        }
        return dist[n-1][m-1];
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends