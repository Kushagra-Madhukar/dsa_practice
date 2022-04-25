// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
bool compare(struct val p1, struct val p2) {
   return p1.second < p2.second;
}
int maxChainLen(struct val p[],int n)
{
    int dp[n+1];
    dp[0] = 1;
    int maxChain = 1;
    sort(p, p+n, compare);
    for(int i=1;i<n;i++){
        dp[i] = 1;
        for(int j=i-1;j>=0;j--){
            if(p[j].second < p[i].first) dp[i] = max(dp[i], dp[j] + 1);
            maxChain = max(maxChain, dp[i]);
        }
    }
    return maxChain;
}