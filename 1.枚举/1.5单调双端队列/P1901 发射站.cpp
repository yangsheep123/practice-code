// P1901 发射站

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i].first >> a[i].second;
    stack<int> s1,s2;
    vector<int> g(n);
    for(int i=n-1;i>=0;i--){
        while(!s1.empty()&&a[s1.top()].first<=a[i].first)
            s1.pop();
        if(!s1.empty()) 
            g[s1.top()] += a[i].second;
        s1.push(i);
    }

    for(int i=0;i<n;i++){
        while(!s2.empty()&&a[s2.top()].first<=a[i].first){
            s2.pop();
        }
        if(!s2.empty()) 
            g[s2.top()] += a[i].second;
        s2.push(i);
    }
    sort(g.begin(),g.end());
    cout<<g[n-1]<<endl;
}
