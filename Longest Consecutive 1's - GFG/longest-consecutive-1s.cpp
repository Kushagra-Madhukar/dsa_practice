// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

/*  Function to calculate the longest consecutive ones
*   N: given input to calculate the longest consecutive ones
*/
class Solution
{
    public:
    int maxConsecutiveOnes(int N)
    {
        //simpler but more time complexity solution
      /* int maxCount = 0, count = 0;
      int num = N;
      while(num){
          if(num&1 == 1) {
              count++;
              maxCount = max(maxCount, count);
          }
          else {
              count = 0;
          }
          num=num>>1;
      }
      return maxCount; */
      //optimum soln
      int maxCount = 0;
      while(N){
          N&=(N<<1);
          maxCount++;
      }
      return maxCount;
    }
};


// { Driver Code Starts.

// Driver Code
int main() {
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n;
		cin>>n;//input n
		Solution obj;
		//calling maxConsecutiveOnes() function
		cout<<obj.maxConsecutiveOnes(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends