//P5788 【模板】单调栈
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    stack<int> s;
    vector<int> g(n+1);
    for(int i=n;i>=1;i--){
        while(!s.empty()&&a[s.top()]<=a[i]){
            s.pop();
        }
        if(s.empty()) g[i]=0;
        else{
            g[i] = s.top();
        }
        s.push(i);
    }
    for(int i=1;i<=n;i++)
        cout<<g[i]<<' ';
}