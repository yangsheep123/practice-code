// https://www.lanqiao.cn/problems/2129/learning/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// 10 5 0
// 9 7 5 3 1 0
// 8 7 6 5 4 3 2 1 0
// 朴素的思路是选取用贪心选取前m个大的升级，但是m最大是2*10^9，会超时
// 那么换个思路：存在一个x，使得大于等于x的升级是否小于等于m？
// x越小，m越大：符合两级性[F,F,F,F,T,T,T..]找到第一个T

int main(){
    int n;
    ll m;
    cin>>n>>m;
    vector<pair<int,int>> skills(n);
    for(auto& [a,b]:skills) cin>>a>>b;
    auto check = [&](ll x){
        ll cnt = 0;
        for(auto& [a,b]:skills){
            if(a<x) continue;
            cnt += (a-x)/b+1;// 求项数
        }
        return cnt <= m;
    };
    int low = 1,high = 1e6;
    while(low<=high){
        int mid = (low+high)/2;
        if(check(mid))
            high = mid -1;
        else low = mid+1;
    }
    // 得到low是得到的第一个符合条件的x
    ll sum = 0;
    ll total_cnt = 0;
    for(auto& [a,b]:skills){
        if(a<low)continue;
        ll c = (a-low)/b+1;
        total_cnt += c;
        sum += ((a+(a-b*(c-1)))*c)/2;
    }
    if(total_cnt<m) sum += (m-total_cnt)*(low-1);
    cout<<sum<<endl;
}