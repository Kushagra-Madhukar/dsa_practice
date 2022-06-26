// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int>> l;
    double median;
    void insertHeap(int &x)
    {
        // if(s.size() == l.size()) s.push(x);
        // else l.push(x);
        // balanceHeaps();
        if(s.size() == 0 || s.top()>x){
            s.push(x);
        }
        else{
            l.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        // if(s.size() > 0 && l.size() > 0 && s.top()>l.top()){
        //     double x = s.top();
        //     double y = l.top();
        //     s.pop(); 
        //     l.pop();
        //     s.push(y);
        //     l.push(x);
        // }
        if(s.size()>l.size()+1){
            l.push(s.top());
            s.pop();
        }
        else if(l.size()>s.size()){
            s.push(l.top());
            l.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        // if(s.size() == l.size()) return median = (s.top() + l.top())/2;
        // else return median = s.top();
        double med;
         if(l.size()==s.size()){
             med=(s.top()+l.top())/2.0;
         }
         else{
             med=s.top();
         }
         return med;
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends