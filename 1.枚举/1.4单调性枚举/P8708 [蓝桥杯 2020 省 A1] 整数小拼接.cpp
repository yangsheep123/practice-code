// P8708 [蓝桥杯 2020 省 A1] 整数小拼接

//整数小于等于 K
//找出不符合条件的最小r
//当l变大的时候，要符合条件，则r必须变小，是单调递减关系
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    ll k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    ll ans=0;
    vector<ll> exp(n,1);
    for(int i=0;i<n;i++){
        for(int x=a[i];x;x/=10,exp[i]*=10);
    }
    for(int l=0,r=n-1;l<n&&r>=0;){//这里没有严格的r必须比l大的约束
       if(1ll*(a[l]*exp[r]+a[r])<=k){
            //[0,r]
            ans += r+1;
            if(l<=r) ans--;
            l++;
       }else{
        r--;
       }
    }
    cout<<ans;
}
