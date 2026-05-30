// https://www.lanqiao.cn/problems/17098/learning/
#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n,m;
    long long k;
    cin>>n>>m>>k;
    vector<int> a(n);
    vector<int> b(m);
    for(auto& x:a) cin>>x;
    for(auto& x:b) cin>>x;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    auto check = [&](int x){
        long long cnt = 0;// 表示比mid小的个数
        for(int i=0;i<n;i++){
            // upper_bound：找出数组中第一个大于target的数的下标
            // upper_bound复杂度：logn
            cnt += upper_bound(b.begin(),b.end(),x - a[i]) - b.begin();
        }
        return cnt >= k;
    };
    int low = 2,high = a[n-1]+b[m-1];
    while(low<=high){
        int mid = low + (high-low)/2;
        if(check(mid))
            high = mid -1;
        else low = mid+1;
    }
    cout<<low<<endl;
}