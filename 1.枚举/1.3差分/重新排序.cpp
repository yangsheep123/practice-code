#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
typedef long long ll;
vector<int> a(N);
vector<ll> pre(N); //前缀和
vector<ll> diff(N); //差分数组

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>m;
    for(int i=0;i<n;i++){
        if(i==0) pre[i] = a[i];
        else pre[i] = pre[i-1] + a[i];
    }
    
    ll total = 0;
    while(m--){
        int l,r;
        cin>>l>>r;
        if(l==1) total += pre[r-1];
        else total += pre[r-1] - pre[l-2];
        // cout<<"total="<<total<<' ';
        diff[l-1] ++;
        diff[r] --;
    }
    for(int i=0;i<n;i++){
        if(i==0) continue;
        diff[i] = diff[i-1] + diff[i];
    }
    // 从大到小排序
    sort(diff.begin(),diff.end(),greater<long long>());
    sort(a.begin(),a.end(),greater<int>());
    long long ans = 0;
    for(int i = 0;i < n;i++){
        ans += a[i] * diff[i];
    }
    cout << ans - total << endl;
    return 0;
}