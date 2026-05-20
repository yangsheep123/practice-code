#include<bits/stdc++.h>
using namespace std;

// (R-L+1)*min(AL,A(L+1),...,AR)
// 固定min(AL,A(L+1),...,AR)
// 找AI，使得AI最小，AY<AI,AX<AI，则区间是[Y+1,X-1]

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    stack<int> s;
    vector<int> pre_g(n);
    vector<int> next_g(n);
    for(int i=0;i<n;i++){
        while(!s.empty()&&a[s.top()]>=a[i])
            s.pop();
        if(s.empty()) pre_g[i] = -1;
        if(!s.empty()) pre_g[i] = s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for(int i=n-1;i>=0;i--){
        while(!s.empty()&&a[s.top()]>=a[i])
            s.pop();
        if(s.empty()) next_g[i] = n;
        if(!s.empty()) next_g[i] = s.top();
        s.push(i);
    }
    long long ans = -1;
    for(int i=0;i<n;i++){
        int l = pre_g[i],r = next_g[i];
        ans = max(1ll*(r-l-1)*a[i],ans);
    }
    cout<<ans<<endl;

}