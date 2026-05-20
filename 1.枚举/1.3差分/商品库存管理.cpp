#include<bits/stdc++.h>
using namespace std;
const int N = 3*1e5+10;
// vector<vector<int>> diff(N,vector<int>(N,0));
vector<long long> diff(N);
vector<long long> cnt1(N); //1的前缀和


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n,m;
    long long ans=0;
    cin>>n>>m;
    int l[m+1],r[m+1];
    long long cnt0 =0;
    for(int i=1;i<=m;i++){
        cin>>l[i]>>r[i];
        diff[l[i]]++;
        diff[r[i]+1]--;
    }
    for(int i=1;i<=n;i++)
        diff[i] += diff[i-1];
    // 再统计第i次操作中，l[i]-r[i]区间内1的个数和总区间中0的个数
    // 如何统计1的个数？也就是计算diff数组中1的前缀和！遇到1就加1
    for(int i = 1;i<=n;i++){
        cnt1[i] = cnt1[i-1];
        if(diff[i] == 1) cnt1[i]++;
        else if(diff[i] ==0 ) cnt0++;
    }
    for(int i=1;i<=m;i++){
        // cnt1[r[i]] - cnt1[l[i]-1]表示[l,r]区间1的个数
        long long ans = cnt0 + cnt1[r[i]] - cnt1[l[i]-1];
        cout<<ans<<endl;
    }

}