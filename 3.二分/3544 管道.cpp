// https://www.lanqiao.cn/problems/3544/learning/
#include<bits/stdc++.h>
using namespace std;
// 对于每个阀门，计算出T时间他能覆盖的区间
// 那么就是求解，所有阀门的区间能否覆盖整个区间
// 贪心+二分
int main(){
    int n,len;
    cin>>n>>len;
    vector<pair<int,int>> pipes(n);
    for(auto& [l,s]:pipes) cin>>l>>s;
    sort(pipes.begin(),pipes.end(),[&](pair<int,int>& a,pair<int,int>& b){
        return a.first + a.second < b.first+ b.second;
    });
    auto check = [&](int time){
        vector<pair<int,int>> segs(n);
        for(int i=0;i<n;i++){
            auto [l,s] = pipes[i];
            segs[i].first = l-(time-s);
            segs[i].second = l+(time-s);
        }
        int max_right = 0;
        for(int i=0;i<n;i++){
            auto [l,r] = segs[i];
            if(l<=max_right+1){
                max_right = max(max_right,r);
            }
        }
        return max_right >= len;
    };
    int low = 1,high = INT_MAX;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(check(mid)) high = mid - 1;
        else low = mid+1;
    }
    cout<<low<<endl;
}