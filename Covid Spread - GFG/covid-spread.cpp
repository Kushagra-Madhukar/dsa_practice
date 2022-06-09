// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        int n = hospital.size();
        int m = hospital[0].size();
        int vis[n+1][m+1] = {0};
        int maxTime = 0;
        int onesCount = 0;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        queue<pair<int, pair<int, int>>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(hospital[i][j] == 1) {
                    onesCount++;
                }
                if(hospital[i][j] == 2) {
                    q.push({0, {i, j}});
                }
            }
        }
        while(!q.empty()){
            pair<int, pair<int, int>> hs = q.front();
            int currtime = hs.first;
            maxTime = max(maxTime, currtime);
            pair<int, int> coords = hs.second;
            int x = coords.first;
            int y = coords.second;
            int nodeVal = hospital[x][y];
            vis[x][y] = 1;
            q.pop();
            for(int i=0;i<4;i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX>=0 && newY>=0 && newX<n && newY<m && hospital[newX][newY] == 1) {
                    q.push({currtime + 1, {newX, newY}});
                    hospital[newX][newY] = 2;
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(hospital[i][j] == 1) {
                    return -1;
                }
            }
        }
        return maxTime;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends