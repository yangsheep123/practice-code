// https://www.luogu.com.cn/problem/P1314
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// w变大，y变小，因此可以找到第一个<=s的w值，
// 然后再计算w-1对应的y，再比较

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int m,n;
    ll s;
    cin>>n>>m>>s;
    vector<pair<int,int>> stones(n);
    vector<pair<int,int>> segs(m);
    for(auto& [w,v]:stones) cin>>w>>v;
    for(auto& [l,r]:segs) cin>>l>>r;
    auto cal = [&](int W){
        vector<int> weight(n+5);
        vector<ll> val(n+5);
        for(int i=1;i<=n;i++){
            auto [w,v] = stones[i-1];
            int t = 0;
            if(w>=W) t = 1;
            weight[i] = weight[i-1] + t;
            val[i] = val[i-1] + t * v;
        }
        ll total = 0;
        for(int i=0;i<m;i++){
            auto [l,r] = segs[i];
            total += (weight[r] - weight[l-1]) * (val[r] - val[l-1]);
        }
        return total;
    };
    auto check = [&](int W){
        return cal(W) <= s;
    };
    int low = 0,high = 1e6;
    while(low<=high){
        int mid = (low+high)/2;
        if(check(mid)) high = mid - 1;
        else low = mid+1;
    }
    ll y1 = cal(low);
    ll y2 = cal(low-1);
    ll cnt1 = abs(s-y1);
    ll cnt2 = abs(s-y2);
    cout<<(cnt1<cnt2 ? cnt1:cnt2) <<endl;
}