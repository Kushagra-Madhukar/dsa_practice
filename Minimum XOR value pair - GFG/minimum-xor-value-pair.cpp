// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Node {
    public:
    Node* left = NULL; //0
    Node* right = NULL; //1
};

class Solution{
    public:
    Node* root;
    Solution(){
        root = new Node();
    }
    private:
    void insertNode(int data){
        Node* ptr = root;
        for(int i=31;i>=0;i--){
            int activeBit = (data>>i)&1;
            if(activeBit){ //1
                if(!ptr->right) ptr->right = new Node();
                ptr = ptr->right;
            } else { //0
                if(!ptr->left) ptr->left = new Node();
                ptr = ptr->left;
            }
        }
    }
    private:
    int getMinXor(int data){
        Node* ptr = root;
        int minXor = 0;
        for(int i=31;i>=0;i--){
            int activeBit = (data>>i)&1;
            if(activeBit){
                if(ptr->right) ptr = ptr->right;
                else {
                    minXor |= (1<<i);
                    ptr = ptr->left;
                }
            } else {
                if(ptr->left) ptr = ptr->left;
                else {
                    minXor |= (1<<i);
                    ptr = ptr->right;
                }
            }
        }
        return minXor;
    }
    
public:
    int minxorpair(int N, int arr[]){    
        int min_xor = INT_MAX;
        insertNode(arr[0]);
        for(int i=1;i<N;i++){
            min_xor = min(min_xor, getMinXor(arr[i]));
            insertNode(arr[i]);
        }
        return min_xor;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.minxorpair(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends