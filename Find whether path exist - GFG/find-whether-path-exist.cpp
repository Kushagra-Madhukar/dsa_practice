// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<int> vis(n*m, 0);
        for(int i = 0;i<n;i++){
            for(int j = 0; j<m;j++){
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i*m + j] = 1;
                    break;
                }
            }
        }
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        while(!q.empty()){
            pair<int, int> data = q.front();
            int x = data.first;
            int y = data.second;
            q.pop();
            if(grid[x][y] == 2) return true;
            for(int i =0;i<4;i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX>=0 && newX<n && newY >=0 && newY<m && grid[newX][newY] != 0 && !vis[newX*m + newY]) {
                    if(grid[newX][newY] == 2) return true;
                    q.push({newX, newY});
                    vis[newX*m + newY] = 1;
                }
            }
        }
        return false;
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
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends