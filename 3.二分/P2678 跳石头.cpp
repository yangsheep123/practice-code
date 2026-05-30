// https://www.luogu.com.cn/problem/P2678

#include<bits/stdc++.h>
using namespace std;


int main(){
    int l,n,m;
    cin>>l>>n>>m;
    vector<int> stones(n);
    for(auto& x:stones) cin>>x;
    stones.push_back(l);
    auto check = [&](int dis){
        int pos = 0;
        int cnt = 0;// 需要移开的石头数量
        for(auto& stone:stones){
            if(stone - pos<dis)
                cnt++;
            else{
                pos = stone;
            }
        }
        return cnt>m;
    };
    int low = 1,high = l;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(check(mid))
            high = mid - 1;
        else low = mid+1;
    }
    cout<<low-1<<endl;
}