// P7404
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// 3 2 2 3 1
// 3 -1 0 1 -2
// x [pos] [neg] 

int main(){
    int n;
    cin>>n;
    vector<int> a(n+5);
    vector<int> d(n+5);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    // cout<<"d:";
    for(int i=n;i>0;i--){
        d[i] = a[i]-a[i-1];
        // cout<<d[i]<<' ';P
    }
    // cout<<endl;
    // leftSum：变成递增序列需要多少操作，前缀和
    // rightSum：变成递减序列需要多少操作，后缀和
    vector<ll> leftSum(n+5),rightSum(n+5);
    for(int i=2;i<=n;i++){
        if(d[i]<1) leftSum[i] = leftSum[i-1] + (1-d[i]);
        else leftSum[i] = leftSum[i-1];
    }
    // cout<<"ls:";
    // for(int i=1;i<=n;i++)
    //     cout<<leftSum[i]<<' ';
    // cout<<endl;
    for(int i=n;i>0;i--){
        if(d[i]>-1) rightSum[i] = rightSum[i+1] + (-(-1-d[i]));
        else rightSum[i] = rightSum[i+1];
    }
    // cout<<"rs:";
    // for(int i=1;i<=n;i++)
    //     cout<<rightSum[i]<<' ';
    // cout<<endl;
    ll res = LLONG_MAX;
    //枚举k
    for(int k=1;k<=n;k++){
        res = min(res,max(leftSum[k],rightSum[k+1]));
    }
    cout<<res;
}