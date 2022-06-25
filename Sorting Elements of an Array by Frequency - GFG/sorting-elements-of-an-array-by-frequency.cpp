#include <bits/stdc++.h>
using namespace std;

class comparator {
    public:
    bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
        if(p1.first == p2.first) return p1.second>p2.second;
        else return p1.first<p2.first;
    }
};
int main() {
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
    	unordered_map<int, int> freq;
    	priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> maxHeap;
    	for(int i=0;i<N;i++){
    	    freq[A[i]]++;
    	}
    	for(auto it: freq){
    	    maxHeap.push({it.second, it.first});
    	}
    	while(!maxHeap.empty()){
    	    int count = maxHeap.top().first;
    	    int val = maxHeap.top().second;
    	    for(int i=0;i<count;i++){
    	        cout<<val<<" ";
    	    }
    	    maxHeap.pop();
    	}
    	cout<<endl;
    }
	return 0;
}