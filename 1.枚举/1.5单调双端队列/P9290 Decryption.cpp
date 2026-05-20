// P9290 [ROI 2018] Decryption

#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    stack<int> s;
    vector<int> next_l(n);
    vector<int> next_g(n);
    for(int i=n-1;i>=0;i--){
        while(!s.empty()&&a[s.top()]>=a[i])
            s.pop();
        if(s.empty()) next_l[i] = n;
        else next_l[i] = s.top();
        s.push(i);
    }
//    cout<<"next_l:"<<' ';
//    for(int i=0;i<n;i++){
//        cout<<next_l[i]<<' ';
//    }
    while(!s.empty()) s.pop();
    for(int i=n-1;i>=0;i--){
        while(!s.empty()&&a[s.top()]<=a[i])
            s.pop();
        if(s.empty()) next_g[i] = n;
        else next_g[i] = s.top();
        s.push(i);
    }
//    cout<<"next_g:"<<' ';
//    for(int i=0;i<n;i++){
//        cout<<next_g[i]<<' ';
//    }
    int ans = 0;
    for(int l=0,r=0;l<n;){
        while(next_g[r]<next_l[l]){
            r = next_g[r];
        }
        ans++;
        l = r+1;
        r = r+1;
    }
    cout<<ans;
}
