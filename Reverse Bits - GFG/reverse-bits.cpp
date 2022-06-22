// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    unsigned int reverseBits(unsigned int n)
    {
        unsigned int num = n;
        stack<unsigned int> st;
        while(num){
            unsigned int digit = num%2;
            num = num/2;
            st.push(digit);
        }
        unsigned int pow = 1;
        unsigned int ans = 0;
        while(!st.empty()){
            ans += st.top()*pow;
            st.pop();
            pow *= 2;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout<< ob.reverseBits(N) <<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends