#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> a(n);
        int maxD = -1,total = 0;
        for(int i=0;i<n;i++) {
            cin>>a[i].first;
            maxD = max(maxD,a[i].first);
        }
        for(int i=0;i<n;i++) {
            cin>>a[i].second;
            total += a[i].second;
        }
        priority_queue<int> pq;
        vector<vector<int>> score(maxD+1);
        for(int i=0;i<n;i++){
            int s = a[i].first;
            int v = a[i].second;
            score[s].push_back(v);
        }
        for(int i = maxD;i>=1;i--){
            for(int j=0;j<score[i].size();j++){
                pq.push(score[i][j]);
            }
            if(!pq.empty()){
                total -= pq.top();
                pq.pop();
            }
        }
        cout<<total<<endl;
    }
}