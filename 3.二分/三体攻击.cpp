// https://www.lanqiao.cn/problems/180/learning/
#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int a,b,c,m;
    cin>>a>>b>>c>>m;
    // 定义三维矩阵
    vector<vector<vector<int>>> hp(a+2,vector<vector<int>> (b+2,vector<int>(c+2)));
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
            for(int k=1;k<=c;k++)
                cin>>hp[i][j][k];
    vector<tuple<int,int,int,int,int,int,int>> attacks(m);
    for(auto& [a,b,c,d,e,f,g]:attacks) cin>>a>>b>>c>>d>>e>>f>>g;
    auto check = [&](int x){// x表示轮数
        vector<vector<vector<long long>>> diff(a+2,vector<vector<long long>> (b+2,vector<long long>(c+2)));
        // 前x轮攻击
        for(int i=0;i<x;i++){
            auto [la,ra,lb,rb,lc,rc,ht] = attacks[i];
            diff[la][lb][lc] += ht;
            diff[la][lb][rc+1] -= ht;
            diff[la][rb+1][lc] -= ht;
            diff[ra+1][lb][lc] -= ht;
            diff[la][rb+1][rc+1] += ht;
            diff[ra+1][rb+1][lc] += ht;
            diff[ra+1][lb][rc+1] += ht;
            diff[ra+1][rb+1][rc+1] -= ht;
        }
        // 计算前缀和
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                for(int k=1;k<=c;k++){
                    diff[i][j][k] += diff[i][j][k-1]
                                  +  diff[i][j-1][k]
                                  +  diff[i-1][j][k]
                                  -  diff[i][j-1][k-1]
                                  -  diff[i-1][j][k-1]
                                  -  diff[i-1][j-1][k]
                                  +  diff[i-1][j-1][k-1];
                    if(diff[i][j][k]>hp[i][j][k]) return true;
                }
            }
        }
        return false;
    };
    int low = 1,high = m;
    while(low<=high){
        int mid = (low+high)/2;
        if(check(mid))
            high = mid-1;
        else low = mid+1;
    }
    cout<<low<<endl;
}