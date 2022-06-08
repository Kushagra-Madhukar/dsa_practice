// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>& grid, int i, int j, int vis[][501]) {
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || i>=n|| j<0 || j>=m) return;
        if(grid[i][j] == '0') return;
        if(!vis[i][j]){
            vis[i][j] = 1;
            dfs(grid, i+1, j, vis);
            dfs(grid, i+1, j+1, vis);
            dfs(grid, i+1, j-1, vis);
            dfs(grid, i, j+1, vis);
            dfs(grid, i, j-1, vis);
            dfs(grid, i-1, j, vis);
            dfs(grid, i-1, j+1, vis);
            dfs(grid, i-1, j-1, vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        int vis[501][501] = {0};
        // vector<vector<int>> vis
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(grid, i, j, vis);
                    count++;
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends