// https://www.lanqiao.cn/problems/2191/learning/

#include<bits/stdc++.h>
using namespace std;

int main(){
    // 枚举多少套牌，牌的套数越少，肯定越容易成功
    // 因此满足两级性[T,T,T,F,F,F...]
    // 要找到最后一个T所对应的牌数
    // 而二分法可以找到第一个符合条件的数，所以要取反
    cin.tie(0)->sync_with_stdio(false);
    int n;
    long long m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(n);
    for(auto& x:a) cin>>x;
    for(auto& x:b) cin>>x;
    int low = 0,high = 2*n;
    auto check = [&](int x){
        // cnt表示为了凑成x副牌，需要用到多少空白牌
        long long cnt = 0;
        for(int i=0;i<n;i++){
            if(a[i]+b[i]<x) return true;// 取反
            cnt += max(0,x-a[i]);
        }
        return (cnt>m);
    };
    while(low<=high){
        int mid = low + (high-low)/2;
        if(check(mid))
            high = mid - 1;
        else low = mid+1;
    }
    cout<<low-1<<endl;
}
