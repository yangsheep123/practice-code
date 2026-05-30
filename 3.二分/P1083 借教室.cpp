// https://www.luogu.com.cn/problem/P1083
#include<bits/stdc++.h>
using namespace std;

// 累加day天之前的所有订单
// day越小，越容易满足。因此满足两级性:[T,T,T,F,F,F..]
// 答案是找到第一个F

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<int> rooms(n+5);
    for(int i=1;i<=n;i++) cin>>rooms[i];
    vector<tuple<int,int,int>> orders(m);
    for(auto& [d,s,t]:orders)
        cin>>d>>s>>t;
    auto check = [&](int day){
        vector<long long> diff(n+5);
        for(int i=0;i<day;i++){
            auto [num,start,end] = orders[i];
            diff[start] += num;
            diff[end+1] -= num;
        }
        for(int i=1;i<=n;i++){
            diff[i] += diff[i-1];
            if(diff[i]>rooms[i]) return true;
        }
        return false;
    };
    int low = 1,high = m;
    while(low<=high){
        int mid = (low+high)/2;
        if(check(mid))
            high = mid - 1;
        else low = mid+1;
    }
    if(low==m+1) cout<<0;
    else{
        cout<<-1<<endl<<low<<endl;
    }
}