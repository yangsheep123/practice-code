#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// 转换成2x个小青蛙一起跳
//1 0 1 0
//第一步：[0,y]的和>=2x
//第二步:[1,y+1]的和>=2x
//即[0,n]所有的区间都满足和>=2x
//[l,l+y]的和>=2x
//条件：[l,r]的和>=2x
//求不满足条件的最大值r,答案就是直接+1


int main(){
    int n;
    ll x;
    cin>>n>>x;
    vector<int> h(n-1);
    for(int i=1;i<=n-1;i++)
        cin>>h[i];
    int l=1,r=1;
    ll sum = 0;
    ll ans = -1;
    while(l<=r){
        while(sum<2*x&&r<=n-1){
            sum+=h[r++];
        }
        if(sum>=2*x){
            //[l,r-2]这段区间坏了，ans维护的是这段区间有几个坏石头
            ans = max(1ll*(r-2-l+1),ans);
        }else{
            ans = max(ans,1ll*(r-l));
        }
        sum -= h[l++];
    }
    // 跳越能力就等于坏石头个数+1
    cout<<ans+1<<endl;
}