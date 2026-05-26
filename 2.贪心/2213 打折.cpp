// https://www.lanqiao.cn/problems/2213/learning

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    // time,zk,type,base_price
// 正确顺序：先删旧折扣 → 再加新折扣
// 先把旧折扣价删掉
// 再把新折扣价加上
// 取当前最低价 → 完全正确
// 错误顺序：先加新折扣 → 再删旧折扣
// 先把新折扣价加上
// 再把旧折扣价删掉
// 中间一瞬间，两个折扣同时存在，价格算错了！
    vector<tuple<int,int,int,int>> actions;
    // [type,price]
    vector<multiset<int>> prices(n+1);
    while(m--){
        int start,end,zk,cnt;
        cin>>start>>end>>zk>>cnt;
        while(cnt--){
            int type,base_price;
            cin>>type>>base_price;
            // 折扣开始
            actions.emplace_back(start,zk,type,base_price);
            // 折扣结束
            actions.emplace_back(end+1,-zk,type,base_price);
            // prices[type]:是一个multiset,multiset插入元素用insert
            prices[type].insert(base_price);
        }
    }
    // 将actions按照时间排序
    sort(actions.begin(),actions.end());
    long long total = 0;
    for(int i=1;i<=n;i++){
        total += *prices[i].begin();
    }
    // cout<<"yes";
    long long ans = total;
    for(auto& [time,zk,type,base_price]:actions){
        int current_price = *prices[type].begin();
        if(zk>0){
            int price = (1ll*base_price*zk)/100;
            prices[type].insert(price);
        }else{
            // multiset删除元素要用find()
            prices[type].erase(prices[type].find((1ll*base_price*(-zk))/100));
        }
        int price = *prices[type].begin();
        int delta = price - current_price;
        total += delta;
        ans = min(ans,total);
    }
    cout<<ans;
}